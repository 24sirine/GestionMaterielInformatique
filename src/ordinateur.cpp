#include "ordinateur.h"

#include<iostream>
using namespace std;
ordinateur::ordinateur(GARANTIE g ,int ref, float p,int s,string m , int type , string processur , int memoire , int capaciteDisqueDur, string carteGraphique, float tailleEcran,string systExploitation,
string couleur):MaterielInfo(g,ref,p,s,m)
{
this->type=type;
this->processeur=processeur;
this->memoire=memoire;
this->capaciteDisqueDur=capaciteDisqueDur;
this->carteGraphique=carteGraphique;
this->tailleEcran=tailleEcran;
this->systExploitation=systExploitation;
this->couleur=couleur;
}
ordinateur::~ordinateur()
{

}
void ordinateur::saisir()
{cout<<"saisir les caracteristiques d'ordinateur"<<endl;
MaterielInfo::saisir();
do
{
    cout<<"saisir le type de l'ordinateur"<<endl;
    cout<<"1- pc portable"<<endl<<"2- ordinateur de bureau"<<endl;
    cin>>type;
}
while((type!=1) && (type !=2));
cout<<"saisir le processeur de l'ordinateur"<<endl;
cin>>processeur;
cout<<"saisir la memoire de l'ordinateur"<<endl;
cin>>memoire;
cout<<"saisir la capacite de disque dur de l'ordinateur"<<endl;
cin>>capaciteDisqueDur;
cout<<"saisir la carte graphique de l'ordinateur"<<endl;
cin>>carteGraphique;
cout<<"saisir  taille de l'ecran de l'ordinateur"<<endl;
cin>>tailleEcran;
cout<<"saisir le systeme d'exploitation de l'ordinateur"<<endl;
cin>>systExploitation;
cout<<"saisir la couleur de l'ordinateur"<<endl;
cin>>couleur;
}
void ordinateur::afficher(string msg)
{ cout<<"*********AFFICHAGE D'ORDINATEUR********"<<endl;
    cout<<msg<<endl;
     MaterielInfo::afficher();
 if (type==1) cout<<"pc portable"<<endl;
 else if (type==2)
 cout<<"ordinateur de bureau"<<endl;
 cout<<"le processeur de l'ordinateur est:"<<processeur<<endl;
 cout<<"la memoire de l'ordinateur est:"<<memoire<<endl;
 cout<<"la capacite de disque dur de l'ordinateur est:"<<capaciteDisqueDur<<endl;
 cout<<"la carte graphique de l'ordinateur est:"<<carteGraphique<<endl;
 cout<<"taille de l'ecran de l'ordinateur est:"<<tailleEcran<<endl;
 cout<<"le systeme d'exploitation de l'ordinateur est:"<<systExploitation<<endl;
 cout<<"la couleur de l'ordinateur est:"<<couleur<<endl;
}

ostream& operator<<(ostream&out,ordinateur&e)
{out<<"*********AFFICHAGE D'ORDINATEUR********"<<endl;
MaterielInfo*m=&e;
out<<*m; //appel de l'operator<< de la classe materielInfo
 if (e.type==1) out<<"pc portable"<<endl;
 else if (e.type==2)
out<<"ordinateur de bureau"<<endl;
 out<<"le processeur de l'ordinateur est:"<<e.processeur<<endl;
 out<<"la memoire de l'ordinateur est:"<<e.memoire<<endl;
 out<<"la capacite de disque dur de l'ordinateur est:"<<e.capaciteDisqueDur<<endl;
 out<<"la carte graphique de l'ordinateur est:"<<e.carteGraphique<<endl;
 out<<"taille de l'ecran de l'ordinateur est:"<<e.tailleEcran<<endl;
 out<<"le systeme d'exploitation de l'ordinateur est:"<<e.systExploitation<<endl;
 out<<"la couleur de l'ordinateur est:"<<e.couleur<<endl;
 return out;
}
 istream& operator>>(istream&in,ordinateur&e)
{
 MaterielInfo*m=&e;
in>>*m; //appel de l'operator>> de la classe materielInfo
do
{
    cout<<"saisir le type de l'ordinateur"<<endl;
    cout<<"1- pc portable"<<endl<<"2- ordinateur de bureau"<<endl;
    in>>e.type;
}
while((e.type!=1) && (e.type !=2));
cout<<"saisir le processeur de l'ordinateur"<<endl;
in>>e.processeur;
cout<<"saisir la memoire de l'ordinateur"<<endl;
in>>e.memoire;
cout<<"saisir la capacite de disque dur de l'ordinateur"<<endl;
in>>e.capaciteDisqueDur;
cout<<"saisir la carte graphique de l'ordinateur"<<endl;
in>>e.carteGraphique;
cout<<"saisir  taille de l'ecran de l'ordinateur"<<endl;
in>>e.tailleEcran;
cout<<"saisir le systeme d'exploitation de l'ordinateur"<<endl;
in>>e.systExploitation;
cout<<"saisir la couleur de l'ordinateur"<<endl;
in>>e.couleur;
return in;
}
ostream& operator<<(ostream& out,ordinateur*e)
{
out<<"*********AFFICHAGE D'ORDINATEUR********"<<endl;
MaterielInfo*m=e;
out<<m; //appel de l'operator<< de la classe materielInfo
 if (e->type==1) out<<"pc portable"<<endl;
 else if (e->type==2)
out<<"ordinateur de bureau"<<endl;
 out<<"le processeur de l'ordinateur est:"<<e->processeur<<endl;
 out<<"la memoire de l'ordinateur est:"<<e->memoire<<endl;
 out<<"la capacite de disque dur de l'ordinateur est:"<<e->capaciteDisqueDur<<endl;
 out<<"la carte graphique de l'ordinateur est:"<<e->carteGraphique<<endl;
 out<<"taille de l'ecran de l'ordinateur est:"<<e->tailleEcran<<endl;
 out<<"le systeme d'exploitation de l'ordinateur est:"<<e->systExploitation<<endl;
 out<<"la couleur de l'ordinateur est:"<<e->couleur<<endl;
 return out;
}
 istream& operator>>(istream&in,ordinateur*e)
 {
  MaterielInfo*m=e;
in>>m; //appel de l'operator>> de la classe materielInfo
    in>>e->type;
in>>e->processeur;
in>>e->memoire;
in>>e->capaciteDisqueDur;
in>>e->carteGraphique;
in>>e->tailleEcran;
in>>e->systExploitation;
in>>e->couleur;
return in;
 }
