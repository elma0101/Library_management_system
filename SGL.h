#include<stdio.h>
#ifndef SGL_H_INCLUDED
#define SGL_H_INCLUDED

typedef struct livre{

  char titre[20],author[50],resume[1000];
  int date_expedition,nbr_pages,progres;

}livre;
typedef struct compte{

  char fullname[50],password[50];

}compte;
void gotoxy();
void ecrire_texte(char*);
void lire_texte(char*);
void print_title();
livre saisir_livre(char* fullname);
void afficher_livre(char* fullname,livre lv);
void traiter_compte();
int newregister();
int first_menu();
int main_menu(char*);
void nouveau_livre(char*);
void chercher_livre(char* );
void lister_livre(char* );
void supprimer_livre(char* );
void modifier_livre(char* );


#endif // SGL_H_INCLUDED
