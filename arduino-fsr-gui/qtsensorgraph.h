#ifndef QTSENSORGRAPH_H
#define QTSENSORGRAPH_H

#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
//#include <QtSerialPort/QSerialPort>

QT_CHARTS_USE_NAMESPACE

class QtSensorGraph : public QMainWindow
{
    Q_OBJECT

public:
    QtSensorGraph(QWidget *parent = Q_NULLPTR);

public Q_SLOTS:
    void onValue(QString);

private:

};

#endif // QTSENSORGRAPH_H
