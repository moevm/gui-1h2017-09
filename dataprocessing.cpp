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

    }
}



void dataProcessing::set_name(QString nm){
    name=nm;
}
void dataProcessing::set_descr(QString descr){
    dscr=descr;
}

void dataProcessing::set_text(QString txt){
    text=txt;
}
void dataProcessing::set_time(int t){
    time=t;
}
void dataProcessing::set_ingr(QString ing){
    ingr.push_back(ing);
}

void dataProcessing::end_transact(){
       Recipe *p=new Recipe(name,dscr,time,"",text,ingr);
       delete p;
}
dataProcessing::~dataProcessing(){

}

