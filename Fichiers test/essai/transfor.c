#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>

#include"transfor.h"




// Fonction qui sert a transformer les instructions en int//
int instructions(char instru[]){
  if(!strcmp(instru,"pop")){
    return 0;
  }

  else if(!strcmp(instru,"push")){
    return 1;
  }

  else if(!strcmp(instru,"iPop")){
      return 2;
    }


  else if(!strcmp(instru,"iPush")){
      return 3;
    }

  else if(!strcmp(instru,"push#")){
        return 4;
      }

  else if(!strcmp(instru,"call")){
        return 5;
        }

  else if(!strcmp(instru,"ret")){
          return 6;
          }
  else if(!strcmp(instru,"jmp")){
          return 7;
            }
  else if(!strcmp(instru,"jpc")){
            return 8;
              }
  else if(!strcmp(instru,"write")){
            return 9;
        }
  else if(!strcmp(instru,"read")){
            return 10;
          }
  else if(!strcmp(instru,"rnd")){
              return 11;
            }
  else if(!strcmp(instru,"dup")){
              return 12;
              }
  else if(!strcmp(instru,"op")){
                return 13;
                }
  else if(!strcmp(instru,"halt")){
    return 99;
  }


  else {
    return -1;
  }
}

int detectionEtiquette(char etiq[]){
  int a;
  a=strlen(etiq);
  int i;
  for(i=0;i<a;i++){
    if(etiq[i]==':'){
      return 1;
    }
  }
return 0;
}


void strip(char ancien[],char new[]){     //suppression des ":"
int i;
for(i=0;ancien[i]!=':';i++){
    new[i]=ancien[i];
}
new[i]='\0';
}





int isInTab(ListeInst*l,char etiq[]){ //renvoie la position de l'etiquette dans le programme
  Inst *e=l->tete;
  while(e!=NULL){

    if(strcmp(e->mot,etiq)==0){
      return e->adr;
    }
    e=e->next;
  }
  return -1;
}

ListeInst *creationListe(char nomFichier[]){
  FILE*f;
  ListeInst* listeEtiq=creerListe();
  int nbligne=0,i=0,j;
  ListeInst* listeMot;
  char ligne[TAILLE_MAX];
  char mots[TAILLE_MAX][TAILLE_MAX];
  char new[32];
  f=fopen(nomFichier,"r");

  while(fgets(ligne,TAILLE_MAX, f) != NULL){
    nbligne++;
    listeMot=creerListe();
    char d[] = " ";
    char *p= strtok(ligne, d);
    while(p != NULL){ //sépare la phrase mot par mot
       mots[i++]=p;
        p = strtok(NULL, d);
    }
    if(detectionEtiquette(tmp)){
        suppression(tmp,nouv);
        strcpy(etiquettes[numDeLigne],nouv);
        tab[j++]=numDeLigne;
    }

  }
  fclose(f);

  return listeEtiq;
}

void afficheList(ListeInst *l){
  Inst* m=l->tete;
  if(m==NULL){
    printf("liste vide\n");
  }
  while(m!=NULL){
    printf("(%s, %d)\n",m->mot,m->adr );
    m=m->next;
  }
}

int transformationFichier(char nomFichier[]){
    FILE* f,*g;
    ListeInst *listeEtiq=creationListe(nomFichier);
  	int numDeLigne=0;
  	char Name[]="hexa.txt";
  	f=fopen(nomFichier,"r");
    g=fopen(Name,"w");
    int numInstru;
    Inst *instru;
    ListeInst* listeMot;
    char ligne[TAILLE_MAX];
    int adr;
    int tmp;
    if(f==NULL || g==NULL){
      printf("Impossible d'ouvrir un des fichiers correctement\n");
      return -1;
      }

    while(fgets(ligne, TAILLE_MAX, f) != NULL){
       ++numDeLigne;
       listeMot=creerListe();
       removenewline(ligne);
       char d[] = " ";
       char *p = strtok(ligne, d);

       while(p != NULL){ //sépare la phrase mot par mot
           ajoutInst(listeMot,p);
           p = strtok(NULL, d);
       }

      if(detectionEtiquette(listeMot->tete->mot)){
           instru=listeMot->tete->next;
          }

      else{
           instru=listeMot->tete;
         }

      numInstru=instructions(instru->mot);

      while(instru!=NULL){
           if(numInstru == -1){
             printf("Erreur dans la syntaxe du programme à la ligne %d\n",numDeLigne);
             return -1;
           }

          if(numInstru==7 || numInstru==8){
              fprintf(g,"%s ",intToHexaInstru(numInstru));
              printf("%s",instru->mot);
              instru=instru->next;
              tmp=isInTab(listeEtiq,instru->mot);
               if(tmp!=-1){
                 adr=tmp-(numDeLigne);
                 fprintf(g,"%s",intToHexa(adr));
               }

               else{
                 printf("cette etiquette n'existe pas, erreur à la ligne %d\n",numDeLigne);
                 return -1;
               }
           }

           else{

             instru=instru->next;
             fprintf(g,"%s ",intToHexaInstru(numInstru));

             if(instru==NULL){
               fprintf(g,"%s",intToHexa(atoi(instru->mot)));
             }
             else{
             fprintf(g,"%s",intToHexa(0));
           }
         }

           instru=instru->next;

            }
            fputs("\n",g);
            freeListe(listeMot);
}
fclose(f);
fclose(g);
freeListe(listeEtiq);
freeListe(listeMot);
return 1;

}
