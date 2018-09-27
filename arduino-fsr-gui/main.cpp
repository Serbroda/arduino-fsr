#include <QtWidgets/QApplication>
#include <QThread>
#include <QtCore>
#include "sensorreader.h"
#include "qtsensorgraph.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QtSensorGraph* window = new QtSensorGraph();
    window->resize(400, 300);
    window->show();

    SensorReader reader;
    reader.start();

    QObject::connect(&reader, SIGNAL(messageSensor(QString)), window, SLOT(onValue(QString)));

    return a.exec();
}
