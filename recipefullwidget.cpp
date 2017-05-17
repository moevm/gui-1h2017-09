#include "recipefullwidget.h"
#include "ui_recipefullwidget.h"

RecipeFullWidget::RecipeFullWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecipeFullWidget)
{
    ui->setupUi(this);
}

RecipeFullWidget::RecipeFullWidget(Recipe * l ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecipeFullWidget)
{
    ui->setupUi(this);
    connect(l,SIGNAL(get_descrs(QString)),this,SLOT(set_dscr(QString)));
    connect(l,SIGNAL(get_names(QString)),this,SLOT(set_name(QString)));
    connect(l,SIGNAL(get_times(QString)),this,SLOT(set_time(QString)));
     connect(l,SIGNAL(get_imgs(QString)),this,SLOT(set_pic(QString)));
     connect(l,SIGNAL(get_txts(QString)),this,SLOT(set_txt(QString)));
      connect(l,SIGNAL(get_ingrs(QString)),this,SLOT(set_ingr(QString)));
       connect(l,SIGNAL(get_ids(int)),this,SLOT(set_id(int)));

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
    pic=new QPixmap();
    if(!pic->load(n)){
        pic->load("i_default.jpg");
    }

   ui->label_pic->setPixmap(*pic);
}
void RecipeFullWidget::set_txt(QString n){
    ui->label_text->setText(n);
}

void RecipeFullWidget::set_ingr(QString n){
    ui->listWidget_name_ingr->addItem(n);
}
void RecipeFullWidget::set_id(int i)
{
    id=i;
}
 void RecipeFullWidget::open_widget(){
     this->show();
     push_opened(id);
 }
