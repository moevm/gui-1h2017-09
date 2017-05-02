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
    query.prepare("Select * from recipe where name like :n and time < :t");
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
        query.bindValue(":n",999999);
    }


    //запрос должен выдать уже столбцы всех подходящих рецептов



    return false;
}
void SearchRecipe::reset(){
    time=0;
    name="";
    for(int i=0;i<=ingr->get_cout();i++){
        ingr->delete_ingr(i);
    }
    for( Recipe * i: search_rep)
    {
        delete i;
    }
}
