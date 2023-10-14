#include "GARANTIE.h"
#include"DATE.h"
#include<iostream>
using namespace std;
GARANTIE::GARANTIE(date d,date a):dateDebut(d),dateFin(a)
{
}
GARANTIE::~GARANTIE()
{
}
void GARANTIE::affichergarantie(string msg)
{
    cout<<msg<<endl;
    cout<<"la date de debut de garantie est:"<<endl;
    dateDebut.afficherdate();
    cout<<"la date de fin de garantie est:"<<endl;
    dateFin.afficherdate();

}
void GARANTIE::saisirgarantie()
{
 cout<<"saisir la date de debut"<<endl;
 dateDebut.saisirdate();
cout<<"saisir la date de fin"<<endl;
 dateFin.saisirdate();
}
ostream& operator<<(ostream& out,GARANTIE&e)
{ out<<"date de debut"<<endl;
  date*d=&e.dateDebut;
out<<*d; //appel de l'operator>> de la classe date
out<<"date de fin"<<endl;
  date*c=&e.dateFin;
  out<<*c;
return out;
}
 istream& operator>>(istream&in,GARANTIE&e)
 {
  date*d=&e.dateDebut;
in>>*d; //appel de l'operator>> de la classe date
  date*c=&e.dateFin;
  in>>*c;
return in;
 }
ostream& operator<<(ostream&out,GARANTIE*e)
{
 out<<"date de debut"<<endl;
  date*d=&e->dateDebut;
out<<d; //appel de l'operator>> de la classe date
out<<"date de fin"<<endl;
  date*c=&e->dateFin;
  out<<c;
return out;
}
 istream& operator>>(istream&in,GARANTIE*e)
 {
   date*d=&e->dateDebut;
in>>d; //appel de l'operator>> de la classe date
  date*c=&e->dateFin;
  in>>c;
return in;
 }
