#ifndef RECIPE_H
#define RECIPE_H
#include <QVector>
#include <QString>
#include <QtSql>
#include "ingrrecipe.h"

class Recipe{
private:
    QSqlQuery query;
    int id;
    int time;
    QString name;
    QString descr;
    QString img;
    QString text;
public:
    IngrRecipe* ingr;
    void get_id();
    Recipe(QSqlQuery *query);//скачивает с помощью query в текущей позиции
    Recipe(int idd,QString nm, QString d,int t,QString i,QString txt);//создает уже существующий рецепт, добавляет сам свои ингр
    Recipe(QString nm, QString d,int t,QString i,QString txt,QVector<QString> in);//создает новый
    QString get_name();
    QString get_descr();
    QString get_img();
    QString get_txt();
    int get_time();

    bool set_name(QString nm);
    bool set_descr(QString descr);
    bool set_img(QString img);
    bool set_text(QString txt);
    bool set_time(int t);

    bool set_descr();
    bool set_img();
    bool set_text();
    bool set_time();

    bool del_recipe();

    ~Recipe();
};


#endif // RECIPE_H
