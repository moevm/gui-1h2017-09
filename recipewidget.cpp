#include "recipewidget.h"
#include "ui_recipewidget.h"

#include <QDebug>


RecipeWidget::RecipeWidget(Recipe *l ,QWidget *parent, Qt::WindowFlags f) :QFrame(parent),
    ui(new Ui::RecipeWidget)
{
    ui->setupUi(this);
    connect(l,SIGNAL(get_descrs(QString)),this,SLOT(set_dscr(QString)));
    connect(l,SIGNAL(get_names(QString)),this,SLOT(set_name(QString)));
    connect(l,SIGNAL(get_times(QString)),this,SLOT(set_time(QString)));
     connect(l,SIGNAL(get_imgs(QString)),this,SLOT(set_pic(QString)));
}


RecipeWidget::RecipeWidget(QWidget *parent, Qt::WindowFlags f) :QFrame(parent),
    ui(new Ui::RecipeWidget)
{
    ui->setupUi(this);
    connect(ui->Button_open,SIGNAL(clicked(bool)),this,SLOT(clicked_open()));
}


void RecipeWidget::set_name(QString n){
    ui->label_name->setText(n);
    //qDebug() <<  this << "name  " << n ;
}
void RecipeWidget::set_time(QString n){
    ui->label_time->setText(n+  " мин");
    //qDebug() <<  this << "time  " << n ;
}
void RecipeWidget::set_dscr(QString n){
    ui->label_dscr->setText(n);
   // qDebug() <<  this << "dscr " << n ;
}

void RecipeWidget::set_pic(QString n){
   // RecipeWidget::void clicked_open();ui->label_dscr->setText(n);
}

void RecipeWidget::clicked_open(){
    open_full_widget();
}

RecipeWidget::~RecipeWidget()
{
    delete ui;
}
