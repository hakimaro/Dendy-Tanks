#ifndef LEVEL_H
#define LEVEL_H

#include "map.h"
#include "Model/tank.h"

class Level
{
public:
    Level();

    void loadLevel();
    void loadNextLevel();

    Tank *player() const;

    std::vector<Tank *> enemies() const;

    Map *map() const;
private:
    int m_currentLevel = 0;
    Map *m_map;
    std::vector<Tank*> m_enemies;
    Tank *m_player;
};

#endif // LEVEL_H
