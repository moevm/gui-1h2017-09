#include "mainwindow.h"
#include <QApplication>
#include "recipefullwidget.h"
#include "dataprocessing.h"
#include "recipewidget.h"
#include "searchform.h"
#include <QObject>
#include <QWidget>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SearchForm f;
    f.show();

    //MainWindow w;
    //dataProcessing* mai= new dataProcessing(&w,NULL);

    //MainWindow w;
   // RecipeWidget testr;

    //QObject::connect(&mai,SIGNAL(get_name(QString)),&testr,SLOT(set_name(QString)));
   // QObject::connect(&mai,SIGNAL(get_time(QString)),&testr,SLOT(set_time(QString)));
    //QObject::connect(&mai,SIGNAL(get_dscr(QString)),&testr,SLOT(set_dscr(QString)));


  //  QObject::connect(&mai,SIGNAL(add_last_rep_to_layout(Recipe*)),&w,SLOT(add_last_rep(Recipe*)));
   //QObject::connect(&mai,SIGNAL(get_time(QString)),&testr,SLOT(set_time(QString)));
    //QObject::connect(&mai,SIGNAL(get_dscr(QString)),&testr,SLOT(set_dscr(QString)));



    //mai.start();

    //testr.show();
   // w.show();

    return a.exec();
}
