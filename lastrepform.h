#ifndef LASTREPFORM_H
#define LASTREPFORM_H

#include <QFrame>
#include <lastrecipe.h>
#include <recipewidget.h>
#include <recipefullwidget.h>

namespace Ui {
class LastRepform;
}

class LastRepform : public QFrame
{
    Q_OBJECT

public:
    explicit LastRepform(QWidget *parent = 0);
    ~LastRepform();
public slots:
   void add_last_rep(Recipe *);
signals:
   void get_last_rep();
private:
    LastRecipe *lrep;
    QVector <RecipeWidget *> last_w;
    QVector <RecipeFullWidget *> full_rep;
    Ui::LastRepform *ui;
};

#endif // LASTREPFORM_H
