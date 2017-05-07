#include "dataprocessing.h"
#include <QtSql>
#include <QDebug>

dataProcessing::dataProcessing(QObject *parent) : Qbject(parent)
{
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("mybd.sqlite");
    if (!dbase.open()) {
        qDebug() << "Dont open/n";

    }else
    {
        qDebug() << "Open/n";
    }
}
//~dataProcessing(){
//    if(*newRecipe != 0) {
//        delete newRecipe;
//    }
//}

void dataProcessing::createNewRecipe(){
    qDebug() << "Something happend";
}
