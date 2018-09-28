#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "sensorreader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mPlot = new QCustomPlot(this);
    setCentralWidget(mPlot);

    mPlot->yAxis->setTickLabels(false);
    connect(mPlot->yAxis2, SIGNAL(rangeChanged(QCPRange)), mPlot->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    mPlot->axisRect()->addAxis(QCPAxis::atRight);

    mGraph1 = mPlot->addGraph(mPlot->xAxis, mPlot->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph1->setPen(QPen(QColor(250, 120, 0)));

    sensorReader.start();

    connect(&sensorReader, SIGNAL(messageSensor(QString)), this, SLOT(onValue(QString)));
}

MainWindow::~MainWindow()
{
    sensorReader.exit(0);
    delete ui;
}

void MainWindow::onValue(QString value)
{
    qDebug() << "Received value " << value;
}
