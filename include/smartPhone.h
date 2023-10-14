#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <MaterielInfo.h>

class smartPhone: public MaterielInfo
{
string couleur;
int stockage;
bool doubleSIM;
public:
    smartPhone(GARANTIE,int =0 , float= 0.0 ,int =1 ,string="",string ="" , int=12 ,bool=false);
    ~smartPhone();
void saisir();
void afficher(string="");
int getStockage(){return stockage;}
void setStockage(int m){stockage=m;}
string getCouleur(){return couleur;}
void setCouleur(string c){couleur=c;}
friend ostream& operator<<(ostream&,smartPhone&);
friend istream& operator>>(istream&,smartPhone&);
friend ostream& operator<<(ostream&,smartPhone*);
friend istream& operator>>(istream&,smartPhone*);
};


#endif // SMARTPHONE_H
