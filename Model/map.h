#ifndef MAP_H
#define MAP_H

#include "gameobject.h"
#include <vector2f.h>

class Map
{
public:
    Map();
    ~Map();

    GameObject* at(int i, int j);
    vector2f mapSizes() const;

    void readMap(QString filename);    
private:
    vector2f m_mapSizes;
    GameObject*** m_objects;
};

#endif // MAP_H
