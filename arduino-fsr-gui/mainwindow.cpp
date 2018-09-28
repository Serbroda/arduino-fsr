#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "sensorreader.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onShow(QShowEvent* event)
{

}

void MainWindow::onValue(QString value)
{
    qDebug() << "Received value " << value;
}
