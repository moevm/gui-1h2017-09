#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recipe.h"
#include "ingrlist.h"
#include "searchform.h"
#include "lastrepform.h"
#include "lastrecipe.h"
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

private:
    Ingredients* ingrlist_manager;
    LastRecipe* last_manager;
    SearchForm* search;
    LastRepform* last_rep;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
