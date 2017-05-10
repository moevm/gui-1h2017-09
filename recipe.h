#ifndef RECIPE_H
#define RECIPE_H
#include <QObject>
#include <QVector>
#include <QString>
#include <QtSql>
#include "ingrrecipe.h"

class Recipe :public QObject{
    Q_OBJECT
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
    explicit  Recipe(QSqlQuery *query,QObject *parent = 0);//скачивает с помощью query в текущей позиции
     explicit Recipe(int idd,QString nm, QString d,int t,QString i,QString txt,QObject *parent = 0);//создает уже существующий рецепт, добавляет сам свои ингр
     explicit Recipe(QString nm, QString d,int t,QString i,QString txt,QVector<QString> in,QObject *parent = 0);//создает новый

    QString get_name();
    QString get_descr();
    QString get_img();
    QString get_txt();
    void init_signals();
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


signals:
    void get_names( QString );
    void get_descrs(QString);
    void get_imgs(QString);
    void get_txts(QString );
    void get_ingrs(QString);
    void get_times(QString);
    void init_widgets(Recipe *);
};


#endif // RECIPE_H
