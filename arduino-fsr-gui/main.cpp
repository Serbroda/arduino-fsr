#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QThread>
#include <QtCore>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QMainWindow window;
    window.resize(400, 300);
    window.show();

    return a.exec();
}
