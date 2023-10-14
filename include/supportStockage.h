#ifndef SUPPORTSTOCKAGE_H
#define SUPPORTSTOCKAGE_H
#include <MaterielInfo.h>


class supportStockage : public MaterielInfo
{

 int categorie;
 float capacite;
 public:
supportStockage(GARANTIE,int =0 , float= 0.0 ,int =1 ,string="", int =0,float=0.0);
~supportStockage();
void saisir();
void afficher(string="");
int getCategorie(){return categorie;}
void setCategorie(int a){categorie=a;}
float getCapacite(){return capacite;}
void setCapacite(float c){capacite=c;}
friend ostream& operator<<(ostream&,supportStockage&);
friend istream& operator>>(istream&,supportStockage&);
friend ostream& operator<<(ostream&,supportStockage*);
friend istream& operator>>(istream&,supportStockage*);

};

#endif // SUPPORTSTOCKAGE_H
