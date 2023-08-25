#include "level.h"

Level::Level()
{
    m_map = new Map();
    loadLevel();
}

void Level::loadLevel()
{
    m_map->clearMap();
    QString filename = QString(":maps/maps/level_%1.json").arg(m_currentLevel);
    m_map->readMap(filename);    
}

void Level::loadNextLevel()
{
    m_currentLevel++;
    loadLevel();
}

Tank *Level::player() const
{
    return m_map->players()->first();
}

Map *Level::map() const
{
    return m_map;
}
#include <QDebug>

bool Level::marginPosition(MovableObject *object, QRectF mapBounds) {
    bool isMargined = false;
    QRectF objectBounds = object->bounds();
    qDebug() << "Map" << mapBounds.bottom() << mapBounds.left() << mapBounds.right() << mapBounds.top();
    qDebug() << "Player" << objectBounds.bottom() << objectBounds.left() << objectBounds.right() << objectBounds.top();

    float x = objectBounds.x();
    float y = objectBounds.y();
    float width = objectBounds.width();
    float height = objectBounds.height();
// слева
    if (objectBounds.left() < mapBounds.left()) {
        x = 0;
        isMargined = true;
    }
// справа
    if (objectBounds.right() > mapBounds.right()) {
        x = mapBounds.right()-object->bounds().width();
        isMargined = true;
    }
// снизу
    if (objectBounds.bottom() > mapBounds.bottom()) {
        y = mapBounds.bottom()-object->bounds().height();
        isMargined = true;
    }
// сверху    
    if (objectBounds.top() < mapBounds.top()) {
        y = 0;
        isMargined = true;
    }

    object->setBounds(QRectF(x, y, width, height));
    return isMargined;
}

