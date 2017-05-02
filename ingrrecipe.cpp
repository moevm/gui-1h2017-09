#include "ingrrecipe.h"

bool IngrRecipe::init(void){
    query.prepare("SELECT name_ingr FROM Ingredients WHERE id_rep= :id");
    query.bindValue(":id",id_recipe);
    if(!query.exec())
    {
        qDebug() <<"Error: rep " <<  id_recipe <<  " init ingr\n";
        return false;
    }else
    {
        while(query.next())
        {
            QSqlRecord rec = query.record();
            ingr.push_back(query.value(rec.indexOf("name_ingr")).toString());
        }
        qDebug() << "rep " <<  id_recipe <<  " init ingr\n";
        return true;
    }
    return false;

}

QString IngrRecipe::get_ingr(int i){
         return ingr[i];
}
int IngrRecipe::get_cout(){
        return ingr.size();
}

IngrRecipe::IngrRecipe(int i)
{
    id_recipe=i;
    if(!init())
    {
        qDebug() << "List ingrdients: error download\n";
    }
}

IngrRecipe::IngrRecipe(int  i, QVector<QString> in)
{
    //вставить то??????
    id_recipe=i;

    for(QString i:in)
    {
        add_ingr(i);
    }

}



 void IngrRecipe::delete_ingr(int i){
         delete_ingr(ingr[i]);
 }


 void IngrRecipe::add_ingr(QString name)
{
     query.prepare("INSERT INTO Ingredients (id_rep,name_ingr) VALUES (:id,:name)");
         query.bindValue(":name",name);
         query.bindValue(":id",id_recipe);
         if(!query.exec())
         {
             qDebug() <<"Error: rep " <<  id_recipe <<  " insert ingr\n";
         }else
         {
             ingr.push_back(name);
             qDebug() << "rep " <<  id_recipe <<  " init ingr\n";
         }
}

void IngrRecipe::delete_ingr(QString name){
    query.prepare("DELETE FROM Ingredients WHERE  name_ingr= :name AND id_rep=:id");
        query.bindValue(":name",name);
        query.bindValue(":id",id_recipe);

        if(!query.exec())
        {
             qDebug() <<"Error: rep " <<  id_recipe <<  " delete ingr\n";
        }else
        {
           ingr.remove(ingr.indexOf(name));
            //надо удалить
           qDebug() << "rep " <<  id_recipe <<  "delete ingr\n";
        }
}

