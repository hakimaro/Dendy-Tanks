#ifndef BULLET_H
#define BULLET_H

#include <vector2f.h>
#include "move.h"
#include <QtGui/QImage>
#include "Model/movableobject.h"

class Bullet : public MovableObject
{
public:
    explicit Bullet(vector2f position, vector2f size, Direction move);


private:
};

#endif // BULLET_H
