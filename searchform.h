#ifndef SEARCHFORM_H
#define SEARCHFORM_H
#include "recipe.h"
#include "recipefullwidget.h"
#include "recipewidget.h"
#include "ingrlist.h"
#include "lastrecipe.h"
#include "searchrecipe.h"
#include <QVector>
#include <QFrame>
#include <QString>
#include <QCheckBox>
namespace Ui {
class SearchForm;
}

class SearchForm : public QFrame
{
    Q_OBJECT

public:
    explicit SearchForm(Ingredients* ingrname_m, LastRecipe * last_m,QWidget *parent = 0);
    explicit SearchForm(QWidget *parent = 0);
    ~SearchForm();
public slots:
    void set_name_ingr(QString);
    void add_found_rep(Recipe *);
    void clicked_search();
    void get_count(int);
signals:
    void selected_ingr(QString);
    void select_name(QString);
    void select_time(QString);
    void get_all_ingr();
    void selected_end();
    void end_transact();

private:
    LastRecipe * last_manager;
    Ingredients* ingrlist;
    Ingredients * ingrlist_manager;
    SearchRecipe* search;
    QVector<QCheckBox *> name_ingr;
    QVector<RecipeWidget *> rep_w;
    QVector<RecipeFullWidget *> full_rep;
    Ui::SearchForm *ui;
};

#endif // SEARCHFORM_H
