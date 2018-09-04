#ifndef LASTRECIPE_H
#define LASTRECIPE_H
#include <QVector>
#include <QString>
#include <QObject>
#include "recipe.h"
#include <recipewidget.h>


class LastRecipe : public QObject
{
        Q_OBJECT
    QSqlQuery query;
    QVector<Recipe*>lastrecipe;
    QVector<int> opened_recipe;
public:
     QVector<RecipeWidget*> recipe_w;
    bool Loaded;
    bool update_last();
    int get_cout_lastrecipe();
    Recipe* get_lastrecipe(int i);
    explicit LastRecipe(int last_n=3,QObject *parent = 0);
    ~LastRecipe();

 public slots:
   void  opened(int);
   void get_rep();
signals:
   void  get_last_recipe(Recipe *);
};

#endif // LASTRECIPE_H
