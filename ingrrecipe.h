#ifndef INGRRECIPE_H
#define INGRRECIPE_H
#include "ingrbase.h"

class IngrRecipe
{
private:
    QSqlQuery query;
   QVector<QString> ingr;
    int id_recipe;
    bool init(void);
public:
    IngrRecipe(int i);
    IngrRecipe(int i, QVector<QString> in);
    QString get_ingr(int i);
    int get_cout();
    void add_ingr(QString name);
    void delete_ingr(int i);
    void delete_ingr(QString name);
};

#endif // INGRRECIPE_H
