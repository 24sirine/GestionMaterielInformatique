#ifndef SOURIS_H
#define SOURIS_H
#include <MaterielInfo.h>

class souris : public MaterielInfo
{
int sansFil;
public:
    souris(GARANTIE,int =0 , float= 0.0 ,int =1 ,string="",int=1);
    ~souris();
void saisir();
void afficher(string="");
bool getSansFil(){return sansFil;}
void setSansFil( bool a){sansFil=a;}
friend ostream& operator<<(ostream&,souris&);
friend istream& operator>>(istream&,souris&);
friend ostream& operator<<(ostream&,souris*);
friend istream& operator>>(istream&,souris*);
};

#endif // SOURIS_H
