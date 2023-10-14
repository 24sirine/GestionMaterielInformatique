#include "serveur.h"

#include<iostream>
using namespace std;
serveur::serveur(GARANTIE g ,int ref, float p,int s,string m, int capacite , string processeur):MaterielInfo(g,ref,p,s,m)
{
this->capacite=capacite;
this->processeur=processeur;

}

serveur::~serveur()
{

}
void serveur::saisir()
{cout<<"saisir les caracteristiques du serveur"<<endl;
MaterielInfo::saisir();
    cout<<"saisir la capacite"<<endl;
    cin>>capacite;
    cout<<"saisir le processeur"<<endl;
    cin>>processeur;



}
void serveur::afficher(string msg)
{cout<<"*********AFFICHAGE DE SERVEUR********"<<endl;
    cout<<msg<<endl;
   MaterielInfo::afficher();
   cout<<"la capacite est:"<<capacite<<endl;
   cout<<"le processeur est:"<<processeur<<endl;

}

ostream& operator<<(ostream&out,serveur&e)
{out<<"*********AFFICHAGE DE SERVEUR********"<<endl;
MaterielInfo*m=&e;
out<<*m; //appel de l'operator<< de la classe materielInfo
  out<<"la capacite est:"<<e.capacite<<endl;
   out<<"le processeur est:"<<e.processeur<<endl;
 return out;
}
 istream& operator>>(istream&in,serveur&e)
{
 MaterielInfo*m=&e;
in>>*m; //appel de l'operator>> de la classe materielInfo
 cout<<"saisir la capacite"<<endl;
    in>>e.capacite;
    cout<<"saisir le processeur"<<endl;
    in>>e.processeur;
return in;
}

 ostream& operator<<(ostream&out,serveur*e)
 {
  out<<"*********AFFICHAGE DE SERVEUR********"<<endl;
MaterielInfo*m=e;
out<<m; //appel de l'operator<< de la classe materielInfo
  out<<"la capacite est:"<<e->capacite<<endl;
   out<<"le processeur est:"<<e->processeur<<endl;
 return out;
 }
istream& operator>>(istream&in,serveur*e)
{
  MaterielInfo*m=e;
in>>m; //appel de l'operator>> de la classe materielInfo
    in>>e->capacite;
    in>>e->processeur;
return in;
}
