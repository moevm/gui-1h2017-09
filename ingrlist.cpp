#include "ingrlist.h"
#include <QtAlgorithms>
Ingredients::Ingredients()
{
    if(!init())
    {
        qDebug() << "List ingrdients: error download\n";
    }

}
bool Ingredients::init(){
    if(query.exec("SELECT name_ingr FROM  Name_ingredients"))
    {
        while(query.next())
        {
            QSqlRecord rec = query.record();
            ingr.push_back(query.value(rec.indexOf("name_ingr")).toString());
        }
        return true;
    }else{
         qDebug() << "Error: SELECT name_ingr FROM  Name_ingredients \n";
        return false;
    }
}
void Ingredients:: add_ingr(QString name){
    query.prepare("INSERT INTO Name_ingredients (name_ingr) VALUES (:name);");
        query.bindValue(":name",name);
        if(!query.exec())
        {
            qDebug() << "Error: insert ingr in list inrg\n";
        }else
        {
            ingr.push_back(name);
            qDebug() << "Insert ingr yes\n";
        }


}
void Ingredients::delete_ingr(QString name){
    query.prepare("DELETE FROM Name_ingredients WHERE  name_ingr= :name;");
        query.bindValue(":name",name);

        if(!query.exec())
        {
            qDebug() << "Error: delete ingr in list inrg\n";
        }else
        {
           ingr.remove(ingr.indexOf(name));
            //надо удалить
            qDebug() << "delete ingr yes\n";
        }

}

void Ingredients::delete_ingr(int i){
        delete_ingr(ingr[i]);
}
QString Ingredients::get_ingr(int i){
         return ingr[i];
}
int Ingredients::get_cout(){
        return ingr.size();
}

