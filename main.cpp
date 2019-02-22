#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainwindow mainwindow;
    QSize(5, 5);
    //mainwindow.setBaseSize(5,5);
    mainwindow.show();
    return a.exec();
}
