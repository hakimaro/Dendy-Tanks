#ifndef WALL_H
#define WALL_H

#include <QtGui/QImage>

enum class WallType { brick = 3, iron = 30, grass = -1, nothing = 0, base = 1, water = -2 };

class Wall
{
public:
    Wall();
    Wall(WallType type);

    bool hit();

    QImage image();
    int hp() const;

    WallType type() const;
    void setType(WallType newType);

private:
    WallType m_type;
    int m_hp;

    struct {
        QImage image_brick_full = QImage(":wall/res/stone_full.png");
        QImage image_brick_half = QImage(":wall/res/stone_half.png");
        QImage image_brick_low = QImage(":wall/res/stone_low.png");
    } brick_images;

    struct {
        QImage image_iron_full = QImage(":wall/res/iron.png");
    } iron_images;

    struct {
        QImage image_ground = QImage(":wall/res/ground.png");
    } ground_images;

    struct {
        QImage image_grass = QImage(":wall/res/grass.png");
    } grass_images;

    struct {
        QImage image_base = QImage(":wall/res/base.png");
    } base_images;

    struct {
        QImage image_water = QImage(":wall/res/water.png");
    } water_images;
};

#endif // WALL_H
