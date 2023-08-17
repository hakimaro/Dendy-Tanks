#include "rasterwindow.h"

constexpr unsigned WINDOW_WIDTH = 600;
constexpr unsigned WINDOW_HEIGHT = 600;

RasterWindow::RasterWindow(QWindow *parent)
    : QWindow(parent)
    , m_backing_store(new QBackingStore(this))
    , m_scene(std::make_unique<LevelScene>(RectF{0, 0, float(WINDOW_WIDTH), float(WINDOW_HEIGHT)}))
{
    setMinimumSize(QSize(WINDOW_WIDTH, WINDOW_HEIGHT));
    setMaximumSize(QSize(WINDOW_WIDTH, WINDOW_HEIGHT));
    m_updateTimer.start();
}

bool RasterWindow::event(QEvent *event) {
    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        return true;
    }
    return QWindow::event(event);
}

void RasterWindow::exposeEvent(QExposeEvent *event) {
    if (isExposed()) {
        renderNow();
    }
}

void RasterWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        keys.left = true;
    } else if (event->key() == Qt::Key_Up) {
        keys.up = true;
    } else if (event->key() == Qt::Key_Right) {
        keys.right = true;
    } else if (event->key() == Qt::Key_Down) {
        keys.down = true;
    } else if (event->key() == Qt::Key_Space) {
        if(event->isAutoRepeat()) {
            return;
        } else {
            m_scene->fireMan();
        }
    }
}

void RasterWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        keys.left = false;
    } else if (event->key() == Qt::Key_Up) {
        keys.up = false;
    } else if (event->key() == Qt::Key_Right) {
        keys.right = false;
    } else if (event->key() == Qt::Key_Down) {
        keys.down = false;
    }
}

void RasterWindow::resizeEvent(QResizeEvent *resizeEvent) {
    m_backing_store->resize(resizeEvent->size());
    if (isExposed()) {
        renderNow();
    }
}

void RasterWindow::renderLater() {
    requestUpdate();
}

void RasterWindow::renderNow() {
    if (!isExposed()) {
        return;
    }

    updateScene();
    renderScene();

    if (m_isAnimating) {
        renderLater();
    }
}

bool RasterWindow::isAnimating() {
    return m_isAnimating;
}

void RasterWindow::setAnimating(bool isAnimating) {
    m_isAnimating = isAnimating;
    if (isAnimating) {
        renderLater();
    }
}

void RasterWindow::updateScene() {
    const float elapsedSeconds = float(m_updateTimer.elapsed()) / 1000.f;

    if (elapsedSeconds > 0) {
        m_updateTimer.restart();
        m_scene->update(keys, elapsedSeconds);
    }
}

void RasterWindow::renderScene() {
    QRect rect(0, 0, width(), height());
    m_backing_store->beginPaint(rect);

    QPaintDevice *device = m_backing_store->paintDevice();
    QPainter painter(device);

    painter.fillRect(0, 0, width(), height(), Qt::black);
    if (m_is_first_render) {
        //m_scene->redrawMap(painter);
        m_is_first_render = false;
    }
    m_scene->redraw(painter);
    painter.end();

    m_backing_store->endPaint();
    m_backing_store->flush(rect);
}
