#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define TAILLE_MAX 500
#define TAILLE_ETIQ 25


//
// void suppression(char ancien[],char nouv[]){     //suppression des ":"
// int i;
// for(i=0;ancien[i]!=':';i++){
//     nouv[i]=ancien[i];
// }
// nouv[i]='\0';
// }
//
// int estDansTabEtiq(char tab[TAILLE_MAX][TAILLE_ETIQ],char a[]){   /* trouve la position de l'etiquette, renvoie -1 si elle n'existe pas */
// int i;
// int taille=strlen(a)-1;
// for(i=0;i<TAILLE_MAX;i++){
//     if(strncmp(tab[i],a,taille)==0) return i;
// }
// return -1;
// }
//
// int estDansTab(int tab[],int a,int taille){
//   int i;
//   for(i=0;i<taille;i++){
//       if(tab[i]==a) return 1;
//   }
//   return -1;
//   }
//
// int detectionEtiquette(char etiq[]){
//   int a;
//   a=strlen(etiq);
//   int i;
//   for(i=0;i<a;i++){
//     if(etiq[i]==':'){
//       return 1;
//     }
//   }
// return 0;
// }
//
// int estEntier(char mot[]){
//
//     int len=strlen(mot);
//     char c;
//     int i;
//     for(i = 0; i < len-1; i++){
//             c = mot[i];
//             if ((c < '0') || (c > '9')){
//               return 0;
//             }
//       }
//       return 1;
//     }
//
// int instrus(char instru[]){
//   if(!strncmp(instru,"pop",3)){
//     return 0;
//   }
//
//
//   else if(!strncmp(instru,"push",4)){
//     return 1;
//   }
//
//   else if(!strncmp(instru,"iPop",4)){
//       return 2;
//     }
//
//
//   else if(!strncmp(instru,"iPush",5)){
//       return 3;
//     }
//
//   else if(!strcmp(instru,"push#"){
//         return 4;
//       }
//
//   else if(!strncmp(instru,"call",4)){
//         return 5;
//         }
//
//   else if(!strncmp(instru,"ret",3)){
//           return 6;
//           }
//   else if(!strncmp(instru,"jmp",3)){
//           return 7;
//             }
//   else if(!strncmp(instru,"jpc",3)){
//             return 8;
//               }
//   else if(!strncmp(instru,"write",5)){
//             return 9;
//         }
//   else if(!strncmp(instru,"read",4)){
//             return 10;
//           }
//   else if(!strncmp(instru,"rnd",3)){
//               return 11;
//             }
//   else if(!strncmp(instru,"dup",3)){
//               return 12;
//               }
//   else if(!strncmp(instru,"op",2)){
//                 return 13;
//                 }
//   else if(!strncmp(instru,"halt",4)){
//     return 99;
//   }
//
//
//   else {
//     return -1;
//   }
// }

// int main(){
//
// FILE* f,*g;
// int numDeLigne=0;
// int numInstru;
// int tab[TAILLE_MAX];
// int tab1[TAILLE_MAX];
// char Name[]="hexa2.txt";
// f=fopen("fact.txt","r");
// char etiquettes[TAILLE_MAX][TAILLE_ETIQ];
// char mots[TAILLE_MAX][TAILLE_ETIQ];
// char tmp[TAILLE_MAX];
// char nouv[TAILLE_ETIQ];
// int j,i,k=0,l=0;
// int null=0;
//
// if(f==NULL){
//   printf("Impossible d'ouvrir un des fichiers correctement\n");
//   return -1;
//   }
//
//   while(fgets(tmp,TAILLE_MAX, f) != NULL){
//     numDeLigne++;
//     i=0;
//     char d[] = " ";
//     char *p= strtok(tmp, d);
//     while(p != NULL){ //sépare la phrase mot par mot
//        strcpy(mots[i++],p);
//         p = strtok(NULL, d);
//     }
//     for(j=0;j<i;j++){
//     if(detectionEtiquette(mots[j])){
//         suppression(mots[j],nouv);
//         strcpy(etiquettes[numDeLigne],nouv);
//         tab[k++]=numDeLigne;
//     }
//
//     if((strncmp(mots[j],"halt",4)==0)||(strncmp(mots[j],"ret",3)==0)||(strncmp(mots[j],"iPush",5)==0)||(strncmp(mots[j],"iPop",4)==0)){
//       tab1[l++]=numDeLigne;
//     }
//   }
// }
//
// fclose(f);
// char donnes[25];
// int temp,adr;
// f=fopen("fact.txt","r");
// g=fopen(Name,"w");
//
// if(f==NULL|| g==NULL){
//   printf("Impossible d'ouvrir un des fichiers correctement\n");
//   return -1;
//   }
//
// for(i=1;i<=numDeLigne;i++){
//
//   if(fgets(tmp,TAILLE_MAX, f) != NULL){
//     j=0;
//     char d[] = " ";
//     char *p= strtok(tmp, d);
//     while(p != NULL){ //sépare la phrase mot par mot
//        strcpy(mots[j++],p);
//         p = strtok(NULL, d);
//     }
//
//         if(estDansTab(tab,i,k)==1){
//           if(estDansTab(tab1,i,l)==1){
//             if(j>2){
//               printf("Beaucoup trop d'argument pour %s à la ligne %d\n",mots[1],i);
//               return -1;
//             }
//               numInstru=instrus(mots[1]);
//           }
//
//           else{
//             if(j>3){
//               printf("Beaucoup trop d'argument pour %s à la ligne %d\n",mots[1],i);
//               return -1;
//             }
//               numInstru=instrus(mots[1]);
//               strcpy(donnes,mots[2]);
//             }
//         }
//
//
//     else if(estDansTab(tab1,i,l)==1){
//         if(j>1){
//           printf("Beaucoup trop d'argument pour %s à la ligne %d\n",mots[0],i);
//             return -1;
//         }
//
//           numInstru=instrus(mots[0]);
//     }
//
//     else{
//       if(j>2){
//         printf("Beaucoup trop d'argument pour %s à la ligne %d\n",mots[0],i);
//         return -1;
//       }
//         numInstru=instrus(mots[0]);
//         strcpy(donnes,mots[1]);
//   }
//
//     if(numInstru==-1){
//        printf("Erreur dans la syntaxe du programme à la ligne %d\n",i);
//        return -1;
//      }
//
//     if(numInstru==7 || numInstru==8 || numInstru==5){
//         fprintf(g,"%.2x  ",numInstru);
//         temp=estDansTabEtiq(etiquettes,donnes);
//
//          if(temp!=-1){
//            adr=temp-(i+1);
//            fprintf(g,"%.4hx\n",adr);
//          }
//
//          else{
//            printf("cette etiquette n'existe pas, erreur à la ligne %d\n",i);
//            return -1;
//          }
//        }
//
//
//        else if(numInstru==99||numInstru==6||numInstru==3||numInstru==2||numInstru==12){ // aucune donnees avant so
//          fprintf(g,"%.2x  ",numInstru);
//          fprintf(g,"%.4hx\n",null);
//        }
//
//
//        else if(numInstru==13){
//          fprintf(g,"%.2x  ",numInstru);
//          if(atoi(donnes)<0 ||atoi(donnes)>15){
//            printf("Erreur cette opération n'existe pas, erreur à la ligne %d\n",i);
//            return -1;
//          }
//
//           fprintf(g,"%.4hx\n",atoi(donnes));
//        }
//
//        else{
//
//          fprintf(g,"%.2x  ",numInstru);
//          if(!estEntier(donnes)){
//            printf("Erreur dans la donnée à la ligne %d, donnés incorrecte\n",i);
//            return -1;
//          }
//          fprintf(g,"%.4hx\n",atoi(donnes));
//        }
//     }
//   }
//   fclose(f);
//   fclose(g);

int main(void)

{
  FILE *f;
  f=fopen("essai2.txt","r");
  char tmp[70];
  char mots[70][70];
  int j,i;
  while(fgets(tmp,70,f)!=NULL){
    j=0;
    char const*pc = strtok(tmp, "   ");
    while (pc != NULL){
        strcpy(mots[j++],pc);
        pc = strtok(NULL, "   ");
    }

    for(i=0;i<j;i++){
      printf("%s  ",mots[i]);
    }
    }
fclose(f);
    return 0;
}
// return 1;
// }
