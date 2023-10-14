#include "MaterielInfo.h"
#include"GARANTIE.h"
#include<iostream>
using namespace std;
 MaterielInfo::MaterielInfo(GARANTIE g,int ref, float p, int s, string m ): garantie(g),reference(ref),prix(p),stock(s),marque(m)
 {

 }
MaterielInfo::~MaterielInfo()
    {

    }
void MaterielInfo::afficher(string msg)
    {
     cout<<"la reference du materiel est:"<<reference<<endl;
     cout<<"le prix du materiel est:"<<prix<<endl;
     cout<<"le stock du materiel est:"<<stock<<endl;
     cout<<"la marque du materiel est:"<<marque<<endl;
     cout<<"le garantie est:"<<endl;
    garantie.affichergarantie();
    }
void MaterielInfo::saisir()
{
    cout<<"saisir la reference:"<<endl;
    cin>>reference;
    cout<<"saisir le prix:"<<endl;
    cin>>prix;
    cout<<"saisir le stock:"<<endl;
    cin>>stock;
    cout<<"saisir la marque:"<<endl;
    cin>>marque;
    garantie.saisirgarantie();
}
ostream& operator<<(ostream& out,MaterielInfo&e)
{
 out<<"la reference du materiel est:"<<e.reference<<endl;
     out<<"le prix du materiel est:"<<e.prix<<endl;
     out<<"le stock du materiel est:"<<e.stock<<endl;
     out<<"la marque du materiel est:"<<e.marque<<endl;
     out<<"le garantie est:"<<endl;
    out<<"date de debut:"<<e.garantie.dateDebut<<endl;
      out<<"date de fin:"<<e.garantie.dateFin<<endl;
    return out;
}
 istream& operator>>(istream&in,MaterielInfo&e)
 {
 cout<<"saisir la reference:"<<endl;
    in>>e.reference;
    cout<<"saisir le prix:"<<endl;
    in>>e.prix;
    cout<<"saisir le stock:"<<endl;
    in>>e.stock;
    cout<<"saisir la marque:"<<endl;
    in>>e.marque;
    cout<<"saisir garantie:"<<endl;
    cout<<"saisir date de debut:"<<endl;
      in>>e.garantie.dateDebut;
      cout<<"saisir date du fin"<<endl;
    in>>e.garantie.dateFin;
    return in;
 }
  ostream& operator<<(ostream&out,MaterielInfo*e)
  {
 out<<"la reference du materiel est:"<<e->reference<<endl;
     out<<"le prix du materiel est:"<<e->prix<<endl;
     out<<"le stock du materiel est:"<<e->stock<<endl;
     out<<"la marque du materiel est:"<<e->marque<<endl;
     out<<"le garantie est:"<<endl;
      out<<"date de debut:"<<e->garantie.dateDebut<<endl;
      out<<"date de fin:"<<e->garantie.dateFin<<endl;
    return out;
  }
istream& operator>>(istream&in,MaterielInfo*e)
{
    in>>e->reference;
    in>>e->prix;
    in>>e->stock;
    in>>e->marque;
    in>>e->garantie.dateDebut;
    in>>e->garantie.dateFin;
    return in;
}
