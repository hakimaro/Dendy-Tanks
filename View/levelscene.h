#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QtGui/QPainter>
#include "Model/tank.h"
#include <rect.h>
#include "Model/level.h"
#include "keys.h"

class LevelScene
{
public:
    explicit LevelScene(const RectF &bounds);

    void update(pressedKeys keys, float dt);
    void redraw(QPainter &painter);
    void redrawMap(QPainter &painter);

    void fireMan();

    bool isInObject(MovableObject object, float dt);

    vector2f marginPosition(vector2f position, vector2f size, float speed, float dt);
    bool canMove(Tank man, Direction , float dt);
    bool isHitWall(Bullet bullet);
private:
    Level *m_level;
    const RectF m_bounds;    
    float m_size_of_square = 0;
};

#endif // LEVELSCENE_H
