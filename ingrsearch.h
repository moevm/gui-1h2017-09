#ifndef SEARCHINGR_H
#define SEARCHINGR_H

#include "ingrbase.h"

class IngrSearch
{
private:
     QSqlQuery query;
    QVector<QString> ingr;
     bool init(void);
public:
    void add_ingr(QString name);
    void delete_ingr(QString name);
    void delete_ingr(int i);
    QString get_ingr(int i);
    int get_cout();
public:
    IngrSearch();
};

#endif // SEARCHINGR_H
