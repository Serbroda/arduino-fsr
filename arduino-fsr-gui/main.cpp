#include <QtWidgets/QApplication>
#include <QThread>
#include <QtCore>
#include "sensorreader.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    /*SensorReader reader;
    reader.start();

    QObject::connect(&reader, SIGNAL(messageSensor(QString)), window, SLOT(onValue(QString)));*/

    return a.exec();
}
