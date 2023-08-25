#ifndef TANK_H
#define TANK_H

#include "movableobject.h"
#include "bullet.h"

enum class Team { RED = 0, GRAY = 1, GREEN = 2, YELLOW = 3 };
class Tank : public MovableObject
{
public:
    Tank();
    ~Tank() = default;

    void changeTeam(Team team);

    void fire();

    Bullet* bullet();
    void setBullet(Bullet *newBullet);

    Team currentTeam() const;
    void setCurrentTeam(Team newCurrentTeam);

    vector2f spawnPosition() const;
    void setSpawnPosition(const vector2f &newSpawnPosition);

private:
    float lives = 3;
    vector2f m_spawnPosition;
    Team m_currentTeam;
    Bullet *m_bullet;
};

#endif // TANK_H
