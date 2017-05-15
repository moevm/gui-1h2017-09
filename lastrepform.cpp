#include "lastrepform.h"
#include "ui_lastrepform.h"

LastRepform::LastRepform(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::LastRepform)
{
    ui->setupUi(this);
    lrep=new LastRecipe();
    connect(lrep,SIGNAL(get_last_recipe(Recipe*)),this,SLOT(add_last_rep(Recipe*)));
    connect(this,SIGNAL(get_last_rep()),lrep,SLOT(get_rep()));
    get_last_rep();

    ui->scrollArea->setWidgetResizable(false);
     ui->scrollAreaWidgetContents->setFixedSize(700,1000);

}

void LastRepform::add_last_rep(Recipe * l){
    last_w.push_back(new RecipeWidget(l,this));
    full_rep.push_back(new RecipeFullWidget(l));
    //связь виджетов
    connect(last_w.last(),SIGNAL(open_full_widget()),full_rep.last(),SLOT(show()));
     ui->verticalLayout_last_rep->addWidget(last_w.last());

}



LastRepform::~LastRepform()
{
    delete lrep;
    for(RecipeWidget * i :last_w)
        delete i;
    for(RecipeFullWidget * i :full_rep)
        delete i;
    delete ui;
}
