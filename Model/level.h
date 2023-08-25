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
    bool marginPosition(MovableObject *object, QRectF bounds);
private:
    int m_currentLevel = 0;
    Map *m_map;
};

#endif // LEVEL_H
