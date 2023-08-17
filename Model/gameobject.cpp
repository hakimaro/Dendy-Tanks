#include "gameobject.h"

GameObject::GameObject() :
    m_type(TypeOfObject(0))
  , m_position(0, 0)
  , m_hp(0)
  , m_size(0, 0)
{

}

vector2f GameObject::position() const
{
    return m_position;
}

void GameObject::setPosition(const vector2f &newPosition)
{
    m_position = newPosition;
}

ObjectType GameObject::type() const
{
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
}

vector2f GameObject::size() const
{
    return m_size;
}

void GameObject::setSize(const vector2f &newSize)
{
    m_size = newSize;
}

#include <QDebug>
void GameObject::showType()
{
    switch(m_type) {
    case ObjectType::SPACE:
        qDebug() << "Space";
        break;
    case ObjectType::WALL:
        qDebug() << "Wall";
        break;
    }
}
