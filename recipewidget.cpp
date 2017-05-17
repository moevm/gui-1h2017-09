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

     connect(ui->Button_open,SIGNAL(clicked(bool)),this,SLOT(clicked_open()));
}


RecipeWidget::RecipeWidget(QWidget *parent, Qt::WindowFlags f) :QFrame(parent),
    ui(new Ui::RecipeWidget)
{
    ui->setupUi(this);
    connect(ui->Button_open,SIGNAL(clicked(bool)),this,SLOT(clicked_open()));
}


void RecipeWidget::set_name(QString n){
    ui->label_name->setText(n);
}
void RecipeWidget::set_time(QString n){
    ui->label_time->setText(n+  " мин");
}
void RecipeWidget::set_dscr(QString n){
    ui->label_dscr->setText(n);
}

void RecipeWidget::set_pic(QString n){
    pic=new QPixmap();
    if(!pic->load(n)){
        pic->load("i_default.jpg");
    }

   ui->label_pic->setPixmap(*pic);
}

void RecipeWidget::clicked_open(){
    open_full_widget();
}

RecipeWidget::~RecipeWidget()
{
    delete ui;
}
