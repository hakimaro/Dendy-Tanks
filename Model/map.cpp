#include "map.h"
#include "wall.h"
#include <QDebug>

Map::Map()
{
}

Map::~Map()
{
    for(int i = 0; i < m_mapSizes.x; ++i) {
        delete[] m_objects[i];
    }
    delete[] m_objects;
}

#include <QFile>
#include <QString>

GameObject* Map::at(int i, int j)
{
    if (i < m_mapSizes.x && j < m_mapSizes.y) {
        return m_objects[j][i];
    }
    return nullptr;
}

vector2f Map::mapSizes() const
{
    return m_mapSizes;
}

#include <iostream>

void Map::readMap(QString filename)
{
    QFile file(filename.toStdString().c_str());
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Couldn't open file";
        return;
    }
    QByteArray data;
    data = file.readAll();

    int prev_index = 0;
    int next_index = data.indexOf('\n', prev_index);
    qDebug() << data;
    qDebug() << data.size();
    qDebug() << next_index;

    m_mapSizes.x = data.size() / (next_index + 1);
    m_mapSizes.y = next_index;

    m_objects = new GameObject**[(int) m_mapSizes.x];
    for(int i = 0; i < m_mapSizes.x; ++i) {
        m_objects[i] = new GameObject*[(int) m_mapSizes.y];
        for(int j = 0; j < m_mapSizes.y; ++j) {
            m_objects[i][j] = new GameObject();
            m_objects[i][j]->setType(TypeOfObject((int) (data[i * ((int) m_mapSizes.x + 1) + j] - '0')));
        }
    }

    for(int i = 0; i < m_mapSizes.x; ++i) {
        QString str;
        for(int j = 0; j < m_mapSizes.y; ++j) {
            str.append(QString::number((int) m_objects[i][j]->type()));
        }
        qDebug() << str;
    }
}
