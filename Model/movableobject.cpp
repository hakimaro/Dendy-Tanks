#include "movableobject.h"

MovableObject::MovableObject() :
    GameObject()
    , m_direction(Direction::RIGHT)
    , m_speed(0)
{

}

void MovableObject::move(float dt)
{
    if (m_isMoving) {
        m_position.x += (m_speed * std::cos((double) m_direction * M_PI / 180) * dt);
        m_position.y += (m_speed * std::sin((double) m_direction * M_PI / 180) * dt);
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

void MovableObject::marginPosition(RectF bounds, float dt)
{
    if (m_position.x - m_size.x / 2 < bounds.leftEdge()) {
        m_position.x = m_position.x + m_speed * dt;
    }
    if (m_position.x + m_size.x / 2 > bounds.rightEdge()) {
        m_position.x = m_position.x - m_speed * dt;
    }
    if (m_position.y - m_size.y / 2 < bounds.topEdge()) {
        m_position.y = m_position.y + m_speed * dt;
    }
    if (m_position.y + m_size.y / 2 > bounds.bottomEdge()) {
        m_position.y = m_position.y - m_speed * dt;
    }
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
