#ifndef TAB_RECLAMATION_H
#define TAB_RECLAMATION_H
#include "reclamation.h"
#include<iostream>
#include<vector>


using namespace std;
class tab_reclamation
{
vector<reclamation*> tab;
public:
	tab_reclamation(){};
	void remplir();
	void supprimerReclamation(int);
	int chercherReclamation (int);
	void ajouter(reclamation,int);
	~tab_reclamation(void);
	tab_reclamation(const tab_reclamation&);
	void afficher();
};



#endif // TAB_RECLAMATION_H
