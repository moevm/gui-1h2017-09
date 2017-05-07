#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H
#include "recipe.h"
#include <QObject>

class dataProcessing:public QObject
{
public:
    Q_OBJECT
    explicit dataProcessing(QObject *parent = 0);
 //   ~dataProcessing();
private:
    Recipe *newRecipe;
};

#endif // DATAPROCESSING_H
