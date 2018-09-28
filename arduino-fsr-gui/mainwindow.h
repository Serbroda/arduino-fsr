#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "qcustomplot.h"
#include "sensorreader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public Q_SLOTS:
    void onValue(unsigned long);
    void realtimePlot();

private:
    Ui::MainWindow *ui;
    SensorReader sensorReader;
    ulong adc_data_g;
    QTimer timer_plot;
};

#endif // MAINWINDOW_H
