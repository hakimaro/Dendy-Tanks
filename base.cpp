#include "base.h"

Base::Base()
{
    m_hp = 1;
}

unsigned int Base::hp() const
{
    return m_hp;
}

QImage Base::image()
{
    return m_base_image;
}

void Base::add_hp(int hp) {
    m_hp += hp;
}
