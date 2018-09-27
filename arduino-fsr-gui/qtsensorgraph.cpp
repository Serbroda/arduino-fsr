#include "qtsensorgraph.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "sensorreader.h"
#include <QDebug>

QtSensorGraph::QtSensorGraph(QWidget *parent) : QMainWindow (parent)
{
    series = new QLineSeries();

    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartView);
}

void QtSensorGraph::onValue(QString val) {
    qDebug() << "Got value " << val << " on window";
    series->remove(0);
    series->append(11, 4);
}
