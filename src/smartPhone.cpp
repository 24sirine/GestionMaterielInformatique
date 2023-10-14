#include "smartPhone.h"
#include<iostream>
using namespace std;
smartPhone::smartPhone(GARANTIE g ,int ref, float p,int s,string m, string couleur, int stockage , bool doubleSIM):MaterielInfo(g,ref,p,s,m)
{
this->couleur=couleur;
this->stockage=stockage;
this->doubleSIM=doubleSIM;
}
smartPhone::~smartPhone()
{

}
void smartPhone::saisir()
{cout<<"saisir les caracteristiques du smart phone"<<endl;
MaterielInfo::saisir();
    cout<<"saisir la couleur de smart Phone"<<endl;
    cin>>couleur;
    cout<<"saisir le stockage de smart Phone"<<endl;
    cin>>stockage;
    do
    {
    cout<<"saisir 1- smart phone double SIM "<<endl<<"saisir 2- smart phone a une seule SIM"<<endl;
    cin>>doubleSIM;
}
while( (doubleSIM != 1) &&(doubleSIM !=2));


}
void smartPhone::afficher(string msg)
{cout<<"*********AFFICHAGE DE SMARTPHONE********"<<endl;
    cout<<msg<<endl;
   MaterielInfo::afficher();
   cout<<"la couleur de smart phone est:"<<couleur<<endl;
   cout<<"le stockage de smart phone est:"<<stockage<<endl;
 if (doubleSIM==1) cout<<"smart phone double SIM"<<endl;
 else if (doubleSIM ==2 )
 cout<<"smart phone a une seule SIM"<<endl;
}

ostream& operator<<(ostream&out,smartPhone&e)
{out<<"*********AFFICHAGE DE SMARTPHONE********"<<endl;
MaterielInfo*m=&e;
out<<*m; //appel de l'operator<< de la classe materielInfo
   out<<"la couleur de smart phone est:"<<e.couleur<<endl;
   out<<"le stockage de smart phone est:"<<e.stockage<<endl;
 if (e.doubleSIM==1) out<<"smart phone double SIM"<<endl;
 else if (e.doubleSIM ==2 )
 out<<"smart phone a une seule SIM"<<endl;

 return out;
}
 istream& operator>>(istream&in,smartPhone&e)
{
 MaterielInfo*m=&e;
in>>*m; //appel de l'operator>> de la classe materielInfo
  cout<<"saisir la couleur de smart Phone"<<endl;
    in>>e.couleur;
    cout<<"saisir le stockage de smart Phone"<<endl;
    in>>e.stockage;
    do
    {
    cout<<"saisir 1- smart phone double SIM "<<endl<<"saisir 2- smart phone a une seule SIM"<<endl;
    in>>e.doubleSIM;
}
while( (e.doubleSIM != 1) &&(e.doubleSIM !=2));

return in;
}

 ostream& operator<<(ostream&out,smartPhone*e)
 {
  out<<"*********AFFICHAGE DE SMARTPHONE********"<<endl;
MaterielInfo*m=e;
out<<m; //appel de l'operator<< de la classe materielInfo
   out<<"la couleur de smart phone est:"<<e->couleur<<endl;
   out<<"le stockage de smart phone est:"<<e->stockage<<endl;
 if (e->doubleSIM==1) out<<"smart phone double SIM"<<endl;
 else if (e->doubleSIM ==2 )
 out<<"smart phone a une seule SIM"<<endl;

 return out;
 }
 istream& operator>>(istream&in,smartPhone*e)
 {
  MaterielInfo*m=e;
in>>m; //appel de l'operator>> de la classe materielInfo
    in>>e->couleur;
    in>>e->stockage;
    in>>e->doubleSIM;

return in;
 }
