#include "unmovableobject.h"

UnmovableObject::UnmovableObject()
{
    setWallType(WallType::BRICK);
}

QImage *UnmovableObject::image()
{
    return m_wallImage;
}

WallType UnmovableObject::wallType() const
{
    return m_wallType;
}

void UnmovableObject::setWallType(WallType newWallType)
{
    m_wallImage = new QImage(QString(":objects/res/objects/wall_%1.png").arg((int) newWallType));
    m_wallType = newWallType;
}
