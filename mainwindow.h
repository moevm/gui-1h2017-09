#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recipewidget.h"
#include "recipefullwidget.h"
#include "recipe.h"
#include "searchform.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

 public slots:
    void add_last_rep(Recipe *);
private:
    SearchForm* search;
    QVector <RecipeWidget *> last_w;
    QVector <RecipeFullWidget *> full_rep;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
