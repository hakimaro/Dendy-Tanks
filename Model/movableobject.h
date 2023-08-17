#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include "gameobject.h"
#include "move.h"
#include <rect.h>

enum class Direction { LEFT = 180, UP = 270, RIGHT = 0, DOWN = 90 };

class MovableObject : public GameObject
{
public:
    MovableObject();
    ~MovableObject() = default;

    void move(float dt);

    float speed() const;
    void setSpeed(float newSpeed);

    Direction direction() const;
    void setDirection(Direction newDirection);

    void marginPosition(RectF bounds, float dt);

    QImage* image() override;

    bool isMoving() const;
    void setIsMoving(bool newIsMoving);

protected:
    Direction m_direction;
    float m_speed;
    bool m_isMoving = false;

    struct {
        QImage* left;
        QImage* right;
        QImage* up;
        QImage* down;
    } images;
};

#endif // MOVABLEOBJECT_H
