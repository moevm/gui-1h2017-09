#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recipe.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    search= new SearchForm(ui->frame_search);
    last_rep=new LastRepform(ui->frame_start);
    //ui->searchWidget->layout()->addWidget(search);


}



MainWindow::~MainWindow()
{
    delete ui;
}

