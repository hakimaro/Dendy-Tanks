#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include "gameobject.h"
//#include "Model/map.h"
#include <rect.h>

enum class Direction { LEFT = 180, UP = 270, RIGHT = 0, DOWN = 90 };
enum class MovableObjectType { BULLET, TANK };

typedef struct KeysToPress {
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
} pressedKeys;

class MovableObject : public GameObject
{
public:
    MovableObject(MovableObjectType type);
    ~MovableObject() = default;

    void move(float dt);

    float speed() const;
    void setSpeed(float newSpeed);

    Direction direction() const;
    void setDirection(Direction newDirection);

    QImage* image() override;

    bool isMoving() const;
    void setIsMoving(bool newIsMoving);

    MovableObjectType movableType() const;
    void setMovableType(MovableObjectType newMovableType);

protected:
    MovableObjectType m_movableType;
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
