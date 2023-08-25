#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QtGui/QPainter>
#include "Model/tank.h"
#include "Model/level.h"

class LevelScene
{
public:
    explicit LevelScene(const QRectF &bounds);

    void update(pressedKeys keys, float dt);
    void redraw(QPainter &painter);

    void fireMan();
private:
    const QRectF m_windowBounds;

    Level *m_level;
    float m_scale = 1;
};

#endif // LEVELSCENE_H
