#include "mainwindow.h"
#include <QApplication>
#include "recipefullwidget.h"
#include "dataprocessing.h"
#include "recipewidget.h"
#include "searchform.h"
#include "ingrlist.h"
#include <QObject>
#include <QWidget>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    dataProcessing* mai= new dataProcessing();\
    // !!!!!!!!!!
    Ingredients i;
    SearchForm f;
     QObject::connect(&i,SIGNAL(get_ingrs(QString)),&f,SLOT(set_name_ingr(QString)));
      QObject::connect(&f,SIGNAL(get_all_ingr()),&i,SLOT(get_all_ingr()));
      f.get_all_ingr();
        f.show();
    // !!!!!

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
   w.show();

    return a.exec();
}
