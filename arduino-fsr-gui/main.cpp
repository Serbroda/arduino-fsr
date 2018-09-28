#include <QtWidgets>
#include "mainwindow.h"
#include <QObject>
#include "sensorreader.h"

int main(int argc, char *argv[]) {

    QApplication anwendung(argc, argv);

    MainWindow w;
    w.show();

    return anwendung.exec();
}
