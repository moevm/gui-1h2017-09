#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recipewidget.h"
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
    void add_last_rep(RecipeWidget *);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
