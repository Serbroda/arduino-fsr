#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onShow(QShowEvent* event);

public Q_SLOTS:
    void onValue(QString);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
