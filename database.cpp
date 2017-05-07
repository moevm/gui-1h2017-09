#include "database.h"
#include <QCoreApplication>

#include <iostream>
#include <QtSql/qtsql>
#include <windows.h>
#include <QDebug>
DataBase::DataBase()
{

}

int ssokgsdvl(int argc, char *argv[])
{
     //  setlocale(LC_ALL,"Russian");

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("mybd.sqlite");
    if (!dbase.open()) {
    //   QDebug() << "Не сработало\n";
        return -1;
    }else
    {
   //     std::cout << "связались с  бд\n";
    }

    QSqlQuery a_query;

  }
