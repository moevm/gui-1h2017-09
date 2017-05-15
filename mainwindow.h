#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recipe.h"
#include "searchform.h"
#include "lastrepform.h"
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
    SearchForm* search;
    LastRepform* last_rep;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
