#include "unmovableobject.h"
#include <QDebug>

UnmovableObject::UnmovableObject(UnmovableObjectType type) :
    objectType(type)
{
    setType(ObjectType::UNMOVABLE);
    m_image = new QImage(QString(":objects/res/objects/Wall_%1.png").arg((int) type));
}

QImage *UnmovableObject::image()
{
    return m_image;
}
