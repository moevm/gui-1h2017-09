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
     void start();
signals:

public slots:

private :
   // LastRecipe * last_rep;
};

#endif // DATAPROCESSING_H
