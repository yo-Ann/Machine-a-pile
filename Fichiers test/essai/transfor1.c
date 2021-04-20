
#include"transfor.h"



int estDansTabEtiq(char tab[TAILLE_MAX][TAILLE_ETIQ],char a[]){   /* trouve la position de l'etiquette, renvoie -1 si elle n'existe pas */
int i;
int taille=strlen(a);
for(i=0;i<TAILLE_MAX;i++){
    if(strncmp(tab[i],a,taille)==0) return i;
}
return -1;
}

int estDansTab(int tab[],int a,int taille){
  int i;
  for(i=0;i<taille;i++){
      if(tab[i]==a) return 1;
  }
  return -1;
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

int estEntier(char mot[]){
    int len=strlen(mot);
    char c;
    int i;
    for(i = 0; i < len; i++){
            c = mot[i];
            if ((c < '0') || (c > '9')){
              return 0;
            }
      }
      return 1;
    }

int instrus(char instru[]){
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

void suppression(char ancien[],char nouv[]){     //suppression des ":"
int i;
for(i=0;ancien[i]!=':';i++){
    nouv[i]=ancien[i];
}
nouv[i]='\0';
}

int transformationFichier(char nomFichier[]){

  FILE* f,*g;
  int numDeLigne=0;
  int numInstru,r;
  int tab[TAILLE_MAX];
  int tab1[TAILLE_MAX];
  char Name[]="hexa.txt";
  f=fopen(nomFichier,"r");
  char etiquettes[TAILLE_MAX][TAILLE_ETIQ];
  char mots[TAILLE_MAX][TAILLE_ETIQ];
  char tmp[TAILLE_MAX];
  char nouv[TAILLE_ETIQ];
  int j,i,k=0,l=0;
  int null=0;

  if(f==NULL){
    printf("Impossible d'ouvrir un des fichiers correctement\n");
    return -1;
    }

    while(fgets(tmp,TAILLE_MAX, f) != NULL){
      numDeLigne++;
      i=0;
      char d[] = " ";
      char *p= strtok(tmp, d);
      while(p != NULL){ //sépare la phrase mot par mot
         strcpy(mots[i++],p);
          p = strtok(NULL, d);
      }

      for(j=0;j<i;j++){
      if(detectionEtiquette(mots[j])){
          suppression(mots[j],nouv);
          strcpy(etiquettes[numDeLigne],nouv);
          tab[k++]=numDeLigne;
      }

      if((strncmp(mots[j],"halt",4)==0)||(strncmp(mots[j],"ret",3)==0)||(strncmp(mots[j],"iPush",5)==0)||(strncmp(mots[j],"iPop",4)==0)){
        tab1[l++]=numDeLigne;
      }
    }
  }

fclose(f);



  char etiq[15];
  char instru[15];
  char donnes[25];
  int temp,adr;
  f=fopen(nomFichier,"r");
  g=fopen(Name,"w");

  if(f==NULL|| g==NULL){
    printf("Impossible d'ouvrir un des fichiers correctement\n");
    return -1;
    }

  for(i=1;i<=numDeLigne;i++){

      if(estDansTab(tab,i,k)==1){
        if(estDansTab(tab1,i,l)==1){
            r=fscanf(f, "%s %s\n",etiq,instru);
        }

        else{
        r=fscanf(f,"%s %s %s\n",etiq,instru,donnes);
      }

    }

      else if(estDansTab(tab1,i,l)==1){
          r=fscanf(f,"%s\n",instru);
      }

      else{
      r=fscanf(f,"%s %s\n",instru,donnes);
    }

      if(r!=EOF){
      numInstru=instrus(instru);
      if(numInstru==-1){
         printf("Erreur dans la syntaxe du programme à la ligne %d\n",i);
         return -1;
       }

      if(numInstru==7 || numInstru==8 || numInstru==5){
          fprintf(g,"%.2x  ",numInstru);
          temp=estDansTabEtiq(etiquettes,donnes);

           if(temp!=-1){
             adr=temp-(i+1);
             fprintf(g,"%.4hx\n",adr);
           }

           else{
             printf("cette etiquette n'existe pas, erreur à la ligne %d\n",i);
             return -1;
           }
         }


         else if(numInstru==99||numInstru==6||numInstru==3||numInstru==2||numInstru==12){ // aucune donnees avant so
           fprintf(g,"%.2x  ",numInstru);
           fprintf(g,"%.4hx\n",null);
         }

         else if(numInstru==13){
           fprintf(g,"%.2x  ",numInstru);
           if(atoi(donnes)<0 ||atoi(donnes)>15){
             printf("Erreur cette opération n'existe pas, erreur à la ligne %d\n",i);
             return -1;
           }
            fprintf(g,"%.4hx\n",atoi(donnes));
         }

         else{

           fprintf(g,"%.2x  ",numInstru);
           if(!estEntier(donnes)){
             printf("Erreur dans la donnée à la ligne %d, donnés incorrecte\n",i);
             return -1;
           }
           fprintf(g,"%.4hx\n",atoi(donnes));
         }
      }
    }
    fclose(f);
    fclose(g);

    return 1;

}
