#ifndef LASTRECIPE_H
#define LASTRECIPE_H
#include <QVector>
#include <QString>
#include "recipe.h"
#include <recipewidget.h>


class LastRecipe
{
    QSqlQuery query;
    QVector<Recipe*>lastrecipe;
    QVector<int> opened_recipe;
    public:
     QVector<RecipeWidget*> recipe_w;
    bool Loaded;
    bool update_last();
    void push_opened(int i);
    int get_cout_lastrecipe();
    Recipe* get_lastrecipe(int i);
    LastRecipe(int last_n);
    ~LastRecipe();
};

#endif // LASTRECIPE_H
