#include "DATE1.h"
#include<iostream>
using namespace std;
 DATE1::DATE1(int jour , int mois , int annee)
 {
     this->jour=jour;
     this->mois=mois;
     this->annee=annee;
 }
DATE1::~DATE1()
    {

    }
void DATE1::afficherdate(string msg)
{
    cout<<msg<<endl;
    cout<<jour<<"/"<<mois<<"/"<<annee<<endl;
}
void DATE1::saisirdate()
{
    cout<<"saisir jour , mois et annee"<<endl;
    cin>>jour>>mois>>annee;
}
