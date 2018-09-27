#ifndef SENSORTHREAD_H
#define SENSORTHREAD_H
#include <QtCore>

class SensorThread : public QThread
{
    Q_OBJECT
public:
    SensorThread();
    void run();

public Q_SLOTS:
    void calc();

Q_SIGNALS:
    void message(QString);

public:
    int *pnt;
};

#endif // SENSORTHREAD_H
