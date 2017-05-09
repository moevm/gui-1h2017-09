#include "dataprocessing.h"
#include <QtSql>
#include <QDebug>

dataProcessing::dataProcessing(QObject *parent) : QObject(parent)
{
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("mybd.sqlite");
    if (!dbase.open()) {
        qDebug() << "Dont open db";

    }else
    {
        qDebug() << "Open db";
        last_rep=new LastRecipe(5);
    }
}

void dataProcessing::start(){

    if (last_rep)
    {
        for(RecipeWidget * i:last_rep->recipe_w)
        {
            add_last_rep_to_layout(i);
        }
        //get_name(last_rep->get_lastrecipe(0)->get_name());
        //get_time(QString::number(last_rep->get_lastrecipe(0)->get_time()));
        //get_dscr(last_rep->get_lastrecipe(0)->get_descr());
    }


}

dataProcessing::~dataProcessing(){
  if(!last_rep) {
        delete last_rep;
    }
}

