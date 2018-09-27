#include "sensorreader.h"
#include <QtCore>
#include <QDebug>

SensorReader::SensorReader()
{

}

void SensorReader::run() {
    readSensor();
}

void SensorReader::readSensor()
{
    int counter = 0;
    while(true)
    {
        counter++;
        qDebug() << "emitting value " << QString::number(counter);
        Q_EMIT messageSensor(QString::number(counter));
        QThread::sleep(1);
    }
}
