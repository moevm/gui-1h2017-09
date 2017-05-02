#include "recipe.h"
#include <QDebug>


Recipe::Recipe(QSqlQuery *query)//скачивает с помощью query в текущей позиции
{
    QSqlRecord rec=query->record();
    id=query->value(rec.indexOf("id")).toInt();
    name=query->value(rec.indexOf("name")).toString();
    descr=query->value(rec.indexOf("description")).toString();
    time=query->value(rec.indexOf("time")).toInt();
    img=query->value(rec.indexOf("picture")).toString();
    text=query->value(rec.indexOf("text")).toString();
    ingr=new IngrRecipe(id);
}
Recipe::Recipe(int idd,QString nm, QString d,int t,QString i,QString txt)//создает уже существующий рецепт, добавляет сам свои ингр
{
    id=idd;
    name=nm;
    descr=d;
    time=t;
    img=i;
    text=txt;
    ingr=new IngrRecipe(id);
}
Recipe::Recipe(QString nm, QString d,int t,QString i,QString txt,QVector<QString> in)//создает новый
{
    query.prepare("INSERT INTO Recipe (name,description,time,picture,text) VALUES (:name,:descr,:time,:pic,:txt)");
        query.bindValue(":name",nm);
        query.bindValue(":descr",d);
        query.bindValue(":time",t);
        query.bindValue(":pic",i);
        query.bindValue(":txt",txt);
        if(!query.exec())
        {

            qDebug() <<"Error: rep"  <<  " insert rep\n";
        }else
        {
            id=0;
            name=nm;
            descr=d;
            time=t;
            img=i;
            text=txt;

            id=0;
            get_id();
            if(id==0)
            {
                 qDebug() <<"Error: rep"  <<  "get id\n";
            }else
            {
                ingr=new IngrRecipe(id,in);
            }
            qDebug() <<"rep"  <<  " insert rep\n";
        }
}
void Recipe::get_id(){
    query.prepare("SELECT id FROM Recipe WHERE (name= :name AND description=:descr AND time=:time AND picture=:pic AND text=:txt)");
    query.bindValue(":name",name);
    query.bindValue(":descr",descr);
    query.bindValue(":time",time);
    query.bindValue(":pic",img);
    query.bindValue(":txt",text);
    if(!query.exec())
    {

        qDebug() <<"Error: rep"  <<  " get id\n";
    }else
    {

        QSqlRecord rec=query.record();
        while(query.next()){
        id=query.value(rec.indexOf("id")).toInt();
        qDebug() <<   "rep"  <<  "select get id\n";
        }
    }

}
QString Recipe::get_name(){
    return name;
}
QString Recipe::get_descr(){
    return descr;
}
QString Recipe::get_img(){
    return img;
}
QString Recipe::get_txt(){
    return text;
}
int Recipe::get_time(){
    return time;
}

bool Recipe::set_name(QString nm){
    query.prepare("UPDATE Recipe SET name=:name WHERE id=:id");
    query.bindValue(":name",nm);
    query.bindValue(":id",id);

    if(nm=="")
    {
        return false;
    }
    if(!query.exec())
    {
        qDebug() << "Error: " << id << "rep set name\n";
        return false;
    }else{
        name=nm;
        return true;
    }
}
bool Recipe::set_descr(QString d){
    query.prepare("UPDATE Recipe SET description=:descr WHERE id=:id");
    query.bindValue(":descr",d);
    query.bindValue(":id",id);

    if(!query.exec())
    {
        qDebug() << "Error: " << id << "rep set descr\n";
        return false;
    }else{
        descr=d;
        return true;
    }
}
bool Recipe::set_img(QString i){
    query.prepare("UPDATE Recipe SET picture=:img WHERE id=:id");
    query.bindValue(":img",i);
    query.bindValue(":id",id);

    if(!query.exec())
    {
        qDebug() << "Error: " << id << "rep set img\n";
        return false;
    }else{
        img=i;
        return true;
    }
}
bool Recipe::set_text(QString t){
    query.prepare("UPDATE Recipe SET text=:txt WHERE id=:id");
    query.bindValue(":txt",t);
    query.bindValue(":id",id);

    if(!query.exec())
    {
        qDebug() << "Error: " << id << "rep set txt\n";
        return false;
    }else{
        text=t;
        return true;
    }
}
bool Recipe::set_time(int t){
    query.prepare("UPDATE Recipe SET time=:tm WHERE id=:id");
    query.bindValue(":tm",t);
    query.bindValue(":id",id);

    if(!query.exec())
    {
        qDebug() << "Error: " << id << "rep set time\n";
        return false;
    }else{
        time=t;
        return true;
    }
}
bool Recipe::set_descr(){
    query.prepare("UPDATE Recipe SET description=NULL WHERE id=:id");
    query.bindValue(":id",id);

    if(!query.exec())
    {
        qDebug() << "Error: " << id << "rep set descr\n";
        return false;
    }else{
        descr="";
        return true;
    }
}
bool Recipe::set_img(){
    query.prepare("UPDATE Recipe SET picture=:NULL WHERE id=:id");
    query.bindValue(":id",id);

    if(!query.exec())
    {
        qDebug() << "Error: " << id << "rep set img\n";
        return false;
    }else{
        img="";
        return true;
    }
}
bool Recipe::set_text(){
    query.prepare("UPDATE Recipe SET text=NULL WHERE id=:id");
    query.bindValue(":id",id);

    if(!query.exec())
    {
        qDebug() << "Error: " << id << "rep set txt\n";
        return false;
    }else{
        text="";
        return true;
    }
}
bool Recipe::set_time(){
    query.prepare("UPDATE Recipe SET time=NULL WHERE id=:id");
    query.bindValue(":id",id);

    if(!query.exec())
    {
        qDebug() << "Error: " << id << "rep set time\n";
        return false;
    }else{
        time=0;
        return true;
    }
}

bool Recipe::del_recipe(){
    query.prepare("DELETE FROM Recipe WHERE id=:id");
    query.bindValue(":id",id);
    if(!query.exec())
    {
        qDebug() << "Error: " << id << "del recipe\n";
        return false;
    }else{
        //int k=ingr->get_cout()-1;
        for(int i=ingr->get_cout()-1;i>=0;i--){
            ingr->delete_ingr(i);
        }
        delete this;
        return true;
    }
    //удалить все ингредиенты пока не восстановлена связь
    //удалить рецепт
}


Recipe::~Recipe(){
    delete ingr;
}
