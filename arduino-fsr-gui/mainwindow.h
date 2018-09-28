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
    void onValue(QString);

private:
    Ui::MainWindow *ui;
    SensorReader sensorReader;
    QCustomPlot *mPlot;
    QPointer<QCPGraph> mGraph1;
};

#endif // MAINWINDOW_H
