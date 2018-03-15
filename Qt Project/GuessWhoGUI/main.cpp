#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFixedHeight(1080);
    w.setFixedWidth(1920);
    return a.exec();
}
