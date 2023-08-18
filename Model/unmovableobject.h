#ifndef UNMOVABLEOBJECT_H
#define UNMOVABLEOBJECT_H

#include "gameobject.h"

enum class WallType { BRICK = 1, IRON = 2, WATER = 3, GRASS = 4 };
class UnmovableObject : public GameObject
{
public:
    UnmovableObject();


    QImage *image() override;
    WallType wallType() const;
    void setWallType(WallType newWallType);

private:
    WallType m_wallType;
    QImage *m_wallImage;
};

#endif // UNMOVABLEOBJECT_H
