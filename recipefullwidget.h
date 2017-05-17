#ifndef RECIPEFULLWIDGET_H
#define RECIPEFULLWIDGET_H

#include <QWidget>
#include <recipe.h>
#include <QPixmap>
namespace Ui {
class RecipeFullWidget;
}

class RecipeFullWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RecipeFullWidget(Recipe *,QWidget *parent = 0);
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
signals:
    void push_opened(int);


private:

    QPixmap *pic;
    int id;
    Ui::RecipeFullWidget *ui;
};

#endif // RECIPEFULLWIDGET_H
