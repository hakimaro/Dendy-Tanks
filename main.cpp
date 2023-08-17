#include <QtGui/QGuiApplication>
#include "View/rasterwindow.h"

#include "Model/level.h"
int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    //Level *level = new Level();
    //level->loadLevel();

    RasterWindow window;
    window.setAnimating(true);
    window.show();

    return a.exec();
}
