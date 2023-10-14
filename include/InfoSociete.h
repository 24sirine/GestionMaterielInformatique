#ifndef INFOSOCIETE_H
#define INFOSOCIETE_H
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
#include<vector>
class InfoSociete
{
vector<MaterielInfo*>tab;
public:
    InfoSociete();
    ~InfoSociete();
    void remplir();
    void afficher(string="");
    InfoSociete(const InfoSociete&);
    int taille(){return tab.size();}
    void ajouter(MaterielInfo*, int=0);
    void ajouter(clavier,int=0);
    void ajouter(tablette,int=0);
    void ajouter(souris,int=0);
    void ajouter(smartPhone,int=0);
    void ajouter(serveur, int=0);
    void ajouter(imprimanteScanner,int=0);
    void ajouter(ordinateur,int=0);
    void ajouter(supportStockage,int=0);
    void ajouter(supportTransmisssion,int=0);
    void supprimer(int=0);
    int rechercherParPrix(float );
    int rechercherParReference(int );
    int rechercherParStock(int);
    int rechercherParMarque(string );
    friend ostream& operator<<(ostream&,InfoSociete&);//affichage sur l'écran
    friend istream& operator>>(istream&,InfoSociete&); //lecture à partir du clavier
    friend ostream& operator<<(ostream&,InfoSociete*);//affichage(écriture)dans le fichier
    friend istream& operator>>(istream&,InfoSociete*);//lecture à partir du fichier
    //static void afficher(fstream&);
};

#endif // INFOSOCIETE_H
