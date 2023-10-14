#ifndef MATERIELINFO_H
#define MATERIELINFO_H
#include"GARANTIE.h"
#include"string"
#include<ios>
using namespace std;


//classe abstraite
class MaterielInfo
{ protected:
  int reference;
  float prix;
  int stock;
  string marque;
  GARANTIE garantie;
public:
    MaterielInfo(GARANTIE,int =1 , float=0.0, int=0, string="");
   virtual ~MaterielInfo();
   virtual void afficher(string="")=0;
   virtual void saisir()=0;
   int getReference(){return reference;}
   float getPrix(){return prix;}
   int getStock(){return stock;}
   string getMarque(){return marque;}
   friend ostream& operator<<(ostream&,MaterielInfo&);
friend istream& operator>>(istream&,MaterielInfo&);
   friend ostream& operator<<(ostream&,MaterielInfo*);
friend istream& operator>>(istream&,MaterielInfo*);

};

#endif // MATERIELINFO_H
