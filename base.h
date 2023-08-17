#ifndef BASE_H
#define BASE_H

#include <QtGui/QImage>

class Base
{
public:
    Base();

    void add_hp(int hp);
    unsigned int hp() const;

    QImage image();
private:
    unsigned int m_hp;
    QImage m_base_image;
};

#endif // BASE_H
