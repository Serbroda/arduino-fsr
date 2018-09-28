#include <QtWidgets>
#include "sensorreader.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    /*SensorReader reader;
    reader.start();

    QObject::connect(&reader, SIGNAL(messageSensor(QString)), w, SLOT(onValue(QString)));*/

    return a.exec();
}
