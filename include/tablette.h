#ifndef TABLETTE_H
#define TABLETTE_H


#include <MaterielInfo.h>

class tablette : public MaterielInfo
{
int memoire;
int tailleEcran;
bool doubleSIM;
public:
    tablette(GARANTIE,int =0 , float= 0.0 ,int =1 ,string="",int =1 , int=12 ,bool=false);
    ~tablette();
void saisir();
void afficher(string="");
int getMemoire(){return memoire;}
void setMemoire(int m){memoire=m;}
int getTailleEcran(){return tailleEcran;}
void setTailleEcran(int t){tailleEcran=t;}
friend ostream& operator<<(ostream&,tablette&);
friend istream& operator>>(istream&,tablette&);
friend ostream& operator<<(ostream&,tablette*);
friend istream& operator>>(istream&,tablette*);
};

#endif // TABLETTE_H
