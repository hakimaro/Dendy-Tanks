#include "gameobject.h"
#include <QDebug>

GameObject::GameObject() :
    m_type(ObjectType::SPACE)
  //, m_position(0, 0)
  , m_hp(0)
  //, m_size(0, 0)
{

}

ObjectType GameObject::type() const
{
    if (this == nullptr) {
        qDebug() << "Nullptr";
        return ObjectType::MOVABLE;
    }
    return m_type;
}

QImage* GameObject::image() { return nullptr; }

void GameObject::setType(ObjectType newType)
{
    m_type = newType;
}

float GameObject::hp() const
{
    return m_hp;
}

void GameObject::setHp(float newHp)
{
    m_hp = newHp;

    if (m_hp <= 0 && m_type == ObjectType::UNMOVABLE) {
        m_type = ObjectType::SPACE;
    }
}

void GameObject::showType()
{
    switch(m_type) {
    case ObjectType::SPACE:
        qDebug() << "Space";
        break;
    case ObjectType::UNMOVABLE:
        qDebug() << "UNMOVABLE";
        break;
    case ObjectType::MOVABLE:
        qDebug() << "MOVABLE";
        break;
    }
}

QRectF GameObject::bounds() const
{
    return m_bounds;
}

void GameObject::setBounds(const QRectF&newBounds)
{
    m_bounds = newBounds;
}
