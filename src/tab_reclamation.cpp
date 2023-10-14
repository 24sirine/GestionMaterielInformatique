

#include<iostream>
#include"tab_reclamation.h"
#include<vector>
using namespace std;

tab_reclamation::tab_reclamation(const tab_reclamation&w){
	reclamation* r;
	for(int i=0;i<w.tab.size();i++){
		r=new reclamation(*w.tab[i]);
		tab.push_back(r);
	}

}

void tab_reclamation::supprimerReclamation(int r)
{
	if (chercherReclamation(r)!=-1);
	   tab.erase(tab.begin()+chercherReclamation(r));



}
void tab_reclamation::remplir(){
	int rep;
	reclamation* r;
	DATE1 d(1,1,1);
DATE1 c(2,2,2);
	do{
		r=new reclamation(0,d,c,0,0);
		r->saisirRec();
		tab.push_back(r);
		cout<<"\n VOULEZ VOUS RAJOUTER UN RECLAMATION?"<<endl;
		cout<<"\n 1 OUI"<<endl;
		cout<<"\n 2 NON"<<endl;
		cin>>rep;
		}
		while(rep==1);
}
tab_reclamation::~tab_reclamation(void){
	for(int i=0;i<tab.size();i++)
	  delete tab[i];
    tab.clear();
}
void tab_reclamation::ajouter(reclamation r,int ind){
	reclamation* e=new reclamation(r);
	tab.insert(tab.begin()+ind,e);

}

int tab_reclamation::chercherReclamation(int r){
    int j=0;
for(unsigned int i=0;i<tab.size();i++){
	  if( tab[i]->getref()==r){
            j=0;
	    return(i);
	    }else{
	     j++;
	     return(-1);}
}
if (j>0){cout<<"cette reclamation n'existe pas"<<endl;}
}

void  tab_reclamation::afficher()
{
cout<<"****AFFICHAGE DE TOUS LES reclamations***"<<endl;
for (int i=0;i<tab.size();i++)
    tab[i]->afficher();
}



