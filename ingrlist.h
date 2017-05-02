#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include "ingrbase.h"


class Ingredients {//пока только для  основных ингредиентов.
private:
    QSqlQuery query;
   QVector<QString> ingr;
    bool init(void);

public:
    void add_ingr(QString name);
    void delete_ingr(QString name);
     void delete_ingr(int i);
    QString get_ingr(int i);
    int get_cout();
    Ingredients();
};
#endif // INGREDIENTS_H
