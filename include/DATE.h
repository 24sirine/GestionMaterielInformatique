#ifndef DATE_H
#define DATE_H
#include"string"
using namespace std;

class date
{
int jour;
int mois;
int annee;
public:
    date(int=1 , int =1 , int = 2000);
    ~date();
   void afficherdate(string="");
   void saisirdate();
friend ostream& operator<<(ostream&,date&);
friend istream& operator>>(istream&,date&);
friend ostream& operator<<(ostream&,date*);
friend istream& operator>>(istream&,date*);
};

#endif // DATE_H
