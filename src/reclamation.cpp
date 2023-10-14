#include<iostream>
using namespace std;
#include"reclamation.h"
reclamation::reclamation(int r ,DATE1 d ,DATE1 a, float pr,int i):ref(r),date_rec(d),date_reg(a),prix(pr),id(i){
}


void reclamation::saisirRec(){
	cout<<"donner la reference"<<endl;
	cin>>ref;
	cout<<"donner la date de reclamation"<<endl;
	cout<<"saisir le jour"<<endl;
	cin>>date_rec.jour;
		cout<<"saisir le mois"<<endl;
		cin>>date_rec.mois;
			cout<<"saisir l'annee"<<endl;
			cin>>date_rec.annee;
	cout<<"donner la date de reglement"<<endl;
	cout<<"saisir le jour"<<endl;
	cin>>date_reg.jour;
		cout<<"saisir le mois"<<endl;
		cin>>date_reg.mois;
			cout<<"saisir l'annee"<<endl;
			cin>>date_reg.annee;
	cout<<"donner le prix"<<endl;
	cin>>prix;
	cout<<"donner l'id de l'utilisateur"<<endl;
	cin>>id;


}

void reclamation::afficher()
{
	cout<<"la reference est"<<"   "<<ref<<endl;
	cout<<"la date de reclamation est"<<"   "<<date_rec.jour<<"/"<<date_rec.mois<<"/"<<date_rec.annee<<endl;
	cout<<"la date de reglement est"<<"  "<<date_reg.jour<<"/"<<date_reg.mois<<"/"<<date_reg.annee<<endl;
	cout<<"le prix est"<<"  "<<prix<<endl;
	cout<<"l'id est'"<<"  "<<id<<endl;

}
