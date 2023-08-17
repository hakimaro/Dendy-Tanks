#include "man.h"

Man::Man() :
     m_view(Direction::RIGHT)
   , m_position(m_position_spawn)
   , m_size({10, 10})
   , m_speed(10)
{
}

void Man::move(Direction move, float dt) {
    switch (move) {
    case Direction::LEFT:
        m_position.x -= m_speed * dt;
        break;
    case Direction::UP:
        m_position.y -= m_speed * dt;
        break;
    case Direction::RIGHT:
        m_position.x += m_speed * dt;
        break;
    case Direction::DOWN:
        m_position.y += m_speed * dt;
        break;
    default:
        break;
    }
    m_view = move;
}

void Man::fire()
{
    float size_X = (m_view == Direction::DOWN || m_view == Direction::UP) ? m_size.x / 4 : m_size.x / 3;
    float size_Y = (m_view == Direction::DOWN || m_view == Direction::UP) ? m_size.x / 3 : m_size.x / 4;
    Bullet bullet(m_position, {size_X, size_Y}, m_view);
    bullet.setSpeed(m_speed * 5);
    m_bullets.push_back(bullet);
}

std::vector<Bullet> Man::bullets() const
{
    return m_bullets;
}

vector2f Man::position() const
{
    return m_position;
}

void Man::setPosition(const vector2f &newPosition)
{
    m_position = newPosition;
}

vector2f Man::size() const
{
    return m_size;
}

float Man::speed() const
{
    return m_speed;
}

void Man::setSpeed(float newSpeed)
{
    m_speed = newSpeed;
}

void Man::setBullets(const std::vector<Bullet> &newBullets)
{
    m_bullets = newBullets;
}

Direction Man::view() const
{
    return m_view;
}

void Man::setSize(const vector2f &newSize)
{
    m_size = newSize;
}

QImage Man::image() {
    switch (m_view) {
    case Direction::DOWN:
        return tank_images.image_tank_down;
        break;
    case Direction::UP:
        return tank_images.image_tank_up;
        break;
    case Direction::LEFT:
        return tank_images.image_tank_left;
        break;
    case Direction::RIGHT:
        return tank_images.image_tank_right;
        break;
    default:
        break;
    }
}

void Man::setView(Direction newView)
{
    m_view = newView;
}

vector2f Man::position_spawn() const
{
    return m_position_spawn;
}
