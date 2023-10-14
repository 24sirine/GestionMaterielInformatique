#ifndef GARANTIE_H
#define GARANTIE_H
#include"DATE.h"

class GARANTIE
{public:
    date dateDebut;
    date dateFin;
public:
    GARANTIE(date,date);
    ~GARANTIE();
    void affichergarantie(string="");
    void saisirgarantie();
friend ostream& operator<<(ostream&,GARANTIE&);
friend istream& operator>>(istream&,GARANTIE&);
friend ostream& operator<<(ostream&,GARANTIE*);
friend istream& operator>>(istream&,GARANTIE*);
};

#endif // GARANTIE_H
