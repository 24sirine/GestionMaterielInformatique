#include "supportTransmisssion.h"
#include<iostream>
using namespace std;
supportTransmisssion::supportTransmisssion(GARANTIE g,int ref , float p ,int s ,string m, int t, float lo):MaterielInfo(g,ref,p,s,m),type(t),longeur(lo)
{

}
supportTransmisssion::~supportTransmisssion()
{

}
void supportTransmisssion::saisir()
{cout<<"saisir les caracteristiques du support de transmission"<<endl;
MaterielInfo::saisir();
   do{
    cout<<"saisir le type du cable"<<endl;
    cout<<" 1- cable HDMI" <<endl<<"2-cable USB"<<endl<<"3- cable reseau"<<endl;
    cin>>type;
    }
    while(type !=1 && type !=2 && type !=3);
cout<<"saisir la longeur du cable"<<endl;
cin>>longeur;
}
void supportTransmisssion::afficher(string msg)
{cout<<"*********AFFICHAGE DE SUPPORT DE TRANSMISSION********"<<endl;
    cout<<msg<<endl;
MaterielInfo::afficher();
if (type==1) cout<<"un cable HDMI"<<endl;
else if (type==2) cout<<"un cable USB"<<endl;
else if (type==3) cout<<"un cable reseau"<<endl;
cout<<"la longeur du cable est:"<<longeur<<endl;
}
ostream& operator<<(ostream&out,supportTransmisssion&e)
{out<<"*********AFFICHAGE DE SUPPORT DE TRANSMISSION********"<<endl;
MaterielInfo*m=&e;
out<<*m; //appel de l'operator<< de la classe materielInfo
if (e.type==1) out<<"un cable HDMI"<<endl;
else if (e.type==2) out<<"un cable USB"<<endl;
else if (e.type==3) out<<"un cable reseau"<<endl;
out<<"la longeur du cable est:"<<e.longeur<<endl;

 return out;
}
 istream& operator>>(istream&in,supportTransmisssion&e)
{
 MaterielInfo*m=&e;
in>>*m; //appel de l'operator>> de la classe materielInfo
  do{
    cout<<"saisir le type du cable"<<endl;
    cout<<" 1- cable HDMI" <<endl<<"2-cable USB"<<endl<<"3- cable reseau"<<endl;
    in>>e.type;
    }
    while(e.type !=1 && e.type !=2 && e.type !=3);
cout<<"saisir la longeur du cable"<<endl;
in>>e.longeur;
 return in;
}
ostream& operator<<(ostream&out,supportTransmisssion*e)
{
    out<<"*********AFFICHAGE DE SUPPORT DE TRANSMISSION********"<<endl;
MaterielInfo*m=e;
out<<m; //appel de l'operator<< de la classe materielInfo
if (e->type==1) out<<"un cable HDMI"<<endl;
else if (e->type==2) out<<"un cable USB"<<endl;
else if (e->type==3) out<<"un cable reseau"<<endl;
out<<"la longeur du cable est:"<<e->longeur<<endl;

 return out;
}
istream& operator>>(istream&in,supportTransmisssion*e)
{
   MaterielInfo*m=e;
in>>m; //appel de l'operator>> de la classe materielInfo
    in>>e->type;
in>>e->longeur;
 return in;
}
