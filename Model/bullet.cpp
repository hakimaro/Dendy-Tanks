#include "bullet.h"

Bullet::Bullet(vector2f position, vector2f size, Direction direction) :
    MovableObject(MovableObjectType::BULLET)
{
    setDirection(direction);
    setSpeed(size.x * 32);

    images.left =  new QImage(":tanks/res/bullet_left.png");
    images.down =  new QImage(":tanks/res/bullet_down.png");
    images.right = new QImage(":tanks/res/bullet_right.png");
    images.up =    new QImage(":tanks/res/bullet_up.png");
}

float Bullet::damage() const
{
    return m_damage;
}
