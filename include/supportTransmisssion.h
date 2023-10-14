#ifndef SUPPORTTRANSMISSSION_H
#define SUPPORTTRANSMISSSION_H

#include <MaterielInfo.h>


class supportTransmisssion : public MaterielInfo
{
 int type;
 float longeur;
 public:
supportTransmisssion(GARANTIE,int =0 , float= 0.0 ,int =1 ,string="", int =0,float=0.0);
~supportTransmisssion();
void saisir();
void afficher(string="");
int getType(){return type;}
void setType(int a){type=a;}
float getLongeur(){return longeur;}
void setLongeur(float l){longeur=l;}
friend ostream& operator<<(ostream&,supportTransmisssion&);
friend istream& operator>>(istream&,supportTransmisssion&);
friend ostream& operator<<(ostream&,supportTransmisssion*);
friend istream& operator>>(istream&,supportTransmisssion*);
};

#endif // SUPPORTTRANSMISSSION_H
