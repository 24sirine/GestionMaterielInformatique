#include "clavier.h"
#include<iostream>
using namespace std;
clavier::clavier(GARANTIE g ,int ref, float p,int s,string m,int tr):MaterielInfo(g,ref,p,s,m),sansFil(tr)
{

}
clavier::~clavier()
{

}
void clavier::saisir()
{ cout<<"saisir les caracteristiques du clavier"<<endl;
MaterielInfo::saisir();
do
{
    cout<<"saisir le type du clavier"<<endl;
    cout<<"1: sans fil"<<endl<<"2: avec fil"<<endl;
    cin>>sansFil;
}
while((sansFil !=1) && (sansFil !=2));
}
void clavier::afficher(string msg)
{ cout<<"*********AFFICHAGE DE ClAVIER********"<<endl;
    cout<<msg<<endl;
    MaterielInfo::afficher();
 if (sansFil==1) cout<<"clavier sans fil"<<endl;
 else if (sansFil ==2 )
 cout<<"clavier avec fil"<<endl;
}
ostream& operator<<(ostream&out,clavier&e)
{
    out<<"*********AFFICHAGE DE ClAVIER********"<<endl;
MaterielInfo*m=&e;
out<<*m; //appel de l'operator<< de la classe materielInfo
 if (e.sansFil==1) out<<"clavier sans fil"<<endl;
 else if (e.sansFil ==2 )
 out<<"clavier avec fil"<<endl;
 return out;
}
 istream& operator>>(istream&in,clavier&e)
{
 MaterielInfo*m=&e;
in>>*m; //appel de l'operator>> de la classe materielInfo
 do
{
    cout<<"saisir le type du clavier"<<endl;
    cout<<"1: sans fil"<<endl<<"2: avec fil"<<endl;
    in>>e.sansFil;
}
while((e.sansFil !=1) && (e.sansFil !=2));
return in;
}
 ostream& operator<<(ostream&out,clavier*e)
 {
     out<<"*********AFFICHAGE DE ClAVIER********"<<endl;
MaterielInfo*m=e;
out<<m; //appel de l'operator<< de la classe materielInfo
 if (e->sansFil==1) out<<"clavier sans fil"<<endl;
 else if (e->sansFil ==2 )
 out<<"clavier avec fil"<<endl;
 return out;
 }
 istream& operator>>(istream&in,clavier*e)
 {
  MaterielInfo*m=e;
in>>m; //appel de l'operator>> de la classe materielInfo
    in>>e->sansFil;
return in;
 }
