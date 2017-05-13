#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H
#include "lastrecipe.h"
#include <recipewidget.h>
#include <QObject>
#include <QVector>
#include "mainwindow.h"

class dataProcessing : public QObject
{
    Q_OBJECT
public:
    explicit dataProcessing(QObject *parent = 0);
    explicit dataProcessing(MainWindow * w,QObject *parent);
    ~dataProcessing();
     LastRecipe * last_rep;
     void start();
signals:
     void add_last_rep_to_layout(Recipe*);
     void get_name(QString);
     void get_time(QString);
     void get_dscr(QString);
public slots:
      void transfer_add_last(Recipe *);
private :
   // LastRecipe * last_rep;
};

#endif // DATAPROCESSING_H
