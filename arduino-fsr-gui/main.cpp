#include <QtWidgets/QApplication>
#include <QThread>
#include <QtCore>
#include "sensorthread.h"
#include "qtsensorgraph.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QtSensorGraph window;
    window.resize(400, 300);
    window.show();

    //SensorThread sensorThread;
    //sensorThread.start();

    return a.exec();
}
