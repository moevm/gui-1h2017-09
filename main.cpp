#include "mainwindow.h"
#include <QApplication>
#include "dataprocessing.h"
#include "searchform.h"
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QtSql>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        dataProcessing* mai= new dataProcessing();
    MainWindow w;
  w.show();

    return a.exec();
}
