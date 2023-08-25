#ifndef RASTERWINDOW_H
#define RASTERWINDOW_H

#include <QtGui/QWindow>
#include <QtGui/QPainter>
#include <QtGui/QResizeEvent>
#include <QtGui/QExposeEvent>
#include <QtGui/QBackingStore>
#include <QtGui/QKeyEvent>
#include <QtCore/QElapsedTimer>

#include "View/levelscene.h"

class RasterWindow : public QWindow
{
    Q_OBJECT

public:
    explicit RasterWindow(QWindow *window = nullptr);

    bool isAnimating();
    void setAnimating(bool isAnimating);
protected:
    bool event(QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    void renderLater();
    void renderNow();

    void updateScene();
    void renderScene();

    QBackingStore *m_backing_store = nullptr;
    std::unique_ptr<LevelScene> m_scene;
    QElapsedTimer m_updateTimer;
    bool m_isAnimating = false;
    bool m_is_first_render = true;

    pressedKeys keys;
};
#endif // RASTERWINDOW_H
