#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector2f.h>
#include <QImage>

typedef enum class TypeOfObject { SPACE = 0, WATER, WALL, PLAYER, ENEMY, BULLET } ObjectType;

class GameObject
{
public:
    explicit GameObject();
    ~GameObject() = default;

    virtual QImage* image();

    vector2f position() const;
    void setPosition(const vector2f &newPosition);

    ObjectType type() const;
    void setType(ObjectType newType);

    float hp() const;
    void setHp(float newHp);

    vector2f size() const;
    void setSize(const vector2f &newSize);

    // For DEBUGGING
    void showType();
protected:
    ObjectType m_type;
    vector2f m_position;
    float m_hp;
    vector2f m_size;
};

#endif // GAMEOBJECT_H
