#include"SGL.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void ecrire_texte(char *txt)
{

    int i=0;
    while(txt[i]!='\0')
    {
        if(txt[i]==' ')
            txt[i]='_';
        i++;
    }
}
void lire_texte(char *txt)
{

    int i=0;
    while(txt[i]!='\0')
    {
        if(txt[i]=='_')
            txt[i]=' ';
        i++;
    }
}
void print_title()
{
  int i;
  char name[37]={" My local library "};

    system("cls");

    gotoxy(35,0);
    for(i=0;i<10;i++)
    { printf("\x4");
      Sleep(20);
    }
    for(i=0;i<18;i++)
    { printf(" %c",name[i]);
      Sleep(20);
    }
     for(i=0;i<10;i++)
    { printf("\x4");
      Sleep(20);
    }

}
livre saisir_livre(char *fullname)
{
    FILE *fp;
    livre lv;
    int i=0;

    system("cls");
    printf("\nTitre : ");
    gets(lv.titre);
    printf("\nAutheur : ");
    gets(lv.author);
    printf("\nDate d'expedition : ");
    scanf("%d",&lv.date_expedition);
    printf("\nNbrs de pages : ");
    scanf("%d",&lv.nbr_pages);
    printf("\nProgres (%) : ");
    scanf("%d",&lv.progres);
    getchar();
    printf("\nSynopsis : ");
    gets(lv.resume);
    ecrire_texte(lv.titre);
    ecrire_texte(lv.author);
    ecrire_texte(lv.resume);
    fp=fopen(fullname,"a");
    fprintf(fp,"%s %s %d %d %d %s",lv.titre,lv.author,lv.date_expedition,lv.nbr_pages,lv.progres,lv.resume);
    fclose(fp);

    return lv;
}

void afficher_livre(char *fullname,livre lv)
{

    int i=0,j=16,k=1;

    lire_texte(lv.titre);
    lire_texte(lv.author);
    lire_texte(lv.resume);


    print_title();
    gotoxy(20,10);
    printf("\xb2\xb2 TITRE : \t\t\t\t\t%s",lv.titre);
    gotoxy(20,11);
    printf("\xb2\xb2 AUTHEUR : \t\t\t\t%s",lv.author);
    gotoxy(20,12);
    printf("\xb2\xb2 DATE DE PUBLICATION : \t\t\t%d",lv.date_expedition);
    gotoxy(20,13);
    printf("\xb2\xb2 NOMBRES DE PAGES : \t\t\t%d",lv.nbr_pages);
    gotoxy(20,14);
    printf("\xb2\xb2 PROGRES : \t\t\t\t%d",lv.progres);
    gotoxy(20,15);
    printf("\xb2\xb2 SYNOPSIS : ");
    gotoxy(20,16);
    printf("\xb2\xb2");
    gotoxy(20,17);
    printf("\xb2\xb2");
    do
    {
        j++;
       gotoxy(20,j);
       printf("\xb2\xb2 ");
       i=76*(k-1);
       do
       {

         printf("%c",lv.resume[i] );
         i++;
         if(i==(76*k) && lv.resume[i]!=' ' )
           printf("-");

       }while(i<(76*k) && i<strlen(lv.resume));
      k++;
    }while(i<strlen(lv.resume));
    j++;
    gotoxy(20,j);
    printf("\xb2\xb2 ");

}

int first_menu()
{

    int choix;
    print_title();

    gotoxy(53,10);
    printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    gotoxy(53,11);
    printf("\xba             \xba");
    gotoxy(53,12);
    printf("\xba    1.New    \xba");
    gotoxy(53,13);
    printf("\xba             \xba");
    gotoxy(53,14);
    printf("\xba    2.Load   \xba");
    gotoxy(53,15);
    printf("\xba             \xba");
    gotoxy(53,16);
    printf("\xba    3.Quit   \xba");
    gotoxy(53,17);
    printf("\xba             \xba");
    gotoxy(53,18);
    printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    gotoxy(93,28);
    printf("made by : 5antoor!");
    gotoxy(60,19);
    scanf("%d",&choix);


    return choix;
}

void traiter_compte()
{
    FILE *fpass,*fcpt;
    compte cpt,cpt_ver ;
    int choix,ver=0;
    char *fullname=malloc(50*sizeof(char));


    choix=first_menu();
    system("cls");
    getchar();

    if(choix==1)
    {
        fpass=fopen("password.txt","a");
        gotoxy(20,10);
        printf("\xb2\xb2 Fullname : ");
        gets(cpt.fullname);
        gotoxy(20,11);
        printf("\xb2\xb2 password : ");
        gets(cpt.password);
        ecrire_texte(cpt.fullname);
        fprintf(fpass,"%s %s",cpt.fullname,cpt.password);
        sprintf(fullname,"%s.txt",cpt.fullname);
        fclose(fpass);
        main_menu(fullname);
    }
    else if(choix==2)
    {
        fpass=fopen("password.txt","r");
        gotoxy(20,10);
        printf("\xb2\xb2 Fullname : ");
        gets(cpt.fullname);
        gotoxy(20,11);
        printf("\xb2\xb2 password : ");
        gets(cpt.password);
        ecrire_texte(cpt.fullname);
        if(fpass==NULL)
        {
            printf("there has been an error \n");
            system("pause");
            traiter_compte();
        }
        while(!feof(fpass))
        {
            fscanf(fpass,"%s %s",cpt_ver.fullname,cpt_ver.password);
            if(strcmp(cpt.fullname,cpt_ver.fullname)==0 && strcmp(cpt.password,cpt_ver.password)==0)
             {
                ver=1;
                break;
             }
        }

        if(ver==1)
        {
            gotoxy(50,20);
            printf("LOGIN CONFIRMED ! ");
            gotoxy(40,23);
            system("pause");
            fclose(fpass);
            sprintf(fullname,"%s.txt",cpt.fullname);
            main_menu(fullname);
        }
        else
        {
            gotoxy(50,20);
            printf(" LOGIN DECLINED ! ");
            gotoxy(40,23);
            system("pause");
            fclose(fpass);
            traiter_compte();
        }

    }
    else
        return 0;


}
int main_menu(char *fullname)
{
    int i,ch;
   do
   {
      print_title();

      gotoxy(45,8);
      printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
      gotoxy(45,9);
      printf("\xba      **** MAIN MENU ****      \xba");
      gotoxy(45,10);
      printf("\xba                               \xba");
      gotoxy(45,11);
      printf("\xba                               \xba");
      gotoxy(45,12);
      printf("\xba      \xdb 1.New Book             \xba");
      gotoxy(45,13);
      printf("\xba                               \xba");
      gotoxy(45,14);
      printf("\xba      \xdb 2.Search               \xba");
      gotoxy(45,15);
      printf("\xba                               \xba");
      gotoxy(45,16);
      printf("\xba      \xdb 3.List                 \xba");
      gotoxy(45,17);
      printf("\xba                               \xba");
      gotoxy(45,18);
      printf("\xba      \xdb 4.Supprimer            \xba");
      gotoxy(45,19);
      printf("\xba                               \xba");
      gotoxy(45,20);
      printf("\xba      \xdb 5.Modifier             \xba");
      gotoxy(45,21);
      printf("\xba                               \xba");
      gotoxy(45,22);
      printf("\xba      \xdb 6.Quit                 \xba");
      gotoxy(45,23);
      printf("\xba                               \xba");
      gotoxy(45,24);
      printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
      gotoxy(61,26);
      scanf("%d",&ch);
      getchar();
      switch(ch)
      {
      case 1 :
          nouveau_livre(fullname);
          getchar();
          break;
      case 2 :
          chercher_livre(fullname);
          getchar();
          break;
      case 3 :
          lister_livre(fullname);
          getchar();
          break;
      case 4 :
          supprimer_livre(fullname);
          break;
      case 5 :
          modifier_livre(fullname);
          break;

      }

   }while(ch!=6);
   first_menu();

}

void nouveau_livre(char* fullname)
{

    livre lv;

    lv=saisir_livre(fullname);
    afficher_livre(fullname,lv);
    printf("\n");
    getchar();


}

void chercher_livre(char* fullname)
{
    FILE *fp;
    livre lv;
    int ver=0;
    char *titre_ver=malloc(20*sizeof(char));
    fp=fopen(fullname,"r");
    system("cls");

    if(fp==NULL)
    {
      gotoxy(50,20);
      printf("pas de livres disponibles \n");
      gotoxy(40,23);
      system("pause");
      main_menu(fullname);
    }
    gotoxy(20,10);
    printf("\xb2\xb2 Titre du livre : ");
    gets(titre_ver);
    ecrire_texte(titre_ver);
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d %d %d %s",lv.titre,lv.author,&lv.date_expedition,&lv.nbr_pages,&lv.progres,lv.resume);
        if(strcmp(lv.titre,titre_ver)==0)
        {
            ver=1;
            break;
        }
    }
    if(ver==1)
    {
        afficher_livre(fullname,lv);
        getchar();

    }
    else{
        gotoxy(50,20);
        printf("\t\t livre indisponible ");
        gotoxy(40,23);
        getchar();
    }
    fclose(fp);
    main_menu(fullname);

}

void lister_livre(char* fullname)
{
    FILE *fp;
    livre lv;

    system("cls");
    fp=fopen(fullname,"r");
    if(fp==NULL)
    {
      gotoxy(50,20);
      printf("pas de livres disponibles \n");
      gotoxy(40,23);
      system("pause");
      main_menu(fullname);
    }

    while(fscanf(fp,"%s %s %d %d %d %s",lv.titre,lv.author,&lv.date_expedition,&lv.nbr_pages,&lv.progres,lv.resume)!=EOF)
    {
         afficher_livre(fullname,lv);
         getchar();
         printf("\n\n");
    }

    fclose(fp);

}

void supprimer_livre(char* fullname)
{
    FILE *fp,*ftemp;
    livre lv;
    char *titre=malloc(50*sizeof(char));

    system("cls");

    fp=fopen(fullname,"r");
    ftemp=fopen("temp.txt","w");

    if(ftemp==NULL || fp==NULL)
    {
        gotoxy(50,20);
        printf("error \n");
        exit(1);
    }

    gotoxy(20,10);
    printf("\xb2\xb2 Titre du livre : ");
    gets(titre);
    ecrire_texte(titre);
     while(fscanf(fp,"%s %s %d %d %d %s",lv.titre,lv.author,&lv.date_expedition,&lv.nbr_pages,&lv.progres,lv.resume)!=EOF)
    {
         if(strcmp(titre,lv.titre)==0)
         {
            continue;
         }else
         {
              fprintf(ftemp,"%s %s %d %d %d %s\n",lv.titre,lv.author,lv.date_expedition,lv.nbr_pages,lv.progres,lv.resume);
         }

    }
    fclose(fp);
    fclose(ftemp);

    fp=fopen(fullname,"w");
    ftemp=fopen("temp.txt","r");
     while(fscanf(ftemp,"%s %s %d %d %d %s",lv.titre,lv.author,&lv.date_expedition,&lv.nbr_pages,&lv.progres,lv.resume)!=EOF)
     {
         fprintf(fp,"%s %s %d %d %d %s\n",lv.titre,lv.author,lv.date_expedition,lv.nbr_pages,lv.progres,lv.resume);
     }
    fclose(fp);
    fclose(ftemp);
}

void modifier_livre(char* fullname)
{
    FILE *fp,*ftemp;
    livre lv;
    int choix,donnee_nbr;
    char *titre=malloc(20*sizeof(livre)),*donne_txt=malloc(500*sizeof(char));

    fp=fopen(fullname,"r");
    ftemp=fopen("temp.txt","w");

    system("cls");
    gotoxy(20,10);
    printf("\xb2\xb2 Titre du livre : ");
    gets(titre);
    ecrire_texte(titre);

    system("cls");
    gotoxy(20,10);
    printf("\xb2\xb2 1. TITRE ");
    gotoxy(20,11);
    printf("\xb2\xb2 2. AUTHEUR ");
    gotoxy(20,12);
    printf("\xb2\xb2 3. DATE DE PUBLICATION ");
    gotoxy(20,13);
    printf("\xb2\xb2 4. NOMBRES DE PAGES ");
    gotoxy(20,14);
    printf("\xb2\xb2 5. PROGRES ");
    gotoxy(20,15);
    printf("\xb2\xb2 6. SYNOPSIS ");
    gotoxy(27,17);
    scanf("%d",&choix);

    system("cls");
    printf("\nMODIFICATION : \n\n");
    if(choix==3 || choix==4 || choix==5)
        scanf("%d",&donnee_nbr);
    else if(choix==1 || choix==2 ||choix==6)
      {
        getchar();
        gets(donne_txt);
        ecrire_texte(donne_txt);
      }

    while(fscanf(fp,"%s %s %d %d %d %s",lv.titre,lv.author,&lv.date_expedition,&lv.nbr_pages,&lv.progres,lv.resume)!=EOF)
    {
        if(strcmp(lv.titre,titre)==0)
        {
            switch(choix)
            {
               case 1:strcpy(lv.titre,donne_txt);
                     break;
               case 2:strcpy(lv.author,donne_txt);
                     break;
               case 3:lv.date_expedition=donnee_nbr;
                     break;
               case 4:lv.nbr_pages=donnee_nbr;
                     break;
               case 5:lv.progres=donnee_nbr;
                     break;
               case 6:strcpy(lv.resume,donne_txt);
                     break;

            }
        }
        fprintf(ftemp,"%s %s %d %d %d %s\n",lv.titre,lv.author,lv.date_expedition,lv.nbr_pages,lv.progres,lv.resume);
    }

    fclose(fp);
    fclose(ftemp);


    fp=fopen(fullname,"w");
    ftemp=fopen("temp.txt","r");
    while(fscanf(ftemp,"%s %s %d %d %d %s",lv.titre,lv.author,&lv.date_expedition,&lv.nbr_pages,&lv.progres,lv.resume)!=EOF)
     {
         fprintf(fp,"%s %s %d %d %d %s\n",lv.titre,lv.author,lv.date_expedition,lv.nbr_pages,lv.progres,lv.resume);
     }
    fclose(fp);
    fclose(ftemp);


}

