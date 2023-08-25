#ifndef UNMOVABLEOBJECT_H
#define UNMOVABLEOBJECT_H

#include "Model/gameobject.h"

enum UnmovableObjectType { Brick, Iron, Grass, Water };
class UnmovableObject : public GameObject
{
public:
    UnmovableObject(UnmovableObjectType type);

    QImage *image() override;
private:
    UnmovableObjectType objectType;
    QImage *m_image;
};

#endif // UNMOVABLEOBJECT_H
