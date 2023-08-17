#include "level.h"

Level::Level()
{
    m_map = new Map();
    m_player = new Tank();
    loadLevel();
}

void Level::loadLevel()
{
    QString filename = QString(":maps/maps/level_%1.txt").arg(m_currentLevel);
    m_map->readMap(filename);
}

void Level::loadNextLevel()
{
    m_currentLevel++;
    loadLevel();
}

Tank *Level::player() const
{
    return m_player;
}

std::vector<Tank *> Level::enemies() const
{
    return m_enemies;
}

Map *Level::map() const
{
    return m_map;
}
