#include "recipefullwidget.h"
#include "ui_recipefullwidget.h"

RecipeFullWidget::RecipeFullWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::RecipeFullWidget)
{
    ui->setupUi(this);
}

RecipeFullWidget::RecipeFullWidget(Ingredients* ingrname_m, Recipe * l ,QWidget *parent) :
    QFrame(parent),
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

       //связывание кнопки изменения
       connect(ui->Button_chg,SIGNAL(clicked()),this,SLOT(clicked_change()));

       //форма изменения рецепта
       chng=new ChangeRecipeForm(ingrname_m,this);
       chng->setGeometry(0,0,this->geometry().width(),this->geometry().height());
       chng->setVisible(false);

       //соеденение с рецептом отображения основных полей без картинки и ингредиентов
       connect(l,SIGNAL(get_descrs(QString)),chng,SLOT(set_dscr(QString)));
       connect(l,SIGNAL(get_names(QString)),chng,SLOT(set_name(QString)));
       connect(l,SIGNAL(get_times(QString)),chng,SLOT(set_time(QString)));
        //connect(l,SIGNAL(get_imgs(QString)),chng,SLOT(set_pic(QString)));
        connect(l,SIGNAL(get_txts(QString)),chng,SLOT(set_txt(QString)));
         connect(l,SIGNAL(get_ingrs(QString)),chng,SLOT(set_ingr(QString)));

         //соедение на изменение данных в рецепте
        connect(chng,SIGNAL(get_delete_ingr(QString)),l,SLOT(set_del_ingr(QString)));
        connect(chng,SIGNAL(get_dscr(QString)),l,SLOT(set_descr(QString)));
        connect(chng,SIGNAL(get_name(QString)),l,SLOT(set_name(QString)));
        connect(chng,SIGNAL(get_time(int)),l,SLOT(set_time(int)));
        connect(chng,SIGNAL(get_add_ingr(QString)),l,SLOT(set_add_ingr(QString)));
        connect(chng,SIGNAL(get_txt(QString)),l,SLOT(set_text(QString)));
        //connect(chng,SIGNAL(get_pic(QString)),l,SLOT(set_img(QString)));

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


 void RecipeFullWidget::clicked_change(){
     chng->show();
 }
