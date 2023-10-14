#ifndef ORDINATEUR_H
#define ORDINATEUR_H
#include<string>
using namespace std;
#include <MaterielInfo.h>
class ordinateur : public MaterielInfo
{
int type;
string processeur;
int memoire;
int capaciteDisqueDur;
string carteGraphique;
float tailleEcran;
string systExploitation;
string couleur;
public:
    ordinateur(GARANTIE,int =0 , float= 0.0 ,int =1 ,string="",int =1 , string="", int = 1 , int =1 , string ="",float =12 ,string ="",string="");
    ~ordinateur();
void saisir();
void afficher(string="");
int getType(){return type;}
string getProcesseur(){return processeur;}
string getCouleur(){return couleur;}
int getMemoire(){return memoire;}
void setType(int t){type=t;}
void setProcesseur(string p){processeur=p;}
void setCouleur(string c){couleur=c;}
void setMemoire(int m){memoire =m;}
friend ostream& operator<<(ostream&,ordinateur&);
friend istream& operator>>(istream&,ordinateur&);
friend ostream& operator<<(ostream&,ordinateur*);
friend istream& operator>>(istream&,ordinateur*);

};

#endif // ORDINATEUR_H
