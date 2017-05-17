#include "lastrecipe.h"
LastRecipe::LastRecipe(int last_n,QObject *parent): QObject(parent)
{
    query.prepare("SELECT * FROM last_recipe INNER JOIN recipe ON last_recipe.id_rep = recipe.id ORDER BY inc DESC LIMIT :count");
    query.bindValue(":count",QString::number(last_n));

    if(query.exec())
    {
        Loaded=true;
        while(query.next())
        {
            qDebug() << "Init recipe";
            lastrecipe.push_back(new Recipe(&query));
           // qDebug() << "Init recipe widget";
           // recipe_w.push_back(new RecipeWidget(lastrecipe.last()->get_name(),QString::number(lastrecipe.last()->get_time()),lastrecipe.last()->get_descr()));
        }

    }else{
        Loaded=false;
         qDebug() << "Error: SELECT last recipe \n";
    }
}
bool LastRecipe::update_last(){
    //удалить те, которые есть

    for(int i:opened_recipe)
    {
        query.prepare("DELETE FROM Last_recipe WHERE id_rep=:id");
        query.bindValue(":id",i);
        if(!query.exec())
        {
            qDebug() << "Error: " << i << "del in last rep\n";
            return false;
        }else{
            query.prepare("INSERT INTO Last_recipe (id_rep) VALUES (:id)");
            query.bindValue(":id",i);
            query.exec();
            return true;
        }
    }

    //добавить из в конец
     /*query.prepare("INSERT INTO Lasr_recipe (id_rep) VALUES (:id)");
     for(int i:opened_recipe)
     {
         query.bindValue(":id",i);
         if(!query.exec())
         {
             qDebug() << "Error: " << i << "insert in last rep\n";
             return false;
         }
     }*/
     return true;
}



int LastRecipe::get_cout_lastrecipe(){
    return lastrecipe.size();
}

void LastRecipe::opened(int i){
    if(opened_recipe.indexOf(i)!=-1){
         opened_recipe.remove(opened_recipe.indexOf(i));
    }
    opened_recipe.push_back(i);
}

Recipe* LastRecipe::get_lastrecipe(int i){
    return lastrecipe[i];
}

void LastRecipe::get_rep(){
    for(Recipe *i:lastrecipe){
        get_last_recipe(i);
        i->init_signals();
    }
}

LastRecipe::~LastRecipe(){
   // qDebug() << "Зашел в конструктор";
    update_last();
    for(Recipe * i :lastrecipe)
        delete i;
    for(RecipeWidget * i :recipe_w)
        delete i;
}
