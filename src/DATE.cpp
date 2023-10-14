#include "DATE.h"

#include "DATE.h"
#include<iostream>
using namespace std;
 date::date(int jour , int mois , int annee)
 {
     this->jour=jour;
     this->mois=mois;
     this->annee=annee;
 }
date::~date()
    {

    }
void date::afficherdate(string msg)
{
    cout<<msg<<endl;
    cout<<jour<<"/"<<mois<<"/"<<annee<<endl;
}
void date::saisirdate()
{
    cout<<"saisir jour , mois et annee"<<endl;
    cin>>jour>>mois>>annee;
}
ostream& operator<<(ostream&out,date&d)
{
 out<<d.jour<<"/"<<d.mois<<"/"<<d.annee<<endl;
}
 istream& operator>>(istream&in,date&d)
 {
  in>>d.jour>>d.mois>>d.annee;
 }
ostream& operator<<(ostream&out,date*d)
{
   out<<d->jour<<"/"<<d->mois<<"/"<<d->annee<<endl;
}
istream& operator>>(istream&in,date*d)
{
   in>>d->jour>>d->mois>>d->annee;
}
