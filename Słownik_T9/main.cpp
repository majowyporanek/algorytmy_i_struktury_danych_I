#include "mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QGuiApplication>
#include <QScreen>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(400, 300);
    QScreen *screen = QGuiApplication::screens().at(0);
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - w.width()) / 2;
    int y = (screenGeometry.height() - w.height()) / 2;
    w.move(x, y);
    w.show();
    return a.exec();
}

