#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scrollArea->setWidgetResizable(false);
     ui->scrollAreaWidgetContents->setFixedSize(1000, 1000);

}

void MainWindow::add_last_rep(RecipeWidget * k){
    ui->verticalLayout_last_rep->addWidget(k);
}

MainWindow::~MainWindow()
{
    delete ui;
}

