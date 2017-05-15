#include "dataprocessing.h"
#include <QtSql>
#include <QDebug>

dataProcessing::dataProcessing(MainWindow  * w,QObject *parent) : QObject(parent)
{
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("mybd.sqlite");
    if (!dbase.open()) {
        qDebug() << "Dont open db";

    }else
    {
        qDebug() << "Open db";
    }
}


dataProcessing::dataProcessing(QObject *parent) : QObject(parent)
{
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("mybd.sqlite");
    if (!dbase.open()) {
        qDebug() << "Dont open db";

    }else
    {
        qDebug() << "Open db";

    }
}



dataProcessing::~dataProcessing(){

}

