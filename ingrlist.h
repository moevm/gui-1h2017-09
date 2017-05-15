#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include "ingrbase.h"
#include <QObject>

class Ingredients :public QObject{//пока только для  основных ингредиентов.
    Q_OBJECT
private:
    QSqlQuery query;
   QVector<QString> ingr;
    bool init(void);

public:
    bool Loaded;
    void add_ingr(QString name);
    void delete_ingr(QString name);
     void delete_ingr(int i);
    QString get_ingr(int i);
    int get_cout();
    explicit Ingredients(QObject *parent = 0);
public slots:
    void get_all_ingr();
signals:
    void get_ingrs(QString);
};
#endif // INGREDIENTS_H
