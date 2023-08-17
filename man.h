#ifndef MAN_H
#define MAN_H

#include <vector2f.h>
#include <vector>
#include "move.h"
#include "Model/bullet.h"
#include <QtGui/QImage>

enum class Team { RED = '0', GRAY = '1', YELLOW = '2', GREEN = '3' };

class Man
{
public:
    explicit Man();

    void move(Direction move, float dt);

    void fire();

    std::vector<Bullet> bullets() const;

    vector2f position() const;
    void setPosition(const vector2f &newPosition);

    vector2f size() const;
    void setSize(const vector2f &newSize);

    float speed() const;
    void setSpeed(float newSpeed);

    void setBullets(const std::vector<Bullet> &newBullets);

    Direction view() const;

    QImage image();
    void setView(Direction newView);

    vector2f position_spawn() const;

private:
    vector2f m_position_spawn = {4, 13};

    Direction m_view;
    std::vector<Bullet> m_bullets;
    vector2f m_position;
    vector2f m_size;
    float m_speed;

    bool isAlive = true;
    int lifes = 3;

    struct {
        QImage image_tank_left = QImage(":images/res/tank_left.png");
        QImage image_tank_up = QImage(":images/res/tank_up.png");
        QImage image_tank_right = QImage(":images/res/tank_right.png");
        QImage image_tank_down = QImage(":images/res/tank_down.png");
    } tank_images ;
};

#endif // MAN_H
