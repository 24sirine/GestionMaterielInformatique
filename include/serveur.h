#ifndef SERVEUR_H
#define SERVEUR_H


#include <MaterielInfo.h>

class serveur: public MaterielInfo
{
int capacite;
string processeur;
public:
    serveur(GARANTIE,int =0 , float= 0.0 ,int =1 ,string="", int=12 ,string="");
    ~serveur();
void saisir();
void afficher(string="");
int getcapacite(){return capacite;}
void setcapacite(int c){capacite=c;}
string getProcesseur(){return processeur;}
void setprocesseur(string p){processeur=p;}
friend ostream& operator<<(ostream&,serveur&);
friend istream& operator>>(istream&,serveur&);
friend ostream& operator<<(ostream&,serveur*);
friend istream& operator>>(istream&,serveur*);
};

#endif // SERVEUR_H
