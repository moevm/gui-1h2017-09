#include "recipefullwidget.h"
#include "ui_recipefullwidget.h"

RecipeFullWidget::RecipeFullWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecipeFullWidget)
{
    ui->setupUi(this);
}

RecipeFullWidget::~RecipeFullWidget()
{
    delete ui;
}

void RecipeFullWidget::set_name(QString n){
    ui->label_name->setText(n);
}
void RecipeFullWidget::set_time(QString n){
    ui->label_time->setText(n + " мин");
}
void RecipeFullWidget::set_dscr(QString n){
    ui->label_dscr->setText(n);
}

void RecipeFullWidget::set_pic(QString n){
   // ui->label_dscr->setText(n);
}
void RecipeFullWidget::set_txt(QString n){
    ui->label_text->setText(n);
}

void RecipeFullWidget::set_ingr(QString n){
    ui->listWidget_name_ingr->addItem(n);
}

 void RecipeFullWidget::open_widget(){
     this->show();
 }
