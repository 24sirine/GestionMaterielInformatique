#include "imprimanteScanner.h"
#include<iostream>
using namespace std;
imprimanteScanner::imprimanteScanner(GARANTIE g ,int ref, float p,int s,string m, int vitesseImpression , string resolutionImpression):MaterielInfo(g,ref,p,s,m)
{
this->vitesseImpression=vitesseImpression;
this->resolutionImpression=resolutionImpression;

}

imprimanteScanner::~imprimanteScanner()
{

}
void imprimanteScanner::saisir()
{cout<<"saisir les caracteristiques du imprimante\scanner"<<endl;
MaterielInfo::saisir();
    cout<<"saisir la vitesse d'impression"<<endl;
    cin>>vitesseImpression;
    cout<<"saisir la resolution d'impression"<<endl;
    cin>>resolutionImpression;



}
void imprimanteScanner::afficher(string msg)
{cout<<"*********AFFICHAGE DE IMPRIMANTE\SCANNER********"<<endl;
    cout<<msg<<endl;
   MaterielInfo::afficher();
   cout<<"la vitesse d'impression est:"<<vitesseImpression<<endl;
   cout<<"la resolution d'impression est:"<<resolutionImpression<<endl;

}
ostream& operator<<(ostream&out,imprimanteScanner&e)
{out<<"*********AFFICHAGE DE IMPRIMANTE\SCANNER********"<<endl;
MaterielInfo*m=&e;
out<<*m; //appel de l'operator<< de la classe materielInfo
 out<<"la vitesse d'impression est:"<<e.vitesseImpression<<endl;
   out<<"la resolution d'impression est:"<<e.resolutionImpression<<endl;
 return out;
}
 istream& operator>>(istream&in,imprimanteScanner&e)
{
 MaterielInfo*m=&e;
in>>*m; //appel de l'operator>> de la classe materielInfo
cout<<"saisir la vitesse d'impression"<<endl;
    in>>e.vitesseImpression;
    cout<<"saisir la resolution d'impression"<<endl;
    in>>e.resolutionImpression;
return in;
}
 ostream& operator<<(ostream&out,imprimanteScanner*e)
 {
   out<<"*********AFFICHAGE DE IMPRIMANTE\SCANNER********"<<endl;
MaterielInfo*m=e;
out<<m; //appel de l'operator<< de la classe materielInfo
 out<<"la vitesse d'impression est:"<<e->vitesseImpression<<endl;
   out<<"la resolution d'impression est:"<<e->resolutionImpression<<endl;
 return out;
 }
 istream& operator>>(istream&in,imprimanteScanner*e)
 {
  MaterielInfo*m=e;
in>>m; //appel de l'operator>> de la classe materielInfo
    in>>e->vitesseImpression;
    in>>e->resolutionImpression;
return in;
 }


