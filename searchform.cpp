#include "searchform.h"
#include "ui_searchform.h"

SearchForm::SearchForm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
     get_all_ingr();
}

void SearchForm::set_name_ingr(QString n){
    name_ingr.push_back(new QCheckBox(n,this));
    ui->verticalLayout_ingr->addWidget(name_ingr.last());
}

void SearchForm::clicked_search(){
    selected_end();
    select_name(ui->lineEdit_name->text());
    for(QCheckBox * i:name_ingr){
       //остановилась здесь, нужно  отправлять сигналы  ингредиентов, те которые отмечены галочкой

    }
    end_transact();
}


void SearchForm::add_found_rep(Recipe * l){
    //ui->verticalLayout_last_rep->addWidget(k);
    rep_w.push_back(new RecipeWidget(this));
    full_rep.push_back(new RecipeFullWidget());
    //для мини формата
    connect(l,SIGNAL(get_descrs(QString)),rep_w.last(),SLOT(set_dscr(QString)));
    connect(l,SIGNAL(get_names(QString)),rep_w.last(),SLOT(set_name(QString)));
    connect(l,SIGNAL(get_times(QString)),rep_w.last(),SLOT(set_dscr(QString)));
     connect(l,SIGNAL(get_imgs(QString)),rep_w.last(),SLOT(set_pic(QString)));


     //для полного формата
     connect(l,SIGNAL(get_descrs(QString)),full_rep.last(),SLOT(set_dscr(QString)));
     connect(l,SIGNAL(get_names(QString)),full_rep.last(),SLOT(set_name(QString)));
     connect(l,SIGNAL(get_times(QString)),full_rep.last(),SLOT(set_time(QString)));
      connect(l,SIGNAL(get_imgs(QString)),full_rep.last(),SLOT(set_pic(QString)));
      connect(l,SIGNAL(get_txts(QString)),full_rep.last(),SLOT(set_txt(QString)));
       connect(l,SIGNAL(get_ingrs(QString)),full_rep.last(),SLOT(set_ingr(QString)));

     //связь виджетов
       connect(rep_w.last(),SIGNAL(open_full_widget()),full_rep.last(),SLOT(show()));

     ui->verticalLayout_rep->addWidget(rep_w.last());
     //qDebug() << "init widget";
}


SearchForm::~SearchForm()
{
    delete ui;
}
