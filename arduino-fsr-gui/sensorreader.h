#ifndef SENSORTHREAD_H
#define SENSORTHREAD_H
#include <QtCore>
#include <QtSerialPort/QSerialPort>

class SensorReader : public QThread
{
    Q_OBJECT

public:
    SensorReader();
    void run();
    bool shouldStop;

public Q_SLOTS:
    void readSensor();

Q_SIGNALS:
    void messageSensor(unsigned long);

private:
    QSerialPort serial;

};

#endif // SENSORTHREAD_H
