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
        last_rep=new LastRecipe();
        //инициализируем сигналы пока здесь
        //connect(last_rep->get_lastrecipe(i),SIGNAL(init_widgets(Recipe*)),w,SLOT(add_last_rep(Recipe*)));
        for(int i=0;i<last_rep->get_cout_lastrecipe();i++){

            qDebug() <<  "start" << i;
            //connect(last_rep->get_lastrecipe(i),SIGNAL(init_widgets(Recipe*)),this,SLOT(transfer_add_last(Recipe*)));
             connect(last_rep->get_lastrecipe(i),SIGNAL(init_widgets(Recipe*)),w,SLOT(add_last_rep(Recipe*)));
            last_rep->get_lastrecipe(i)->init_signals();
        }
    }
}


dataProcessing::dataProcessing(QObject *parent) : QObject(parent)
{

}


void dataProcessing::transfer_add_last(Recipe *r ){
    //qDebug() << "Tranfer" ;
    add_last_rep_to_layout(r);
}
void dataProcessing::start(){

    if (last_rep)
    {
        for(RecipeWidget * i:last_rep->recipe_w)
        {
           // add_last_rep_to_layout(i);
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

