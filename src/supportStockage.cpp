#include "supportStockage.h"
#include<iostream>
using namespace std;
supportStockage::supportStockage(GARANTIE g,int ref , float p ,int s ,string m, int cat, float cap):MaterielInfo(g,ref,p,s,m),categorie(cat),capacite(cap)
{

}
supportStockage::~supportStockage()
{

}
void supportStockage::saisir()
{cout<<"saisir les caracteristiques du support de stockage"<<endl;
MaterielInfo::saisir();
   do{
    cout<<"saisir le type du support de stockage"<<endl;
    cout<<" 1- cle USB" <<endl<<"2-CD_DVD"<<endl<<"3- carte memeoire"<<endl<<"4-disque dur"<<endl;
    cin>>categorie;
    }
    while((categorie!=1) && (categorie !=2 )&&( categorie !=3) &&( categorie!=4));
    cout<<"saisir la capacite du support de stockage"<<endl;
    cin>>capacite;
}
void supportStockage::afficher(string msg)
{cout<<"*********AFFICHAGE DE SUPPORT DE STOCKAGE********"<<endl;
    cout<<msg<<endl;
    MaterielInfo::afficher();
if (categorie==1) cout<<"cle USB"<<endl;
else if (categorie==2) cout<<"un CD ou DVD"<<endl;
else if (categorie==3) cout<<"une carte memoire"<<endl;
else if (categorie==4) cout<<"un disque dur"<<endl;
cout<<"la capacite de stockage est:"<<capacite<<endl;

}
ostream& operator<<(ostream&out,supportStockage&e)
{out<<"*********AFFICHAGE DE SUPPORT DE STOCKAGE********"<<endl;
MaterielInfo*m=&e;
out<<*m; //appel de l'operator<< de la classe materielInfo
if (e.categorie==1) out<<"cle USB"<<endl;
else if (e.categorie==2) out<<"un CD ou DVD"<<endl;
else if (e.categorie==3) out<<"une carte memoire"<<endl;
else if (e.categorie==4) out<<"un disque dur"<<endl;
out<<"la capacite de stockage est:"<<e.capacite<<endl;

 return out;
}
 istream& operator>>(istream&in,supportStockage&e)
{
 MaterielInfo*m=&e;
in>>*m; //appel de l'operator>> de la classe materielInfo
  do{
    cout<<"saisir le type du support de stockage"<<endl;
    cout<<" 1- cle USB" <<endl<<"2-CD_DVD"<<endl<<"3- carte memeoire"<<endl<<"4-disque dur"<<endl;
    in>>e.categorie;
    }
    while((e.categorie!=1) && (e.categorie !=2 )&&( e.categorie !=3) &&( e.categorie!=4));
    cout<<"saisir la capacite du support de stockage"<<endl;
    in>>e.capacite;
 return in;
}
ostream& operator<<(ostream&out,supportStockage*e)
{
out<<"*********AFFICHAGE DE SUPPORT DE STOCKAGE********"<<endl;
MaterielInfo*m=e;
out<<m; //appel de l'operator<< de la classe materielInfo
if (e->categorie==1) out<<"cle USB"<<endl;
else if (e->categorie==2) out<<"un CD ou DVD"<<endl;
else if (e->categorie==3) out<<"une carte memoire"<<endl;
else if (e->categorie==4) out<<"un disque dur"<<endl;
out<<"la capacite de stockage est:"<<e->capacite<<endl;

 return out;
}
istream& operator>>(istream&in,supportStockage*e)
{
  MaterielInfo*m=e;
in>>m; //appel de l'operator>> de la classe materielInfo
    in>>e->categorie;
    in>>e->capacite;
 return in;
}
