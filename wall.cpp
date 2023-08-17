#include "wall.h"
#include "qimage.h"

Wall::Wall() :
    m_type(WallType::nothing), m_hp(0)
{

}

Wall::Wall(WallType type) :
    m_type(type), m_hp((int) type)
{

}

bool Wall::hit()
{
    if (m_type == WallType::iron) {
        return true;
    }
    m_hp--;

    return true;
}

QImage Wall::image() {
    float percent_of_full_hp = (100 * (float) m_hp / (int) m_type);
    switch(m_type) {
    case WallType::brick:
        if (percent_of_full_hp >= 67.0f) {           
            return brick_images.image_brick_full;
        } else if (percent_of_full_hp >= 34.0f) {
            return brick_images.image_brick_half;
        } else {
            return brick_images.image_brick_low;
        }
        break;
    case WallType::iron:
        return iron_images.image_iron_full;
        break;
    case WallType::nothing:
        return ground_images.image_ground;        
        break;
    case WallType::grass:
        return grass_images.image_grass;
        break;
    case WallType::base:
        return base_images.image_base;
        break;
    case WallType::water:
        return water_images.image_water;
    }
}

int Wall::hp() const
{
    return m_hp;
}

WallType Wall::type() const
{
    return m_type;
}

void Wall::setType(WallType newType)
{
    m_type = newType;
}
