#include "searchrecipe.h"

SearchRecipe::SearchRecipe()
{
    name="";
    time=0;
    ingr = new IngrSearch();

}

void SearchRecipe::set_name(QString n){
    name=n;
}
void SearchRecipe::set_time(int t){
    time=t;
}
bool SearchRecipe::search(){
    //обработка по ингредиентам
    QString str_sel_ingr="";
    if(ingr->get_cout()!=0)
    {
        str_sel_ingr=("and id in (select id_rep from ingredients where %1 group by id_rep having count(*)=%2)");
        QString name_col=" name_ingr like ";
        QString oper=" or ";
        QString ing="";
        for(int i=0;i<ingr->get_cout();i++)
        {
            if(i!=0)
            {
                ing+=oper;
            }
            ing+=name_col;
            ing+="'"+ingr->get_ingr(i)+"'";
        }


         str_sel_ingr=str_sel_ingr.arg(ing)
                 .arg(ingr->get_cout());
         //query.bindValue(":filtr_ingr",str_sel_ingr);
    }else{
       //query.bindValue(":filtr_ingr",1);
    }




    query.prepare("Select * from recipe where name like :n and time <= :t "+str_sel_ingr);// :filtr_ingr
    //обработка по времени и имени
    if(name!="")
    {
        query.bindValue(":n",name);
    }else{
        query.bindValue(":n","%");
    }

    if(time!=0)
    {

        query.bindValue(":t",time);
    }else{
        query.bindValue(":t",(int)9999);
    }





    /*query.prepare("Select * from recipe where name like :n and time <= :t"); //версия 1
    if(name!="")
    {
        query.bindValue(":n",name);
    }else{
        query.bindValue(":n","%");
    }

    if(time!=0)
    {

        query.bindValue(":t",time);
    }else{
        query.bindValue(":t",(int)9999);
    }

*/
    //запрос должен выдать уже столбцы всех подходящих рецептов
    if(query.exec()){
        while(query.next()){
            search_rep.push_back(new Recipe(&query));
        }
        return true;
    }else{
        qDebug() << "Error search\n";
        return false;
    }
    return true;
}
void SearchRecipe::reset(){
    time=0;
    name="";
    for(int i=ingr->get_cout()-1;i>=0;i--){
        ingr->delete_ingr(i);
    }
    for(int i=search_rep.size()-1;i>=0;i--){
        delete search_rep.value(i);
        search_rep.remove(i);
    }
}

SearchRecipe::~SearchRecipe(){
    reset();
}
