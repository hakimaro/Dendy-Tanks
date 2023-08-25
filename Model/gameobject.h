#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector2f.h>
#include <QImage>
#include <rect.h>

typedef enum class TypeOfObject { SPACE = 0, UNMOVABLE = 1, MOVABLE = 2 } ObjectType;

class GameObject
{
public:
    explicit GameObject();
    ~GameObject() = default;

    virtual QImage* image();

    ObjectType type() const;
    void setType(ObjectType newType);

    float hp() const;
    void setHp(float newHp);

    QRectF bounds() const;
    void setBounds(const QRectF& newBounds);

    // For DEBUGGING
    void showType();
protected:
    ObjectType m_type;
    float m_hp;

    // AABB объекта.
    QRectF m_bounds;
};

#endif // GAMEOBJECT_H
