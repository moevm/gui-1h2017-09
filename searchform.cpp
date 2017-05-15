#include "searchform.h"
#include "ui_searchform.h"

SearchForm::SearchForm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SearchForm)
{
     ui->setupUi(this);
    //инициализация
    //связь между списком ингредиентом
    search=new SearchRecipe();
    ingrlist=new Ingredients();
    connect(ingrlist,SIGNAL(get_ingrs(QString)),this,SLOT(set_name_ingr(QString)));
    connect(this,SIGNAL(get_all_ingr()),ingrlist,SLOT(get_all_ingr()));
    get_all_ingr();
      //связь между  поиском
     connect(search,SIGNAL(get_found_recipe(Recipe*)),this,SLOT(add_found_rep(Recipe*)));
     connect(this,SIGNAL(select_name(QString)),search,SLOT(set_name(QString)));
      connect(this,SIGNAL(select_time(QString)),search,SLOT(set_time(QString)));
      connect(this,SIGNAL(selected_ingr(QString)),search,SLOT(set_ingr(QString)));
      connect(this,SIGNAL(selected_end()),search,SLOT(start_search()));
      connect(this,SIGNAL(end_transact()),search,SLOT(end_transact()));


    ui->scrollArea_ingr->setWidgetResizable(false);
     ui->scrollArea_rep->setWidgetResizable(false);
     ui->scrollAreaWidgetContents_2->setFixedSize(170, 1000);
     ui->scrollAreaWidgetContents->setFixedSize(710, 2000);
     connect(ui->Button_search,SIGNAL(clicked()),this,SLOT(clicked_search()));




}

void SearchForm::set_name_ingr(QString n){
    name_ingr.push_back(new QCheckBox(n,this));
    ui->verticalLayout_ingr->addWidget(name_ingr.last());
}

void SearchForm::clicked_search(){
    for(RecipeWidget * i:rep_w)
     {
         delete i;
         rep_w.removeOne(i);
     }
    selected_end();
    select_name(ui->lineEdit_name->text());
    for(QCheckBox * i:name_ingr){
       //остановилась здесь, нужно  отправлять сигналы  ингредиентов, те которые отмечены галочкой
        //qDebug() << i->checkState();

        if(i->checkState()==Qt::Checked)
        {
            qDebug() << i->checkState();
            //отправляем сигнал с именем
            selected_ingr(i->text());
        }

    }
    end_transact();

    //удаляем найденные рецепты ранее


}


void SearchForm::add_found_rep(Recipe * l){
   // qDebug() << "slots add found";
    //ui->verticalLayout_last_rep->addWidget(k);
    rep_w.push_back(new RecipeWidget(this));
    full_rep.push_back(new RecipeFullWidget());
    //для мини формата
    connect(l,SIGNAL(get_descrs(QString)),rep_w.last(),SLOT(set_dscr(QString)));
    connect(l,SIGNAL(get_names(QString)),rep_w.last(),SLOT(set_name(QString)));
    connect(l,SIGNAL(get_times(QString)),rep_w.last(),SLOT(set_time(QString)));
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
