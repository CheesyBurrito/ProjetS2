#include <QApplication>
#include "StartWindow.h"
#include "MainWindow.h"
#include "MenuWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow main;
	main.showFullScreen();

    return app.exec();
}
