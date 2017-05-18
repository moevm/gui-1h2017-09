#include "mainwindow.h"
#include <QApplication>
#include "dataprocessing.h"
#include "changerecipeform.h"
#include "newrecipeform.h"
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QtSql>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     dataProcessing* mai= new dataProcessing();
    MainWindow  w;

    QObject::connect(w.new_rep,SIGNAL(get_dscr(QString)),mai,SLOT(set_descr(QString)));
    QObject::connect(w.new_rep,SIGNAL(get_ingr(QString)),mai,SLOT(set_ingr(QString)));
    QObject::connect(w.new_rep,SIGNAL(get_name(QString)),mai,SLOT(set_name(QString)));
    QObject::connect(w.new_rep,SIGNAL(get_time(int)),mai,SLOT(set_time(int)));
    QObject::connect(w.new_rep,SIGNAL(get_txt(QString)),mai,SLOT(set_text(QString)));
    QObject::connect(w.new_rep,SIGNAL(end_transact()),mai,SLOT(end_transact()));

 w.show();

    return a.exec();
}
