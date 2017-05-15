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

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("mybd.sqlite");
    if (!dbase.open()) {
        qDebug() << "Dont open db";
        return 0;

    }
    MainWindow w;
    //dataProcessing* mai= new dataProcessing(&w,NULL);

    //SearchForm f;
    //f.show();


    //MainWindow w;
   // RecipeWidget testr;

    //QObject::connect(&mai,SIGNAL(get_name(QString)),&testr,SLOT(set_name(QString)));
   // QObject::connect(&mai,SIGNAL(get_time(QString)),&testr,SLOT(set_time(QString)));
    //QObject::connect(&mai,SIGNAL(get_dscr(QString)),&testr,SLOT(set_dscr(QString)));


  //  QObject::connect(&mai,SIGNAL(add_last_rep_to_layout(Recipe*)),&w,SLOT(add_last_rep(Recipe*)));
   //QObject::connect(&mai,SIGNAL(get_time(QString)),&testr,SLOT(set_time(QString)));
    //QObject::connect(&mai,SIGNAL(get_dscr(QString)),&testr,SLOT(set_dscr(QString)));
  w.show();

    return a.exec();
}
