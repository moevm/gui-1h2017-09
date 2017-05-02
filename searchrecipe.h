#ifndef SEARCHRECIPE_H
#define SEARCHRECIPE_H
#include <QVector>
#include <QString>
#include <QtSql>
#include <recipe.h>
#include <ingrsearch.h>

class SearchRecipe
{
        QSqlQuery query;
    QVector<Recipe *> search_rep;
    QString name;
    int time;
    IngrSearch* ingr;
public:
    void set_name(QString n);
    void set_time(int t);
    bool search();
    void reset();
    SearchRecipe();
};

#endif // SEARCHRECIPE_H
