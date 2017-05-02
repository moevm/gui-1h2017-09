#ifndef LASTRECIPE_H
#define LASTRECIPE_H
#include <QVector>
#include <QString>
#include "recipe.h"


class LastRecipe
{
    QSqlQuery query;
    QVector<Recipe*>lastrecipe;
    QVector<int> opened_recipe;
    public:
    bool update_last();
    void push_opened(int i);
    int get_cout_lastrecipe();
    Recipe* get_lastrecipe(int i);
    LastRecipe(int last_n);
};

#endif // LASTRECIPE_H
