#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recipe.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scrollArea->setWidgetResizable(false);
     ui->scrollAreaWidgetContents->setFixedSize(1000, 1000);

    search= new SearchForm(ui->frame);
    //ui->searchWidget->layout()->addWidget(search);


}

void MainWindow::add_last_rep(Recipe * l){
    //ui->verticalLayout_last_rep->addWidget(k);
    last_w.push_back(new RecipeWidget(this));
    full_rep.push_back(new RecipeFullWidget());
    //для мини формата
    connect(l,SIGNAL(get_descrs(QString)),last_w.last(),SLOT(set_dscr(QString)));
    connect(l,SIGNAL(get_names(QString)),last_w.last(),SLOT(set_name(QString)));
    connect(l,SIGNAL(get_times(QString)),last_w.last(),SLOT(set_dscr(QString)));
     connect(l,SIGNAL(get_imgs(QString)),last_w.last(),SLOT(set_pic(QString)));


     //для полного формата
     connect(l,SIGNAL(get_descrs(QString)),full_rep.last(),SLOT(set_dscr(QString)));
     connect(l,SIGNAL(get_names(QString)),full_rep.last(),SLOT(set_name(QString)));
     connect(l,SIGNAL(get_times(QString)),full_rep.last(),SLOT(set_time(QString)));
      connect(l,SIGNAL(get_imgs(QString)),full_rep.last(),SLOT(set_pic(QString)));
      connect(l,SIGNAL(get_txts(QString)),full_rep.last(),SLOT(set_txt(QString)));
       connect(l,SIGNAL(get_ingrs(QString)),full_rep.last(),SLOT(set_ingr(QString)));

     //связь виджетов
       connect(last_w.last(),SIGNAL(open_full_widget()),full_rep.last(),SLOT(show()));

     ui->verticalLayout_last_rep->addWidget(last_w.last());
     //qDebug() << "init widget";
}

MainWindow::~MainWindow()
{
    delete ui;
}

