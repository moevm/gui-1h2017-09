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

    bool set_descr();
    bool set_img();
    bool set_text();
    bool set_time();
    bool del_recipe();

    ~Recipe();
public slots:
    void set_name(QString nm);
    void set_descr(QString descr);
    void set_img(QString img);
    void set_text(QString txt);
    void set_time(int t);
    void set_del_ingr(QString i);
    void set_add_ingr(QString i);

signals:
    void get_names( QString );
    void get_descrs(QString);
    void get_imgs(QString);
    void get_txts(QString );
    void get_ingrs(QString);
    void get_times(QString);
    void get_ids(int);
    void init_widgets(Recipe *);
};


#endif // RECIPE_H
