#ifndef CHANGERECIPEFORM_H
#define CHANGERECIPEFORM_H

#include <QFrame>
#include <QSignalMapper>
#include <QCheckBox>
#include "ingrlist.h"
namespace Ui {
class ChangeRecipeForm;
}

class ChangeRecipeForm : public QFrame
{
    Q_OBJECT

public:
    explicit ChangeRecipeForm(Ingredients *,QWidget *parent = 0);
    ~ChangeRecipeForm();
public slots:
    void set_name(QString n);
    void set_time(QString n);
    void set_dscr(QString n);
//    void set_pic(QString n);
    void set_ingr(QString n);
    void set_txt(QString n);

    void set_name_ingr(QString);
    //void chng_checkstate();
private slots:
    void clicked_new_ingr();
    void clicked_save();
    void chg_checkstate(int);
signals:
     void get_all_ingr();
     void new_name_ingr(QString);

     void get_name(QString n);
     void get_time(int);
     void get_dscr(QString n);
     //    void get_pic(QString n);
     void get_ingr(QString n);
     void get_txt(QString n);
     void get_delete_ingr(int);
     void get_add_ingr(int);

private:
     QSignalMapper *signalMapper;
     bool BasechgCheckState;

    Ingredients* ingrlist;
    QVector<QCheckBox *> name_ingr;

    QVector<int> del_ingr;
    QVector<int> add_ingr;

    Ui::ChangeRecipeForm *ui;
};

#endif // CHANGERECIPEFORM_H
