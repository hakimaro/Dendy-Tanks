#include "bullet.h"

Bullet::Bullet(vector2f position, vector2f size, Direction direction)
{
    setPosition(position);
    setSize(size);
    setDirection(direction);

    images.left =  new QImage(":images/res/bullet_left.png");
    images.down =  new QImage(":images/res/bullet_down.png");
    images.right = new QImage(":images/res/bullet_right.png");
    images.up =    new QImage(":images/res/bullet_up.png");
}
