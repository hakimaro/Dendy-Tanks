#include "tank.h"

Tank::Tank() :
    MovableObject(MovableObjectType::TANK)
  , m_spawnPosition(0, 0)
  , m_currentTeam(Team::GREEN)
  , m_bullet(nullptr)
{
    changeTeam(m_currentTeam);
}

void Tank::changeTeam(Team team)
{
    m_currentTeam = team;    
    images.left  = new QImage(QString(":tanks/res/tanks/tank%1_left.png").arg((int) team));
    images.right = new QImage(QString(":tanks/res/tanks/tank%1_right.png").arg((int) team));
    images.up    = new QImage(QString(":tanks/res/tanks/tank%1_up.png").arg((int) team));
    images.down  = new QImage(QString(":tanks/res/tanks/tank%1_down.png").arg((int) team));
}

void Tank::fire()
{
//    m_bullet = new Bullet(m_position, { m_size.x/3, m_size.y/3 }, m_direction);
}

Bullet* Tank::bullet() {
    return m_bullet;
}

void Tank::setBullet(Bullet *newBullet)
{
    m_bullet = newBullet;
}

Team Tank::currentTeam() const
{
    return m_currentTeam;
}

void Tank::setCurrentTeam(Team newCurrentTeam)
{
    m_currentTeam = newCurrentTeam;
}

vector2f Tank::spawnPosition() const
{
    return m_spawnPosition;
}

void Tank::setSpawnPosition(const vector2f &newSpawnPosition)
{
    m_spawnPosition = newSpawnPosition;
}


