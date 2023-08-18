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

#if 0
bool PoolTableScene::canMove(Man man, Direction move, float dt)
{
    vector2f position = man.position();
    vector2f size = man.size();
    float speed = man.speed();

    float column_left = ((position.x - (size.x) / 2)) / m_size_of_square;
    float row_top = (position.y - (size.y) / 2) / m_size_of_square;
    float row_down = (position.y + (size.y) / 2) / m_size_of_square;
    float column_right = (position.x + (size.x / 2)) / m_size_of_square;
    switch (move) {
    case Direction::DOWN:
        row_down += speed * dt / m_size_of_square;
        //qDebug() << row_down << column_left << column_right;
        return  m_map.at(column_left, row_down)->type() != WallType::water && m_map.at(column_right, row_down)->type() != WallType::water
                && m_map.at(column_left, row_down)->hp() <= 0 && m_map.at(column_right, row_down)->hp() <= 0;
    case Direction::LEFT:
        column_left -= speed * dt / m_size_of_square;
        //qDebug() << column_left << row_top << row_down;
        return m_map.at(column_left, row_top)->type() != WallType::water && m_map.at(column_left, row_down)->type() != WallType::water
                && m_map.at(column_left, row_top)->hp() <= 0 && m_map.at(column_left, row_down)->hp() <= 0;
    case Direction::RIGHT:
        column_right += speed * dt / m_size_of_square;
        //qDebug() << column_right << row_down << row_top;
        return m_map.at(column_right, row_down)->type() != WallType::water && m_map.at(column_right, row_top)->type() != WallType::water
                && m_map.at(column_right, row_down)->hp() <= 0 && m_map.at(column_right, row_top)->hp() <= 0;
        break;
    case Direction::UP:
        row_top -= speed * dt / m_size_of_square;
        //qDebug() << row_top << column_left << column_right;
        return m_map.at(column_left, row_top)->type() != WallType::water && m_map.at(column_right, row_top)->type() != WallType::water
                && m_map.at(column_left, row_top)->hp() <= 0 && m_map.at(column_right, row_top)->hp() <= 0;
        break;
    }
}
#endif
bool MovableObject::containsObject(const Map *map, float dt)
{
    float column_left = (m_position.x - (m_size.x) / 2);
}
