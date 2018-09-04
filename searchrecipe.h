#ifndef SEARCHRECIPE_H
#define SEARCHRECIPE_H
#include <QVector>
#include <QString>
#include <QtSql>
#include <QObject>
#include <recipe.h>
#include <ingrsearch.h>

class SearchRecipe : public QObject
{
   Q_OBJECT
        QSqlQuery query;
    QVector<Recipe *> search_rep;
    QString name;
    int time;
public:
    IngrSearch* ingr;
public slots:
    void set_name(QString);
    void set_time(QString);
    void set_ingr(QString);
    void start_search();
    void end_transact();
signals:
    void get_count(int);
    void get_found_recipe(Recipe *);
public:
    void reset();
    bool search();
     explicit SearchRecipe(QObject *parent = 0);
    ~SearchRecipe();
};

#endif // SEARCHRECIPE_H
