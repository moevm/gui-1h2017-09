#include "newrecipeform.h"
#include "ui_newrecipeform.h"
#include <QDebug>
#include <QLabel>

NewRecipeform::NewRecipeform(Ingredients* ingrname_m,QWidget *parent) :
    QFrame(parent),
    ui(new Ui::NewRecipeform)
{
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

    ui->scrollArea_ingr->setWidgetResizable(false);
     ui->scrollAreaWidgetContents_2->setFixedSize(200, 1000);

     //связывание изменения состояния  чекбоксов

}


void NewRecipeform::clicked_save(){
    if(ui->lineEdit_name->text()!=""){
    get_dscr(ui->lineEdit_dscr->text());
    get_name(ui->lineEdit_name->text());
    get_time(ui->lineEdit_time->text().toInt());
    get_txt(ui->lineEdit_txt->text());
    //get_pic();
    for(QCheckBox *  i:name_ingr){
        if(i->checkState()==Qt::Checked){
            get_ingr(i->text());
        }
         //  qDebug() << "Удалить " << name_ingr[i]->text();
        //get_delete_ingr(name_ingr[i]->text());
    }
     end_transact();
     QLabel *yes=new QLabel("Рецепт добавлен");
     yes->setGeometry(500,500,300,50);
     yes->setAlignment(Qt::AlignCenter);
    yes->show();
    //this->setVisible(false);
    }else{
        QLabel *yes=new QLabel("Ошибка: имя не должно быть пустым!");
        yes->setGeometry(500,500,300,50);
        yes->setAlignment(Qt::AlignCenter);
       yes->show();
    }
}




void NewRecipeform::set_name_ingr(QString n){
    name_ingr.push_back(new QCheckBox(n,this));
    ui->verticalLayout_ingr->addWidget(name_ingr.last());

    //connect(name_ingr.last(),SIGNAL(clicked()),signalMapper,SLOT(map()));
   // signalMapper->setMapping(name_ingr.last(),name_ingr.size()-1);
}

void NewRecipeform::clicked_new_ingr(){
    new_name_ingr(ui->lineEdit_newingr->text());
    ui->lineEdit_newingr->setText("");
}

NewRecipeform::~NewRecipeform()
{
    delete ui;
}
