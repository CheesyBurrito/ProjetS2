/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

GuessWho.cpp
*****************************************/

#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "MainWindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	QString locale = QLocale::system().name().section('_', 0, 0);
	QTranslator translator;
	translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	app.installTranslator(&translator);

    MainWindow main;

    return app.exec();
}
