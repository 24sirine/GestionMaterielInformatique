#ifndef IMPRIMANTESCANNER_H
#define IMPRIMANTESCANNER_H


#include <MaterielInfo.h>

class imprimanteScanner: public MaterielInfo
{
int vitesseImpression;
string resolutionImpression;
public:
    imprimanteScanner(GARANTIE,int =0 , float= 0.0 ,int =1 ,string="", int=12 ,string="");
    ~imprimanteScanner();
void saisir();
void afficher(string="");
int getVitesseImpression(){return vitesseImpression;}
void setVitesseImpression(int c){vitesseImpression=c;}
friend ostream& operator<<(ostream&,imprimanteScanner&);
friend istream& operator>>(istream&,imprimanteScanner&);
friend ostream& operator<<(ostream&,imprimanteScanner*);
friend istream& operator>>(istream&,imprimanteScanner*);
};

#endif // IMPRIMANTESCANNER_H
