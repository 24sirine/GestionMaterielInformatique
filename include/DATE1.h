#ifndef DATE1_H
#define DATE1_H
#include<iostream>

#include<string>
using namespace std;
class DATE1{
     public:;
	int jour;
	int mois;
	int annee;
	public:
		DATE1(int=0,int=0,int=0);
		~DATE1(void);
void afficherdate(string="");
void saisirdate();

};

#endif // DATE1_H
