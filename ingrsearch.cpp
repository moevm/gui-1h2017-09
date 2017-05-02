#include "ingrsearch.h"

IngrSearch::IngrSearch()
{

}

 bool IngrSearch::init(){
     return true;
 }

void IngrSearch::add_ingr(QString name){
    ingr.push_back(name);
}

 void IngrSearch::delete_ingr(QString name){
     ingr.remove(ingr.indexOf(name));
 }

 void IngrSearch::delete_ingr(int i){
         delete_ingr(ingr[i]);
 }
 QString IngrSearch::get_ingr(int i){
          return ingr[i];
 }
 int IngrSearch::get_cout(){
         return ingr.size();
 }

