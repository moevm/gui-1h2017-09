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
public slots:
    void set_name(QString n);
    void set_time(QString n);
    void set_dscr(QString n);
    void set_pic(QString n);
    void set_ingr(QString n);
    void set_txt(QString n);
    void open_widget();


private:
    Ui::RecipeFullWidget *ui;
};

#endif // RECIPEFULLWIDGET_H
