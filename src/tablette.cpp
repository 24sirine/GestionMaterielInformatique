#include "tablette.h"
#include<iostream>
using namespace std;
tablette::tablette(GARANTIE g ,int ref, float p,int s,string m, int memoire , int tailleEcran , bool doubleSIM):MaterielInfo(g,ref,p,s,m)
{
this->memoire=memoire;
this->tailleEcran=tailleEcran;
this->doubleSIM=doubleSIM;
}
tablette::~tablette()
{

}
void tablette::saisir()
{cout<<"saisir les caracteristiques du tablette"<<endl;
MaterielInfo::saisir();
    cout<<"saisir la memoire du tablette"<<endl;
    cin>>memoire;
    cout<<"saisir la taille de l'écran"<<endl;
    cin>>tailleEcran;
    do
    {
    cout<<"saisir 1- tablette double SIM "<<endl<<"saisir 2- tablette a une seule SIM"<<endl;
    cin>>doubleSIM;
}
while( (doubleSIM != 1) && (doubleSIM !=2));


}
void tablette::afficher(string msg)
{cout<<"*********AFFICHAGE DE TABLETTE********"<<endl;
    cout<<msg<<endl;
   MaterielInfo::afficher();
   cout<<"la memoire du tablette est:"<<memoire<<endl;
   cout<<"la taille de l'ecran du tablette est:"<<tailleEcran<<endl;
 if (doubleSIM==1) cout<<"tablette double SIM"<<endl;
 else if (doubleSIM ==2 )
 cout<<"tablette a une seule SIM"<<endl;
}
ostream& operator<<(ostream&out,tablette&e)
{out<<"*********AFFICHAGE DE TABLETTE********"<<endl;
MaterielInfo*m=&e;
out<<*m; //appel de l'operator<< de la classe materielInfo
   out<<"la memoire du tablette est:"<<e.memoire<<endl;
   out<<"la taille de l'ecran du tablette est:"<<e.tailleEcran<<endl;
 if (e.doubleSIM==1) out<<"tablette double SIM"<<endl;
 else if (e.doubleSIM ==2 )
 out<<"tablette a une seule SIM"<<endl;

 return out;
}
 istream& operator>>(istream&in,tablette&e)
{
 MaterielInfo*m=&e;
in>>*m; //appel de l'operator>> de la classe materielInfo
    cout<<"saisir la memoire du tablette"<<endl;
    in>>e.memoire;
    cout<<"saisir la taille de l'écran"<<endl;
    in>>e.tailleEcran;
    do
    {
    cout<<"saisir 1- tablette double SIM "<<endl<<"saisir 2- tablette a une seule SIM"<<endl;
    in>>e.doubleSIM;
}
while( (e.doubleSIM != 1) && (e.doubleSIM !=2));



return in;
}
ostream& operator<<(ostream&out,tablette*e)
{
  out<<"*********AFFICHAGE DE TABLETTE********"<<endl;
MaterielInfo*m=e;
out<<m; //appel de l'operator<< de la classe materielInfo
   out<<"la memoire du tablette est:"<<e->memoire<<endl;
   out<<"la taille de l'ecran du tablette est:"<<e->tailleEcran<<endl;
 if (e->doubleSIM==1) out<<"tablette double SIM"<<endl;
 else if (e->doubleSIM ==2 )
 out<<"tablette a une seule SIM"<<endl;

 return out;
}
 istream& operator>>(istream&in,tablette*e)
 {
   MaterielInfo*m=e;
in>>m; //appel de l'operator>> de la classe materielInfo
    in>>e->memoire;
    in>>e->tailleEcran;
    in>>e->doubleSIM;
return in;
 }
