#include "recipewidget.h"
#include "ui_recipewidget.h"



RecipeWidget::RecipeWidget( QString name,QString time,QString dscr,QWidget *parent, Qt::WindowFlags f) :QFrame(parent),
    ui(new Ui::RecipeWidget)
{
    ui->setupUi(this);
    ui->label_name->setText(name);
    ui->label_time->setText(time + " мин");
    ui->label_dscr->setText(dscr);
}


void RecipeWidget::set_name(QString n){
    ui->label_name->setText(n);
}
void RecipeWidget::set_time(QString n){
    ui->label_time->setText(n);
}
void RecipeWidget::set_dscr(QString n){
    ui->label_dscr->setText(n);
}



RecipeWidget::~RecipeWidget()
{
    delete ui;
}
