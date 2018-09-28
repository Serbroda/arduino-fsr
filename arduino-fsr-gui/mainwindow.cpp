#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "sensorreader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sensorReader.start();
    sensorReader.shouldStop = false;
    connect(&sensorReader, SIGNAL(messageSensor(unsigned long)), this, SLOT(onValue(unsigned long)));

    setCentralWidget(ui->centralWidget);

    /* Add graph and set the curve line color to green */
        ui->centralWidget->addGraph();
        ui->centralWidget->graph(0)->setPen(QPen(Qt::red));
        ui->centralWidget->graph(0)->setAntialiasedFill(false);

        /* Configure x-Axis as time in secs */
        QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
        timeTicker->setTimeFormat("%s");
        ui->centralWidget->xAxis->setTicker(timeTicker);
        ui->centralWidget->axisRect()->setupFullAxesBox();


        /* Configure x and y-Axis to display Labels */
        ui->centralWidget->xAxis->setTickLabelFont(QFont(QFont().family(),8));
        ui->centralWidget->yAxis->setTickLabelFont(QFont(QFont().family(),8));
        ui->centralWidget->xAxis->setLabel("Time(s)");
        ui->centralWidget->yAxis->setLabel("ADC Raw Counts");

        /* Make top and right axis visible, but without ticks and label */
        ui->centralWidget->xAxis2->setVisible(true);
        ui->centralWidget->yAxis->setVisible(true);
        ui->centralWidget->xAxis2->setTicks(false);
        ui->centralWidget->yAxis2->setTicks(false);
        ui->centralWidget->xAxis2->setTickLabels(false);
        ui->centralWidget->yAxis2->setTickLabels(false);

        /* Set up and initialize the graph plotting timer */
        connect(&timer_plot, SIGNAL(timeout()),this,SLOT(realtimePlot()));
        timer_plot.start(5);
}

MainWindow::~MainWindow()
{
    sensorReader.shouldStop = true;
    sensorReader.quit();
    delete ui;
}

void MainWindow::onValue(unsigned long value)
{
    qDebug() << "Received value " << value;

    /* Discard the noisy bits */
    value = value/100;

    /* Support the plotter */
    adc_data_g = value;

}

void MainWindow::realtimePlot()
{
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0;
    static double lastPointKey = 0;
    if(key - lastPointKey > 0.002)
    {
        ui->centralWidget->graph(0)->addData(key, (double)adc_data_g);
        lastPointKey = key;
    }

    ui->centralWidget->graph(0)->rescaleValueAxis();
    ui->centralWidget->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->centralWidget->replot();
}
