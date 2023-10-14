#include <iostream>
#include <Windows.h>
#include <mysql.h>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include"MaterielInfo.h"
#include"supportStockage.h"
#include"supportTransmisssion.h"
#include"InfoSociete.h"
#include"ordinateur.h"
#include"clavier.h"
#include"souris.h"
#include"InfoSociete.h"
#include<fstream>
#include <iostream>
#include "reclamation.h"
#include "tab_reclamation.h"
#include "DATE1.h"


//PROJET DE GROUPE CHEHINE BEN SALAH MANEL BEN MOULOUD ET SIRINE BOURBIAA


using namespace std;
MYSQL* admin_connectdatabase(){

    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "admin",3306, NULL, 0);

    if(conn){
        cout<<"connected to  ADMIN database"<<endl;
        return conn;
    }
    else{
        cout<<"failed to connnect to the ADMIN database"<<endl;
        return conn;
    }
}
MYSQL* employe_connectdatabase(){

    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "employe",3306, NULL, 0);

    if(conn){
        cout<<"connected to  EMPLOYE database"<<endl;
        return conn;
    }
    else{
        cout<<"failed to connnect to the EMPLOYE database"<<endl;
        return conn;
    }
}

void insertion_employe(MYSQL* conn){
    int qstate=0;
    stringstream ss;
    string username,password;
    cout<<"donner le username"<<endl;
    cin>>username;
    cout<<"donner le password"<<endl;
    cin>>password;
    ss<<"insert into employe(username,password) values ('"+username+"','"+password+"')";
    string query=ss.str();
    const char* q=query.c_str();
    qstate=mysql_query(conn,q);
    if(qstate==0){
        cout<<"EMPLOYE inserted"<<endl;
    }
    else {cout<<" EMPLOYE insertion failed"<<endl;}
}

void afficher_employe(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES * res;
    if(conn){
        int qstate=mysql_query(conn,"select * from employe");
        if(qstate==0){
            res=mysql_store_result(conn);
            int c=mysql_num_fields(res);
            cout<<"AFFICHAGE DE LA BASE DE DONNEES D'EMPLOYE "<<endl;
            cout<<"ID "<<"USERNAME   "<<"PASSWORD  "<<endl;
            while(row=mysql_fetch_row(res)){
                for(int i=0;i<c;i++)
                    cout<<"\t"<<row[i];
                cout<<endl;
            }
        }
    }
    else{
        cout<<"erreur d'affichage EMPLOYE "<<endl;
    }
}
void insertion_admin(MYSQL* conn){
    int qstate=0;
    stringstream ss;
    string username,password;
    cout<<"donner le username"<<endl;
    cin>>username;
    cout<<"donner le password"<<endl;
    cin>>password;
    ss<<"insert into admin(username,password) values ('"+username+"','"+password+"')";
    string query=ss.str();
    const char* q=query.c_str();
    qstate=mysql_query(conn,q);
    if(qstate==0){
        cout<<" ADMIN inserted"<<endl;
    }
    else {cout<<"ADMIN insertion failed"<<endl;}
}
void afficher_admin(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES * res;
    if(conn){
        int qstate=mysql_query(conn,"select * from admin");
        if(qstate==0){
            res=mysql_store_result(conn);
            int c=mysql_num_fields(res);
            cout<<"AFFICHAGE DE LA BASE DE DONNEES D'ADMIN"<<endl;
            cout<<"ID "<<"USERNAME   "<<"PASSWORD  "<<endl;
            while(row=mysql_fetch_row(res)){
                for(int i=0;i<c;i++)
                    cout<<"\t"<<row[i];
                cout<<endl;
            }
        }
    }
    else{
        cout<<"erreur d'affichage"<<endl;
    }
}

void registration(MYSQL* conn_admin,MYSQL* conn_employe){
    int choix;
    cout<<"    1 REGISTER AS ADMIN "<<endl;
    cout<<"    2 REGISTER AS EMPLOYE "<<endl;
    cin>>choix;
    if( choix== 1){
        insertion_admin(conn_admin);
    }
    else if(choix==2){
        insertion_employe(conn_employe);
    }

}

BOOL login_admin(MYSQL* conn){
    string user,pwd;
    MYSQL_ROW row;
    MYSQL_RES * res;
    int i=0;
    cout<<"LOGIN AS AN ADMIN"<<endl;
    cout<<"enter your username"<<endl;
    cin>>user;
    cout<<"enter your password"<<endl;
    cin>>pwd;
    if(conn){
        int qstate=mysql_query(conn,"select * from admin");
        if(qstate==0){
            res=mysql_store_result(conn);
            int c=mysql_num_fields(res);
            while(row=mysql_fetch_row(res)){
                if(row[1]==user && row[2]==pwd)
                    {
                        i=0;
                        break;
                        }
                else{
                        i++;
                        continue;
                }
            }
            if(i==0){
                cout<<"YOUR ARE CONNECTED AS AN ADMIN "<<endl;
                return true;
            }
            else{
                cout<<"YOUR ARE NOT AN ADMIN "<<endl;
                system("pause");
                system("cls");
                login_admin(conn);
            }
        }
    }
    else{
        cout<<"FAILED TO CONNECT TO ADMIN DATABASE"<<endl;
    }
}


BOOL login_employe(MYSQL* conn){
    string user,pwd;
    MYSQL_ROW row;
    MYSQL_RES * res;
    int i=0;
    cout<<"LOGIN AS AN EMPLOYE "<<endl<<endl;
    cout<<"enter your username"<<endl;
    cin>>user;
    cout<<"enter your password"<<endl;
    cin>>pwd;
    if(conn){
        int qstate=mysql_query(conn,"select * from employe");
        if(qstate==0){
            res=mysql_store_result(conn);
            int c=mysql_num_fields(res);
            while(row=mysql_fetch_row(res)){
                if(row[1]==user && row[2]==pwd)
                    {
                        i=0;
                        break;
                        }
                else{
                        i++;
                        continue;
                }
            }
            if(i==0){
                cout<<"YOUR ARE CONNECTED AS AN EMPLOYE "<<endl;
                return true;
            }
            else{
                cout<<"CHECK USERNAME AND PASSWORD "<<endl;
                login_employe(conn);
            }
        }
    }
    else{
        cout<<"FAILED TO CONNECT TO EMPLOYE DATABASE"<<endl;
    }
}


//PROJET DE GROUPE CHEHINE BEN SALAH MANEL BEN MOULOUD ET SIRINE BOURBIAA

void recherche_admin(MYSQL* conn){
    string id;
    MYSQL_ROW row;
    MYSQL_RES * res;
    int i=0;
    cout<<"donner l id d'ADMIN a chercher "<<endl;
    cin>>id;
    if(conn){
        int qstate=mysql_query(conn,"select * from admin");
        if(qstate==0){
            res=mysql_store_result(conn);
            int c=mysql_num_fields(res);
            while(row=mysql_fetch_row(res)){
                if(row[0]==id)
                    {
                     cout<<" ID : "<<row[0]<<" USERNAME : "<<row[1]<<"PASSWORD : "<<row[2]<<endl;
                     i++;
                        }
                else{
                        i=0;
                        continue;
                }
            }
            if(i==0){
                cout<<"ADMIN NOT FOUND "<<endl;

            }
        }
    }
    else{
        cout<<"FAILED TO CONNECT TO ADMIN DATABASE"<<endl;
    }
}
void recherche_employe(MYSQL* conn){
    string id;
    MYSQL_ROW row;
    MYSQL_RES * res;
    int i=0;
    cout<<"donner l id d'EMPLOYE a chercher "<<endl;
    cin>>id;
    if(conn){
        int qstate=mysql_query(conn,"select * from employe");
        if(qstate==0){
            res=mysql_store_result(conn);
            int c=mysql_num_fields(res);
            while(row=mysql_fetch_row(res)){
                if(row[0]==id)
                    {
                     cout<<" ID : "<<row[0]<<" USERNAME : "<<row[1]<<"PASSWORD : "<<row[2]<<endl;
                     i++;
                        }
                else{
                        i=0;
                        continue;
                }
            }
            if(i==0){
                cout<<"EMPLOYE NOT FOUND "<<endl;

            }
        }
    }
    else{
        cout<<"FAILED TO CONNECT TO EMPLOYE DATABASE"<<endl;
    }
}
void delete_admin(MYSQL* conn_admin){
    int qstate=0;
    stringstream ss;
    string id;
    cout<<"donner l'ID d'ADMIN "<<endl;
    cin>>id;

    ss<<"delete from admin where id = "+id;
    string query=ss.str();
    const char* q=query.c_str();
    qstate=mysql_query(conn_admin,q);
    if(qstate==0){
        cout<<"ADMIN DELETED"<<endl;
    }
    else {cout<<" "<<endl;}

}
void delete_employe(MYSQL* conn_employe){
    int qstate=0;
    stringstream ss;
    string id;
    cout<<"donner id a supprimer "<<endl;
    cin>>id;

    ss<<"delete from employe where id = "+id;
    string query=ss.str();
    const char* q=query.c_str();
    qstate=mysql_query(conn_employe,q);
    if(qstate==0){
        cout<<"employe DELETED"<<endl;
    }
    else {cout<<"  "<<endl;}

}
void menu_ajouter_materiel(InfoSociete m)
 { int ch;
    cout<<"------------------------------------------------"<<endl;
    cout<<"  1. AJOUTER clavier"<<endl;
    cout<<"  2. AJOUTER tablette"<<endl;
    cout<<"  3. AJOUTER souris"<<endl;
    cout<<"  4. AJOUTER smart phone"<<endl;
    cout<<"  5. AJOUTER serveur"<<endl;
    cout<<"  6. AJOUTER imprimante / scanner"<<endl;
    cout<<"  7. AJOUTER ordinateur"<<endl;
    cout<<"  8. AJOUTER support de stockage"<<endl;
    cout<<"  9. AJOUTER support de transmission"<<endl;
    cout<<" 10. QUITTER       "<<endl;
cin>>ch;
 date d1=(25,11,2000);
date d2=(31,12,2021);
GARANTIE g(d1,d2);
if(ch==1){ clavier c(g);
cin>>c;
m.ajouter(c);
m.afficher();
}
 if(ch==2){ tablette t(g);
 cin>>t;
 m.ajouter(t);
m.afficher();
}
if(ch==3){ souris s(g);
cin>>s;
m.ajouter(s);
m.afficher();
}
if(ch==4){ smartPhone sp(g);
cin>>sp;
m.ajouter(sp)   ;
m.afficher();
}
if(ch==5){ serveur ser(g);
cin>>ser;
m.ajouter(ser);
m.afficher();
}
if(ch==6){imprimanteScanner is(g);
cin>>is;
m.ajouter(is);
m.afficher();

}
if(ch==7){ ordinateur o(g);
cin>>o;
m.ajouter(o);
m.afficher();
}
if(ch==8){ supportStockage ss(g);
cin>>ss;
m.ajouter(ss);
m.afficher();
}
if(ch==9){ supportTransmisssion st(g);
cin>>st;
m.ajouter(st);
m.afficher();
}

}

//PROJET DE GROUPE CHEHINE BEN SALAH MANEL BEN MOULOUD ET SIRINE BOURBIAA

void menu_rechercher_materiel(InfoSociete m)
{ int ch;
    cout<<"------------------------------------------------"<<endl;
    cout<<"  1. Recherche selon le prix du materiel"<<endl;
    cout<<"  2. Recherche selon la reference du materiel"<<endl;
    cout<<"  3. Recherche selon le stock du materiel"<<endl;
    cout<<"  4. Recherche selon la marque du materiel"<<endl;
    cout<<"  5. QUITTER      "<<endl;

cin>>ch;
if(ch==1)
{ float pr;
    cout<<"saisir le prix "<<endl;
    cin>>pr;
    int t= m.rechercherParPrix(pr );
    if (t==-1) cout<<"le materiel choisit est introuvable!"<<endl;
else cout<<"le materiel existe et son indice est:"<<"   "<<t<<endl;

}
if (ch==2)
{ int refe;
    cout<<"saisir la référence "<<endl;
    cin>>refe;
    int t= m.rechercherParReference(refe);
    if (t==-1) cout<<"le materiel choisit est introuvable!"<<endl;
else cout<<"le materiel existe et son indice est:"<<"   "<<t<<endl;

}
if (ch==3)
    { int st;
    cout<<"saisir le stock "<<endl;
    cin>>st;
    int t= m.rechercherParReference(st);
    if (t==-1) cout<<"le materiel choisit est introuvable!"<<endl;
else cout<<"le materiel existe et son indice est:"<<"   "<<t<<endl;

}
if (ch==4)
    { string ma;
    cout<<"saisir la marque"<<endl;
    cin>>ma;
    int t= m.rechercherParMarque(ma);
    if (t==-1) cout<<"le materiel choisit est introuvable!"<<endl;
else cout<<"le materiel existe et son indice est:"<<"   "<<t<<endl;

}
if(ch==5){ exit(1);}
}
void menu_gestion_stock(InfoSociete m){
    int choix;
    int indice_supprimer;
    cout<<"                MENU GESTION STOCK "<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"                1 AJOUTER MATERIEL           "<<endl;
    cout<<"                2 RECHERCHER MATERIEL           "<<endl;
    cout<<"                3 SUPPRIMER  MATERIEL           "<<endl;
    cout<<"                4 AFFICHER  MATERIEL           "<<endl;
    cout<<"                5 DECONNEXION           "<<endl;
    cin>>choix;
    if(choix==1){
        menu_ajouter_materiel(m);
        menu_gestion_stock(m);
    }
    if(choix==2){
        menu_rechercher_materiel(m);
        menu_gestion_stock(m);
    }
    if(choix==3){
        cout<<"DONNER L'INDICE DE MATERIEL A SUPPRIMER "<<endl;
        cin>>indice_supprimer;
        m.supprimer(indice_supprimer);
        m.afficher();
        menu_gestion_stock(m);
    }
    if(choix==4){
        m.afficher();
        menu_gestion_stock(m);
    }

}

void menu_reclamation(tab_reclamation tab)
{
    int i,indice;
     cout<<"*********************"<<endl;
    cout<<"  1.ajouter reclamation"<<endl;
    cout<<"  2.chercher reclamation"<<endl;
    cout<<"  3.supprimer reclamation"<<endl;
    cout<<"  4.afficher() "<<endl;
    cin>>i;
    DATE1 d1=(7,2,2000);
    DATE1 d2=(29,5,2022);
    if (i==1){
    reclamation r(0,d1,d2,0,0);
    r.saisirRec();
    int indice=0;
    tab.ajouter(r,indice);
    indice++;
    menu_reclamation(tab);

    }
    if (i==2){
          int ref;
          cout<<"saisir la reference"<<endl;
          cin>>ref;
          int t=tab.chercherReclamation(ref);
          if(t==-1) cout<<"reclamation n'existe pas"<<endl;
          else cout<<"reclamation existe et son indice est:"<<"  "<<t<<endl;
          menu_reclamation(tab);
    }
   if(i==3) {
        int ref;
    cout<<"donner la reference du reclamation a supprimer"<<endl;
    cin>>ref;
    tab.supprimerReclamation(ref);
    menu_reclamation(tab);
    }
   if(i==4){
   tab.afficher();
   menu_reclamation(tab);
   }
}

//PROJET DE GROUPE CHEHINE BEN SALAH MANEL BEN MOULOUD ET SIRINE BOURBIAA

int menu_admin(MYSQL* conn_employe,MYSQL* conn_admin){
    int choix,nbemploye;

    cout<<"===================================================== \n";
    cout<<"                    \t\tMENU \t \n ";
    cout<<"===================================================== \n";
    cout<<"                    1. AJOUTER EMPLOYE \n";
    cout<<"                    2. AFFICHER EMPLOYE \n";
    cout<<"                    3. AJOUTER ADMIN \n";
    cout<<"                    4. AFFICHER ADMIN \n";
    cout<<"                    5. RECHERCHE ADMIN  \n";
    cout<<"                    6. RECHERCHE EMPLOYE  \n";
    cout<<"                    7. DELETE ADMIN  \n";
    cout<<"                    8. DELETE EMPLOYE  \n";
    cout<<"                    9. GESTION ET CONTROLE DE STOCK\n";
    cout<<"                    10. GESTION DES RECLAMATIONS  \n";
    cout<<"                    11. DECONNEXION \n";

    cin>>choix;

    if(choix==1){
        system("cls");
         cout<<"donner le nombre d'EMPLOYE a inserer"<<endl;
         cin>>nbemploye;
         for(int i=0;i<nbemploye;i++){
            insertion_employe(conn_employe);
         }
         menu_admin(conn_employe,conn_admin);
    }
    else if (choix==2){
         afficher_employe(conn_employe);
         menu_admin(conn_employe,conn_admin);
    }
    else if(choix==3){
        system("cls");
         cout<<"donner le nombre des ADMIN a inserer"<<endl;
         cin>>nbemploye;
         for(int i=0;i<nbemploye;i++){
            insertion_admin(conn_admin);
         }
         menu_admin(conn_employe,conn_admin);
    }

    else if (choix==4){
         afficher_admin(conn_admin);
         menu_admin(conn_employe,conn_admin);
    }
    else if (choix==5){
            recherche_admin(conn_admin);
            menu_admin(conn_employe,conn_admin);
    }
    else if (choix==6){
            recherche_employe(conn_employe);
            menu_admin(conn_employe,conn_admin);
    }
    else if(choix==7){
         delete_admin(conn_admin);
         menu_admin(conn_employe,conn_admin);
    }
    else if(choix==8){
         delete_employe(conn_employe);tab_reclamation tab;

         menu_admin(conn_employe,conn_admin);
    }
    else if(choix==9){
        InfoSociete m;
        fstream f("c:\\fichier\\fichier.txt");
        if(!f.is_open()){cout<<"-" ;}
        f.seekp(0,ios::end);
        cout<<"   REMPLIR LE STOCK MATERIEL  "<<endl;
        cin>>m;
        f<<&m;
        cout<<m;
        menu_gestion_stock(m);
    }
    else if(choix==10){
        tab_reclamation tab;
        cout<<"remplir le tableau des reclamation"<<endl;
        tab.remplir();
        menu_reclamation(tab);

    }
    else if(choix==11){
        return 5;
    }
}
//PROJET DE GROUPE CHEHINE BEN SALAH MANEL BEN MOULOUD ET SIRINE BOURBIAA

int menu_employe(MYSQL* conn_employe,MYSQL* conn_admin){
    int choix;
    system("cls");
    cout<<"===================================================== \n";
    cout<<"                    \t\tMENU \t \n ";
    cout<<"===================================================== \n";
    cout<<"                    1.   RECLAMATION  \n";
    cout<<"                                      \n";
    cout<<"                    2.DECONNEXION \n";
    cin>>choix;
    if(choix==2){
        return 1;
    }
    if(choix==1){
            tab_reclamation tab;
        menu_reclamation(tab);
    }
}

int main()
{
   int choix;
    MYSQL *conn_admin=admin_connectdatabase();
    MYSQL *conn_employe=employe_connectdatabase();
    //menu(conn_employe,conn_admin);
    cout<<"===================================================== \n";
    cout<<"                    \t\tWELCOME \t \n ";
    cout<<"===================================================== \n";
    cout<<"    \t\t1  LOGIN AS ADMINISTRATOR \t \n "<<endl;
    cout<<"    \t\t2  LOGIN AS EMPLOYE \t \n "<<endl;
    cout<<"    \t\t3  REGISTRATION \t \n "<<endl;
    cout<<"    \t\t4  CLOSE PROGRAM \t \n "<<endl;
    cout<<"===================================================== \n";
    cin>>choix;

    if (choix==1){
            system("cls");
        if (login_admin(conn_admin)==true){
                if(menu_admin(conn_employe,conn_admin)==5){
                    system("cls");
                    main();
                }
                }
        else {
            cout<<"NOT ADMIN TRY LATER "<<endl;

    }
    }
    if (choix==2){
        system("cls");
        if (login_employe(conn_employe)==true){
               if(menu_employe(conn_employe,conn_admin)==1){

                    main();
                }
        }
        else {cout<<"NOT EMPLOYE TRY LATER "<<endl;}
    }
    if(choix==3){
        registration(conn_admin,conn_employe);
        main();

    }
    if(choix==4){
        exit(1);
    }



    return 0;
}
//PROJET DE GROUPE CHEHINE BEN SALAH MANEL BEN MOULOUD ET SIRINE BOURBIAA
//PROJET DE GROUPE CHEHINE BEN SALAH MANEL BEN MOULOUD ET SIRINE BOURBIAA
