#ifndef NEWRECIPEFORM_H
#define NEWRECIPEFORM_H

#include <QFrame>
#include <QCheckBox>
#include "ingrlist.h"
namespace Ui {
class NewRecipeform;
}

class NewRecipeform : public QFrame
{
    Q_OBJECT

public:
    explicit NewRecipeform(Ingredients *,QWidget *parent = 0);
    ~NewRecipeform();
public slots:


    void set_name_ingr(QString);
    //void chng_checkstate();
private slots:
    void clicked_new_ingr();
    void clicked_save();

signals:
     void get_all_ingr();
     void new_name_ingr(QString);

     void get_name(QString n);
     void get_time(int);
     void get_dscr(QString n);
     //    void get_pic(QString n);
     void get_ingr(QString n);
     void get_txt(QString n);

     void end_transact();


private:
    Ingredients* ingrlist;
    QVector<QCheckBox *> name_ingr;

    Ui::NewRecipeform *ui;
};
#endif // NEWRECIPEFORM_H
