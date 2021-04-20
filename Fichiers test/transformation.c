#include"transfor.h"
#include"instructions.h"

void suppression(char ancien[],char nouv[]){     //suppression des ":"
int i;
for(i=0;ancien[i]!=':';i++){
    nouv[i]=ancien[i];
}
nouv[i]='\0';
}

int estDansTabEtiq(char tab[TAILLE_MAX][TAILLE_ETIQ],char a[]){   /* trouve la position de l'etiquette, renvoie -1 si elle n'existe pas */
int i;
int taille=strlen(a);
for(i=0;i<TAILLE_MAX;i++){
    if(strncmp(tab[i],a,taille)==0) return i;
}
return -1;
}

int estDansTab(int tab[],int a,int taille){ // verifie si la ligne a entré en argument correspond à une ligne ayant une instruction spéciale
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

int estEntier(char mot[]){// verifie si la donnée d'une instruction est bien un décimal

    int len=strlen(mot);
    char c;
    int i;
    for(i = 0; i < len-1; i++){
            c = mot[i];
            if ((c < '0') || (c > '9')){
              return 0;
            }
      }
      return 1;
    }

int instrus(char instru[]){ // retourne le code machine de l'instruction donnée en paramètres ou -1 si elle n'existe pas
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

  else if(!strncmp(instru,"ret",3)){
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
void suptab(char tmp[]){ // supprime les passages à la ligne sous linux ou sur windows
  int a=strlen(tmp);

  if(tmp[a-1]=='\n'){
    if(tmp[a-2]=='\r'){
      tmp[a-2]='\0';
    }
    else{
        tmp[a-1]='\0';
      }
    }
}

int transformationFichier(char nomFichier[]){

FILE* f,*g;
int numDeLigne=0;
int numInstru;
int tab[TAILLE_MAX];//tableau contenant les lignes où il y a des étiquettes
int tab1[TAILLE_MAX];//tableau contenant les lignes d'instructions spéciales
char Name[]="hexa.txt";
Instructions stockage[TAILLE_MAX];
f=fopen(nomFichier,"r");
char etiquettes[TAILLE_MAX][TAILLE_ETIQ];
char mots[TAILLE_MAX][TAILLE_ETIQ]; //tableau de chaines de caractère contenant les differents mots d'une ligne
char tmp[TAILLE_MAX]; // chaine de caractère recuperant une ligne
char nouv[TAILLE_ETIQ];
int j,i,k=0,l=0;
int null=0;

if(f==NULL){
  printf("Impossible d'ouvrir un des fichiers correctement\n");
  return -1;
  }

  while(fgets(tmp,TAILLE_MAX, f) != NULL){//parciurs le fichier une premiere fois
    numDeLigne++;
    i=0;
    char d[] = "  ";
    char *p= strtok(tmp, d);
    while(p != NULL){ //sépare la phrase mot par mot
       strcpy(mots[i++],p);
        p = strtok(NULL, d);
      }

    for(j=0;j<i;j++){

    if(detectionEtiquette(mots[j])){
        suppression(mots[j],nouv);
        strcpy(etiquettes[numDeLigne],nouv);
        tab[k++]=numDeLigne;// ajoute le numero de la ligne au tableau des lignes contenant d'etiquettes
    }

    if((strncmp(mots[j],"halt",4)==0)||(strncmp(mots[j],"ret",3)==0)||(strncmp(mots[j],"iPush",5)==0)||(strncmp(mots[j],"iPop",4)==0)){
      tab1[l++]=numDeLigne; //ajoute le numero de la ligne au tableau des lignes contenant d'etiquettes
    }
  }
}

fclose(f);
char donnes[25];
int temp,adr;
f=fopen(nomFichier,"r");
g=fopen(Name,"w"); //ouvre le fichier hexa.txt

if(f==NULL|| g==NULL){
  printf("Impossible d'ouvrir un des fichiers correctement\n");
  return -1;
  }

for(i=1;i<=numDeLigne;i++){

  if(fgets(tmp,TAILLE_MAX, f) != NULL){
    suptab(tmp);//supprime les sauts de ligne
    j=0;
    char d[] = "  ";
    char *p= strtok(tmp, d);
    while(p != NULL){ //sépare la phrase mot par mot
       strcpy(mots[j++],p);
        p = strtok(NULL, d);
      }


        if(estDansTab(tab,i,k)==1){//il y a présence d'une etiquette
          if(estDansTab(tab1,i,l)==1){//il y a présence d'une instructions ne prenant pas d'argument

            if(j>2){//l'utilisateur a mis un argument
              printf("Beaucoup trop d'argument pour %s à la ligne %d\n",mots[1],i);
              remove("hexa.txt");
              return -1;
            }
            numInstru=instrus(mots[1]);
          }
          // else if(){}

          else{
            if(j>3){//l'utilisateur a mis plus d'un argument
              printf("Beaucoup trop d'argument pour %s à la ligne %d\n",mots[1],i);
              remove("hexa.txt");
              return -1;
            }
              numInstru=instrus(mots[1]);
              strcpy(donnes,mots[2]);

            }
        }


    else if(estDansTab(tab1,i,l)==1){
        if(j>1){//l'utilisateur a mis un argument
          printf("Beaucoup trop d'argument pour %s à la ligne %d\n",mots[0],i);
          remove("hexa.txt");
            return -1;
        }

          numInstru=instrus(mots[0]);
    }

    else{//aucune etiquette et présence d'une instruction prenant 1 argument
      if(j>2){//l'utilisateur a mis plus d'un argument
        printf("Beaucoup trop d'argument pour %s à la ligne %d\n",mots[0],i);
        remove("hexa.txt");
        return -1;
      }
        numInstru=instrus(mots[0]);
        strcpy(donnes,mots[1]);
  }

    if(numInstru==-1){ //l'instruction n'existe pas
       printf("Erreur dans la syntaxe du programme à la ligne ou l'argument attendu n'a pas été entré à la ligne %d\n",i);
       remove("hexa.txt");
       return -1;
     }

    if(numInstru==7 || numInstru==8 || numInstru==5){//presence de jpc,jmp ou call
        fprintf(g,"%.2x  ",numInstru);
        temp=estDansTabEtiq(etiquettes,donnes);

         if(temp!=-1){
           adr=temp-(i+1);
           fprintf(g,"%.4hx\n",adr);
         }

         else{
           printf("cette etiquette n'existe pas, erreur à la ligne %d\n",i);
          remove("hexa.txt");
           return -1;
         }
       }


       else if(numInstru==99||numInstru==6||numInstru==3||numInstru==2||numInstru==12){ // instruction n'ayant aucun argument
         fprintf(g,"%.2x  ",numInstru);
         fprintf(g,"%.4hx\n",null);
       }


       else if(numInstru==13){//instruction op
         fprintf(g,"%.2x  ",numInstru);
         if(atoi(donnes)<0 ||atoi(donnes)>15){
           printf("Erreur cette opération n'existe pas, erreur à la ligne %d\n",i);
          remove("hexa.txt");;
           return -1;
         }

          fprintf(g,"%.4hx\n",atoi(donnes));
       }

       else{

         fprintf(g,"%.2x  ",numInstru);
         if(!estEntier(donnes)){
           printf("Erreur dans la donnée à la ligne %d, donnés non décimal\n",i);
          remove("hexa.txt");
           return -1;
         }
         fprintf(g,"%.4hx\n",atoi(donnes));
       }
    }
  }
  fclose(f);
  fclose(g);
return 1; //La traduction s'est bien passée
}
