#include "changerecipeform.h"
#include "ui_changerecipeform.h"
#include <QDebug>

ChangeRecipeForm::ChangeRecipeForm(Ingredients* ingrname_m,QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ChangeRecipeForm)
{
    BasechgCheckState=false;
    ui->setupUi(this);
    //связывает кнопки
    connect(ui->pushButton_save,SIGNAL(clicked()),this,SLOT(clicked_save()));
    connect(ui->pushButton_newingr,SIGNAL(clicked()),this,SLOT(clicked_new_ingr()));

    //связываение  листом ингредиентов
    ingrlist=new Ingredients();
    connect(ingrlist,SIGNAL(get_ingrs(QString)),this,SLOT(set_name_ingr(QString)));
    connect(this,SIGNAL(get_all_ingr()),ingrlist,SLOT(get_all_ingr()));

    //для рассылки новых имен
    connect(ingrname_m,SIGNAL(get_ingrs(QString)),this,SLOT(set_name_ingr(QString)));
    connect(this,SIGNAL(new_name_ingr(QString)),ingrname_m,SLOT(add_ingr(QString)));
    get_all_ingr();


    //для определения новых и ненужных ингр для рецепта
    signalMapper=new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)),this, SLOT(chg_checkstate(int)));


    ui->scrollArea_ingr->setWidgetResizable(false);
     ui->scrollAreaWidgetContents_2->setFixedSize(200, 1000);

     //связывание изменения состояния  чекбоксов

}

 void ChangeRecipeForm::chg_checkstate(int i){
     //передан объект у которого изменилось состояние
     //определяем его данное состояния
     int state=name_ingr[i]->checkState();
     if(state==Qt::Checked){
         if(add_ingr.indexOf(i)==-1){
             del_ingr.push_back(i);

         }else{
             add_ingr.removeOne(i);
         }
     }else{
         if(del_ingr.indexOf(i)==-1){
             add_ingr.push_back(i);

         }else{
             del_ingr.removeOne(i);
         }
     }
 }


void ChangeRecipeForm::clicked_save(){
    get_dscr(ui->lineEdit_dscr->text());
    get_name(ui->lineEdit_name->text());
    get_time(ui->lineEdit_time->text().toInt());
    get_txt(ui->lineEdit_txt->text());
    //get_pic();
    for(int  i:del_ingr){
           qDebug() << "Удалить " << name_ingr[i]->text();
        //get_delete_ingr(name_ingr[i]->text());
    }

    for(int  i:add_ingr){
        qDebug() << "Добавить " << name_ingr[i]->text();
        //get_add_ingr(name_ingr[i]->text());
    }
    this->setVisible(false);
}


void ChangeRecipeForm::set_name(QString n){
    ui->lineEdit_name->setText(n);
}
void ChangeRecipeForm::set_time(QString n){
    ui->lineEdit_time->setText(n);
}
void ChangeRecipeForm::set_dscr(QString n){
    ui->lineEdit_dscr->setText(n);
}
//    void set_pic(QString n);
    void ChangeRecipeForm::set_ingr(QString n){
        for(QCheckBox * i:name_ingr){
            if(i->text()==n){
                BasechgCheckState=true;
                i->setCheckState(Qt::Checked);
                BasechgCheckState=false;
                break;
            }
        }


    }
void ChangeRecipeForm::set_txt(QString n){
    ui->lineEdit_txt->setText(n);
}

void ChangeRecipeForm::set_name_ingr(QString n){
    name_ingr.push_back(new QCheckBox(n,this));
    ui->verticalLayout_ingr->addWidget(name_ingr.last());

    //connect(name_ingr.last(),SIGNAL(clicked()),signalMapper,SLOT(map()));
   // signalMapper->setMapping(name_ingr.last(),name_ingr.size()-1);
}

void ChangeRecipeForm::clicked_new_ingr(){
    new_name_ingr(ui->lineEdit_newingr->text());
    ui->lineEdit_newingr->setText("");
}

ChangeRecipeForm::~ChangeRecipeForm()
{
    delete ui;
}
