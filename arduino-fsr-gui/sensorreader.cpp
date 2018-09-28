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
    serial.setPortName("COM3");
    serial.open(QIODevice::ReadWrite);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    while (!serial.isOpen()) {
        serial.open(QIODevice::ReadWrite);
    }

    int counter = 0;
    unsigned long val = 0;

    while(!shouldStop)
    {
        counter++;
        //qDebug() << "emitting value " << QString::number(counter);

        if(counter % 100 == 0) {
            val = (unsigned long)122427;
        } else if (counter % 90 == 0) {
            val = (unsigned long)123234;
        }else {
            val = (unsigned long)94862;

        }

        qDebug() << "emitting value " << QString::number(val);
        Q_EMIT messageSensor(val);

        QThread::msleep(30);
    }
}
