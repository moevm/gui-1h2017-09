#ifndef RECIPEWIDGET_H
#define RECIPEWIDGET_H

#include <QFrame>
#include <QWidget>

namespace Ui {
class RecipeWidget;
}

class RecipeWidget : public QFrame
{
    Q_OBJECT

public:
     explicit RecipeWidget( QString name,QString time,QString dscr,QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~RecipeWidget();
public slots:
    void set_name(QString n);
    void set_time(QString n);
    void set_dscr(QString n);
private:
    Ui::RecipeWidget *ui;
};

#endif // RECIPEWIDGET_H
