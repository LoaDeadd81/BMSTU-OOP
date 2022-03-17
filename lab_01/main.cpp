#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("ЛР №1");
    w.showMaximized();
//    w.setFixedSize(w.size());
    w.show();
    return a.exec();
}
