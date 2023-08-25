#include "movableobject.h"

MovableObject::MovableObject(MovableObjectType type) :
    GameObject()
    , m_movableType(type)
    , m_direction(Direction::RIGHT)
    , m_speed(0)
{
    setType(ObjectType::MOVABLE);
}

void MovableObject::move(float dt)
{
    float x = 0;
    float y = 0;
    float width = 0;
    float height = 0;
    if (m_isMoving) {        
        x = (m_bounds.x() + m_speed * std::cos((double) m_direction * M_PI / 180) * dt);
        y = (m_bounds.y() + m_speed * std::sin((double) m_direction * M_PI / 180) * dt);
        width = m_bounds.width();
        height = m_bounds.height();

        m_bounds = QRectF(x, y, width, height);
    }    
}

float MovableObject::speed() const
{
    return m_speed;
}

void MovableObject::setSpeed(float newSpeed)
{
    m_speed = newSpeed;
}

Direction MovableObject::direction() const
{
    return m_direction;
}

void MovableObject::setDirection(Direction newDirection)
{
    m_isMoving = true;
    m_direction = newDirection;
}

QImage* MovableObject::image()
{
    switch(m_direction) {
    case Direction::DOWN:
        return images.down;
    case Direction::LEFT:
        return images.left;
    case Direction::RIGHT:
        return images.right;
    case Direction::UP:
        return images.up;
    }
}

bool MovableObject::isMoving() const
{
    return m_isMoving;
}

void MovableObject::setIsMoving(bool newIsMoving)
{
    m_isMoving = newIsMoving;
}

MovableObjectType MovableObject::movableType() const
{
    return m_movableType;
}

void MovableObject::setMovableType(MovableObjectType newMovableType)
{
    m_movableType = newMovableType;
}
