#include "map.h"

#include <QDebug>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Map::~Map()
{
    // Очистка карты
    clearMap();
}

// Очистка карты
void Map::clearMap()
{
    m_irons.clear();
    m_bricks.clear();
    m_water.clear();
    m_grass.clear();
    m_players.clear();
}

void Map::readMap(QString filename)
{
    QFile jsonFile(filename);
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Couldn't open file";
        return;
    }

    QByteArray saveData = jsonFile.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(saveData));
    if (doc.isObject()) {
        QJsonObject json = doc.object();
        QJsonArray brickArray   = json["Brick"].toArray();
        QJsonArray ironArray    = json["Iron"].toArray();
        QJsonArray grassArray   = json["Grass"].toArray();
        QJsonArray waterArray   = json["Water"].toArray();
        QJsonArray playerArray  = json["Player"].toArray();

        jsonUnmovableObjectToRead(brickArray, m_bricks, UnmovableObjectType::Brick);
        jsonUnmovableObjectToRead(ironArray, m_irons, UnmovableObjectType::Iron);
        jsonUnmovableObjectToRead(grassArray, m_grass, UnmovableObjectType::Grass);
        jsonUnmovableObjectToRead(waterArray, m_water, UnmovableObjectType::Water);
        jsonMovableObjectToRead(playerArray, m_players);
    }
}

void Map::jsonUnmovableObjectToRead(QJsonArray jsonArray, QVector<UnmovableObject *> &object, UnmovableObjectType type)
{
    foreach(const QJsonValue & value, jsonArray) {
        if (value.isObject()) {
            QJsonObject obj = value.toObject();
            float x = obj["x"].toDouble();
            float y = obj["y"].toDouble();
            float width = obj["width"].toDouble();
            float height = obj["height"].toDouble();

            UnmovableObject *unmovableObject = new UnmovableObject(type);
            unmovableObject->setBounds(QRectF(x, y, width, height));
            object.push_back(unmovableObject);
        }
    }
}

void Map::jsonMovableObjectToRead(QJsonArray jsonArray, QVector<Tank *> &object)
{
    foreach(const QJsonValue & value, jsonArray) {
        if (value.isObject()) {
            QJsonObject obj = value.toObject();
            float x = obj["x"].toDouble();
            float y = obj["y"].toDouble();
            float width = obj["width"].toDouble();
            float height = obj["height"].toDouble();
            float speed = obj["speed"].toDouble();

            Tank *tank = new Tank();
            tank->setBounds(QRectF(x, y, width, height));
            tank->setSpeed(speed);
            object.push_back(tank);
        }
    }
}

QVector<UnmovableObject *>* Map::bricks()
{
    return &m_bricks;
}

QVector<UnmovableObject *> *Map::irons()
{
    return &m_irons;
}

QVector<UnmovableObject *> *Map::grass()
{
    return &m_grass;
}

QVector<UnmovableObject *> *Map::water()
{
    return &m_water;
}

QVector<Tank *> *Map::players()
{
    return &m_players;
}

// [TODO]
// [DONE] 1. Изменить снаряды. Чтобы вычиталось не 1, а тот урон, который у снаряда.
// 2. Распараллелить for each, чтобы ускорить работу метода.
bool Map::hasCollision(MovableObject object, float dt)
{
    object.move(dt);
    bool isCollision = false;
    for(auto brick : m_bricks) {
        if (object.bounds().intersects(brick->bounds())) {
            if(object.movableType() == MovableObjectType::BULLET) {
                Bullet bullet = (Bullet&) object;
                brick->setHp(brick->hp() - bullet.damage());
            }
            isCollision = true;
        }
    }

    for(auto iron : m_irons) {
        if (object.bounds().intersects(iron->bounds())) {
            isCollision = true;
        }
    }

    for(auto water : m_water) {
        if (object.bounds().intersects(water->bounds())) {
            isCollision = true;
        }
    }

    for(auto player : m_players) {
        if (player == &object) {
            continue;
        } else {
           if (object.bounds().intersects(player->bounds())) {
               if (object.movableType() == MovableObjectType::BULLET) {
                   Bullet bullet = (Bullet &) object;
                   player->setHp(player->hp() - bullet.damage());
               }
           }
        }
    }

    return isCollision;
}
