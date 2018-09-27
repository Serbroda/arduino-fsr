#include "sensorthread.h"
#include <QtCore>
#include <QDebug>

SensorThread::SensorThread()
{

}

void SensorThread::run() {
    while(true) {
        qDebug() << this->pnt << " Running thread";
        calc();
        QThread::sleep(1);
    }
}

void SensorThread::calc() {
    Q_EMIT message("val");
}
