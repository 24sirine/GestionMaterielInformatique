#include "souris.h"
#include<iostream>
using namespace std;
souris::souris(GARANTIE g ,int ref, float p,int s,string m,int tr):MaterielInfo(g,ref,p,s,m),sansFil(tr)
{

}
souris::~souris()
{

}
void souris::saisir()
{cout<<"saisir les caracteristiques du souris"<<endl;
MaterielInfo::saisir();
do
{
    cout<<"saisir le type du souris"<<endl;
    cout<<"1: sans fil"<<endl<<"2: avec fil"<<endl;
    cin>>sansFil;
}
while((sansFil !=1) &&(sansFil !=2));
}
void souris::afficher(string msg)
{cout<<"*********AFFICHAGE DE SOURIS********"<<endl;
    cout<<msg<<endl;
     MaterielInfo::afficher();
 if (sansFil==1) cout<<"souris sans fil"<<endl;
 else if (sansFil ==2 )
 cout<<"souris avec fil"<<endl;
}
ostream& operator<<(ostream&out,souris&e)
{out<<"*********AFFICHAGE DE SOURIS********"<<endl;
MaterielInfo*m=&e;
out<<*m; //appel de l'operator<< de la classe materielInfo
 if (e.sansFil==1) out<<"souris sans fil"<<endl;
 else if (e.sansFil ==2 )
 out<<"souris avec fil"<<endl;
 return out;
}
 istream& operator>>(istream&in,souris&e)
{
 MaterielInfo*m=&e;
in>>*m; //appel de l'operator>> de la classe materielInfo
 do
{
    cout<<"saisir le type du souris"<<endl;
    cout<<"1: sans fil"<<endl<<"2: avec fil"<<endl;
    in>>e.sansFil;
}
while((e.sansFil !=1) && (e.sansFil !=2));
return in;
}
ostream& operator<<(ostream&out,souris*e)
{
out<<"*********AFFICHAGE DE SOURIS********"<<endl;
MaterielInfo*m=e;
out<<m; //appel de l'operator<< de la classe materielInfo
 if (e->sansFil==1) out<<"souris sans fil"<<endl;
 else if (e->sansFil ==2 )
 out<<"souris avec fil"<<endl;
 return out;
}
 istream& operator>>(istream&in,souris*e)
{
  MaterielInfo*m=e;
in>>m; //appel de l'operator>> de la classe materielInfo

    in>>e->sansFil;

return in;
}
