#include "mainwindow.h"
#include <QApplication>
#include "dataprocessing.h"
#include "recipewidget.h"
#include <QObject>
#include <QWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dataProcessing mai;
    MainWindow w;
   // RecipeWidget testr;

    //QObject::connect(&mai,SIGNAL(get_name(QString)),&testr,SLOT(set_name(QString)));
   // QObject::connect(&mai,SIGNAL(get_time(QString)),&testr,SLOT(set_time(QString)));
    //QObject::connect(&mai,SIGNAL(get_dscr(QString)),&testr,SLOT(set_dscr(QString)));


    QObject::connect(&mai,SIGNAL(add_last_rep_to_layout(RecipeWidget*)),&w,SLOT(add_last_rep(RecipeWidget*)));
   //QObject::connect(&mai,SIGNAL(get_time(QString)),&testr,SLOT(set_time(QString)));
    //QObject::connect(&mai,SIGNAL(get_dscr(QString)),&testr,SLOT(set_dscr(QString)));



    mai.start();

    //testr.show();
    w.show();

    return a.exec();
}
