#ifndef MAP_H
#define MAP_H

#include "Model/tank.h"
#include "Model/unmovableobject.h"
#include <vector2f.h>

// Просто хранит все позиции игровых объектов.
class Map
{
public:
    Map() = default;
    ~Map();

    void clearMap();

    void readMap(QString filename);
    void jsonUnmovableObjectToRead(QJsonArray array, QVector<UnmovableObject *>& object, UnmovableObjectType type);
    void jsonMovableObjectToRead(QJsonArray array, QVector<Tank *>& object);

    QVector<UnmovableObject *>* bricks();
    QVector<UnmovableObject *>* irons();
    QVector<UnmovableObject *>* grass();
    QVector<UnmovableObject *>* water();
    QVector<Tank *>* players();

    bool hasCollision(MovableObject object, float dt);
private:
    QVector<UnmovableObject*> m_bricks;
    QVector<UnmovableObject*> m_irons;
    QVector<UnmovableObject*> m_grass;
    QVector<UnmovableObject*> m_water;
    QVector<Tank*> m_players;
};

#endif // MAP_H
