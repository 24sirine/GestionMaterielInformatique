 #include"InfoSociete.h"
 #include"ordinateur.h"
  #include"souris.h"
 #include"clavier.h"
 #include"tablette.h"
 #include"imprimanteScanner.h"
 #include"supportStockage.h"
 #include"supportTransmisssion.h"
#include"serveur.h"
#include"smartPhone.h"
#include"MaterielInfo.h"
#include<iostream>
#include<typeinfo>
#include<ios>
#include<fstream>
using namespace std;
 InfoSociete:: InfoSociete()
 {
  //constructeur vide
 }
InfoSociete::~InfoSociete()
{
    for (int i=0;i<tab.size();i++)
        delete tab[i];
    tab.clear();
}
void InfoSociete::remplir()
{
  date d1=(25,11,2000);
date d2=(31,12,2021);
GARANTIE g(d1,d2);
char rep;
MaterielInfo*q;
int choix;
do
{
 cout<<"taper 1-ordinateur, 2-smart phone , 3- tablette ,4- serveur, 5-imprimante ou scanner , 6- souris , 7-clavier , 8-support de stockage, 9- support de transmission"<<endl;
 cin>>choix;
 if(choix==1) q= new ordinateur(g);
 else if (choix==2) q= new smartPhone(g);
  else if (choix==3) q= new tablette(g);
  else if (choix==4) q= new serveur(g);
  else if (choix==5) q= new imprimanteScanner(g);
  else if (choix==6) q= new souris(g);
  else if (choix==7) q= new clavier(g);
  else if (choix==8) q= new supportStockage(g);
  else if (choix==9) q= new supportTransmisssion(g);
  else break;
q->saisir();
tab.push_back(q);
cout<<" voulez -vous ajouter un autre matériel? si oui tapez 'o' ou bien 'O'"<<endl;
cin>>rep;
}
while(rep=='o' || rep=='O');
}
void  InfoSociete::afficher(string msg)
{
cout<<msg<<endl;
cout<<"*****AFFICHAGE DE TOUS LES MATERIELS DE SOCIETE****"<<endl;
for (int i=0;i<tab.size();i++)
    tab[i]->afficher();
}
InfoSociete::InfoSociete(const InfoSociete&w)
{
    MaterielInfo *e;
    for (int i=0 ;i<w.tab.size();i++)
    {
        if (typeid(*w.tab[i])== typeid(ordinateur))
            e= new ordinateur(static_cast<const ordinateur&>(*w.tab[i]));
        else if (typeid(*w.tab[i])== typeid(serveur))
            e= new serveur(static_cast<const serveur&>(*w.tab[i]));
        else if (typeid(*w.tab[i])== typeid(tablette))
            e= new tablette(static_cast<const tablette&>(*w.tab[i]));
            else if (typeid(*w.tab[i])== typeid(smartPhone))
            e= new smartPhone(static_cast<const smartPhone&>(*w.tab[i]));
            else if (typeid(*w.tab[i])== typeid(clavier))
            e= new clavier(static_cast<const clavier&>(*w.tab[i]));
            else if (typeid(*w.tab[i])== typeid(souris))
            e= new souris(static_cast<const souris&>(*w.tab[i]));
            else if (typeid(*w.tab[i]) ==typeid(imprimanteScanner))
            e= new imprimanteScanner(static_cast<const imprimanteScanner&>(*w.tab[i]));
            else if (typeid(*w.tab[i])== typeid(supportStockage))
            e= new supportStockage(static_cast<const supportStockage&>(*w.tab[i]));
            else if (typeid(*w.tab[i])== typeid(supportTransmisssion))
            e= new supportTransmisssion(static_cast<const supportTransmisssion&>(*w.tab[i]));
        tab.push_back(e);



    }
}

    void InfoSociete::ajouter(clavier q,int ind)
    {
        MaterielInfo *e= new clavier(q);
        tab.insert(tab.begin()+ind,e);
    }

void InfoSociete::ajouter(tablette t,int ind)
    {
        MaterielInfo *e= new tablette(t);
        tab.insert(tab.begin()+ind,e);
    }
    void InfoSociete::ajouter(souris q,int ind)
    {
        MaterielInfo *e= new souris(q);
        tab.insert(tab.begin()+ind,e);
    }
    void InfoSociete::ajouter(smartPhone q,int ind)
    {
        MaterielInfo *e= new smartPhone(q);
        tab.insert(tab.begin()+ind,e);
    }
    void InfoSociete::ajouter(serveur q, int ind)
    {

        MaterielInfo *e= new serveur(q);
        tab.insert(tab.begin()+ind,e);

    }
    void InfoSociete::ajouter(imprimanteScanner q,int ind)
   {
        MaterielInfo *e= new imprimanteScanner(q);
        tab.insert(tab.begin()+ind,e);
    }
    void InfoSociete::ajouter(ordinateur q,int ind)
    {
        MaterielInfo *e= new ordinateur(q);
        tab.insert(tab.begin()+ind,e);
    }
    void InfoSociete::ajouter(supportStockage q,int ind)
    {
        MaterielInfo *e= new supportStockage(q);
        tab.insert(tab.begin()+ind,e);
    }
    void InfoSociete::ajouter(supportTransmisssion q,int ind)
  {
        MaterielInfo *e= new supportTransmisssion(q);
        tab.insert(tab.begin()+ind,e);
    }
    void InfoSociete::supprimer(int ind)
    {
     delete tab[ind];
     tab.erase(tab.begin()+ind);
    }
void InfoSociete::ajouter(MaterielInfo*q, int ind)
{
tab.insert(tab.begin()+ind,q);

}

    int InfoSociete::rechercherParPrix(float p)
    {

       int a=-1;
       for (int i=0;i<tab.size();i++)
       {if ((tab[i]->getPrix()==p))
        a=i;
        }
        return a;

    }
    int InfoSociete::rechercherParReference(int r)
    {

       int a=-1;
       for (int i=0;i<tab.size();i++)
       {if ((tab[i]->getReference()==r))
        a=i;}
        return a;
    }
    int InfoSociete::rechercherParStock(int s)
    {

       int a=-1;
       for (int i=0;i<tab.size();i++)
       {if ((tab[i]->getStock()==s))
        a=i;}
        return a;
    }
    int InfoSociete::rechercherParMarque(string m)
    {

       int a=-1;
       for (int i=0;i<tab.size();i++)
       {if ((tab[i]->getMarque()==m))
        a=i;}
        return a;
    }
 ostream& operator<<(ostream& out,InfoSociete&c)
 { for (int i=0 ;i<c.tab.size();i++)
     {if (typeid(*c.tab[i])==typeid(ordinateur))
        out<<(static_cast< ordinateur&>(*c.tab[i]));//appel de l'operateur de classe ordinateur
     else if(typeid(*c.tab[i])==typeid(clavier))
        out<<static_cast< clavier&>(*c.tab[i]);//appel de l'operateur de classe clavier
     else if(typeid(*c.tab[i])==typeid(souris))
        out<<static_cast< souris&>(*c.tab[i]);//appel de l'operateur de classe souris
      else if(typeid(*c.tab[i])==typeid(tablette))
        out<<static_cast< tablette&>(*c.tab[i]);//appel de l'operateur de classe tablette
         else if(typeid(*c.tab[i])==typeid(smartPhone))
        out<<static_cast< smartPhone&>(*c.tab[i]);//appel de l'operateur de classe smartPhone
         else if(typeid(*c.tab[i])==typeid(imprimanteScanner))
        out<<static_cast< imprimanteScanner&>(*c.tab[i]);//appel de l'operateur de classe imprimanteScanner
         else if(typeid(*c.tab[i])==typeid(serveur))
        out<<static_cast< serveur&>(*c.tab[i]);//appel de l'operateur de classe serveur
         else if(typeid(*c.tab[i])==typeid(supportStockage))
        out<<static_cast< supportStockage&>(*c.tab[i]);//appel de l'operateur de classe supportStockage
         else if(typeid(*c.tab[i])==typeid(supportTransmisssion))
        out<<static_cast< supportTransmisssion&>(*c.tab[i]);//appel de l'operateur de classe supportTransmisssion

        }
        return out;
 }
  istream& operator>>(istream& in,InfoSociete&c)
  {
       date d1=(25,11,2000);
date d2=(31,12,2021);
GARANTIE g(d1,d2);
      int choix;
      char rep;
      do{
      cout<<"taper 1-ordinateur, 2-smart phone , 3- tablette ,4- serveur, 5-imprimante ou scanner , 6- souris , 7-clavier , 8-support de stockage, 9- support de transmission"<<endl;
 in>>choix;
 if(choix==1)
 {ordinateur*q= new ordinateur(g);
 in>>*q;
 c.tab.push_back(q);
 }
else if(choix==2)
 {smartPhone*q= new smartPhone(g);
 in>>*q;
 c.tab.push_back(q);
 }
 else if(choix==3)
 {tablette*q= new tablette(g);
 in>>*q;
 c.tab.push_back(q);
 }
 else if(choix==4)
 {serveur*q= new serveur(g);
 in>>*q;
 c.tab.push_back(q);
 }
 else if(choix==5)
 {imprimanteScanner*q= new imprimanteScanner(g);
 in>>*q;
 c.tab.push_back(q);
 }
 else if(choix==6)
 {souris*q= new souris(g);
 in>>*q;
 c.tab.push_back(q);
 }
 else if(choix==7)
 {clavier*q= new clavier(g);
 in>>*q;
 c.tab.push_back(q);
 }
 else if(choix==8)
 {supportStockage*q= new supportStockage(g);
 in>>*q;
 c.tab.push_back(q);
 }
 else if(choix==9)
 {supportTransmisssion*q= new supportTransmisssion(g);
 in>>*q;
 c.tab.push_back(q);
 }
cout<<" voulez -vous ajouter un autre materiel? si oui tapez 'o' ou bien 'O'"<<endl;
in>>rep;
}
while(rep=='o' || rep=='O');
return in ;
}

ostream& operator<<(ostream&out,InfoSociete*c)
{
  for (int i=0 ;i<c->tab.size();i++)
     {if (typeid(*c->tab[i])==typeid(ordinateur))
        out<<(static_cast< ordinateur&>(*c->tab[i]));//appel de l'operateur de classe ordinateur
     else if(typeid(*c->tab[i])==typeid(clavier))
        out<<static_cast< clavier&>(*c->tab[i]);//appel de l'operateur de classe clavier
     else if(typeid(*c->tab[i])==typeid(souris))
        out<<static_cast< souris&>(*c->tab[i]);//appel de l'operateur de classe souris
      else if(typeid(*c->tab[i])==typeid(tablette))
        out<<static_cast< tablette&>(*c->tab[i]);//appel de l'operateur de classe tablette
         else if(typeid(*c->tab[i])==typeid(smartPhone))
        out<<static_cast< smartPhone&>(*c->tab[i]);//appel de l'operateur de classe smartPhone
         else if(typeid(*c->tab[i])==typeid(imprimanteScanner))
        out<<static_cast< imprimanteScanner&>(*c->tab[i]);//appel de l'operateur de classe imprimanteScanner
         else if(typeid(*c->tab[i])==typeid(serveur))
        out<<static_cast< serveur&>(*c->tab[i]);//appel de l'operateur de classe serveur
         else if(typeid(*c->tab[i])==typeid(supportStockage))
        out<<static_cast< supportStockage&>(*c->tab[i]);//appel de l'operateur de classe supportStockage
         else if(typeid(*c->tab[i])==typeid(supportTransmisssion))
        out<<static_cast< supportTransmisssion&>(*c->tab[i]);//appel de l'operateur de classe supportTransmisssion
}
return out;
}
 istream& operator>>(istream& in,InfoSociete*c)
    {
            date d1=(25,11,2000);
date d2=(31,12,2021);
GARANTIE g(d1,d2);
int choix;
in.seekg(0);
while(1)
{
 in>>choix;
 if (in.eof())break;
 if(choix==1)
 {ordinateur*q= new ordinateur(g);
 in>>*q;
 c->tab.push_back(q);
 }
else if(choix==2)
 {smartPhone*q= new smartPhone(g);
 in>>*q;
 c->tab.push_back(q);
 }
 else if(choix==3)
 {tablette*q= new tablette(g);
 in>>*q;
 c->tab.push_back(q);
 }
 else if(choix==4)
 {serveur*q= new serveur(g);
 in>>*q;
 c->tab.push_back(q);
 }
 else if(choix==5)
 {imprimanteScanner*q= new imprimanteScanner(g);
 in>>*q;
 c->tab.push_back(q);
 }
 else if(choix==6)
 {souris*q= new souris(g);
 in>>*q;
 c->tab.push_back(q);
 }
 else if(choix==7)
 {clavier*q= new clavier(g);
 in>>*q;
 c->tab.push_back(q);
 }
 else if(choix==8)
 {supportStockage*q= new supportStockage(g);
 in>>*q;
 c->tab.push_back(q);
 }
 else if(choix==9)
 {supportTransmisssion*q= new supportTransmisssion(g);
 in>>*q;
 c->tab.push_back(q);
 }
}
return in ;
    }

