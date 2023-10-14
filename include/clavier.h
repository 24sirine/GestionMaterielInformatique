#ifndef CLAVIER_H
#define CLAVIER_H
#include <MaterielInfo.h>


class clavier : public MaterielInfo
{
int sansFil;
public:
    clavier(GARANTIE,int =0 , float= 0.0 ,int =1 ,string="",int=1);
    ~clavier();
void saisir();
void afficher(string="");
bool getSansFil(){return sansFil;}
void setSansFil( bool a){sansFil=a;}
friend ostream& operator<<(ostream&,clavier&);
friend istream& operator>>(istream&,clavier&);
friend ostream& operator<<(ostream&,clavier*);
friend istream& operator>>(istream&,clavier*);
};

#endif // CLAVIER_H
