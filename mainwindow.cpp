#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recipe.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    last_manager =new LastRecipe(0);
    ingrlist_manager=new Ingredients();

    search= new SearchForm(ingrlist_manager,last_manager,ui->frame_search);
    last_rep=new LastRepform(ingrlist_manager,last_manager,ui->frame_start);
    //ui->searchWidget->layout()->addWidget(search);
}



MainWindow::~MainWindow()
{
    delete ingrlist_manager;
    delete last_manager;
    delete ui;
}

