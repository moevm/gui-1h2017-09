#ifndef RECIPEFULLWIDGET_H
#define RECIPEFULLWIDGET_H

#include <QWidget>

namespace Ui {
class RecipeFullWidget;
}

class RecipeFullWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RecipeFullWidget(QWidget *parent = 0);
    ~RecipeFullWidget();

private:
    Ui::RecipeFullWidget *ui;
};

#endif // RECIPEFULLWIDGET_H
