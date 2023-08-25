#ifndef BULLET_H
#define BULLET_H

#include "Model/movableobject.h"

class Bullet : public MovableObject
{
public:
    explicit Bullet(vector2f position, vector2f size, Direction move);

    float damage() const;

private:
    float m_damage = 1;
};

#endif // BULLET_H
