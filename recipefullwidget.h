#ifndef RECIPEFULLWIDGET_H
#define RECIPEFULLWIDGET_H

#include <QFrame>
#include "recipe.h"
#include "changerecipeform.h"
#include <QPixmap>
namespace Ui {
class RecipeFullWidget;
}

class RecipeFullWidget : public QFrame
{
    Q_OBJECT

public:
    explicit RecipeFullWidget(Ingredients* ingrname_m,Recipe *,QWidget *parent = 0);
        explicit RecipeFullWidget(QWidget *parent = 0);
    ~RecipeFullWidget();
public slots:
    void set_name(QString n);
    void set_time(QString n);
    void set_dscr(QString n);
    void set_pic(QString n);
    void set_ingr(QString n);
    void set_txt(QString n);
    void set_id(int);
    void open_widget();
    void clicked_change();
signals:
    void push_opened(int);


private:
    ChangeRecipeForm * chng;
    QPixmap *pic;
    int id;
    Ui::RecipeFullWidget *ui;
};

#endif // RECIPEFULLWIDGET_H
