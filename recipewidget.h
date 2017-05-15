#ifndef RECIPEWIDGET_H
#define RECIPEWIDGET_H

#include <QFrame>
#include <QWidget>
#include <recipe.h>
namespace Ui {
class RecipeWidget;
}

class RecipeWidget : public QFrame
{
    Q_OBJECT

public:
     explicit RecipeWidget( Recipe * p,QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
     explicit RecipeWidget(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~RecipeWidget();
public slots:
    void set_name(QString n);
    void set_time(QString n);
    void set_dscr(QString n);
    void set_pic(QString n);
    void clicked_open();
signals:
    void open_full_widget();
private:
    Ui::RecipeWidget *ui;
};

#endif // RECIPEWIDGET_H
