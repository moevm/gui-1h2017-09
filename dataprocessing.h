#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H
#include "lastrecipe.h"
#include <recipewidget.h>
#include <QObject>
#include <QVector>
#include "mainwindow.h"
#include "recipe.h"

class dataProcessing : public QObject
{
    Q_OBJECT
public:
    dataProcessing(QObject *parent = 0);

    ~dataProcessing();
     void start();
signals:

public slots:
     void set_name(QString nm);
     void set_descr(QString descr);

     void set_text(QString txt);
     void set_time(int t);
     void set_ingr(QString ing);
     void end_transact();

private :
     QString name;
     QString dscr;
     int time;
     QString text;
     QVector<QString> ingr;
   // LastRecipe * last_rep;
};

#endif // DATAPROCESSING_H
