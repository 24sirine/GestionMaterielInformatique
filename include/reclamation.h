#ifndef RECLAMATION_H
#define RECLAMATION_H

#include"DATE1.h"
#include<iostream>
#pragma once
class reclamation
{

		int ref;//reference du reclamation unique
		DATE1 date_rec;
		DATE1 date_reg;
		float prix;
		int id;// l'id de la personne qui a effectué cette reclamation
		public:
			reclamation(int ,DATE1 ,DATE1, float , int);
			void saisirRec();
			void afficher();
			int getref(){return(ref);};
			~reclamation(void){};

		};


#endif // RECLAMATION_H
