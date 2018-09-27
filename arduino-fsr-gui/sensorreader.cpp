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
    /*serial.setPortName("COM3");
    serial.open(QIODevice::ReadWrite);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    while (!serial.isOpen()) {
        serial.open(QIODevice::ReadWrite);
    }*/

    int counter = 0;
    while(true)
    {
        counter++;
        qDebug() << "emitting value " << QString::number(counter);
        Q_EMIT messageSensor(QString::number(counter));
        QThread::sleep(1);
    }
}
