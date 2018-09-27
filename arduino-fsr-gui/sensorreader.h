#ifndef SENSORTHREAD_H
#define SENSORTHREAD_H
#include <QtCore>

class SensorReader : public QThread
{
    Q_OBJECT

public:
    SensorReader();
    void run();

public Q_SLOTS:
    void readSensor();

Q_SIGNALS:
    void messageSensor(QString);

};

#endif // SENSORTHREAD_H
