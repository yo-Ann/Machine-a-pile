#ifndef TRANSFOR_H
#define TRANSFOR_H
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>
#include <ctype.h>
#include<string.h>
#include"instructions.h"

#define TAILLE_MAX  500
#define TAILLE_ETIQ 30


int conversion(char instru[]);
int detectionEtiquette(char etiq[]);
void strip(char ancien[],char new[]);
int estDansTab(int tab[],int a,int taille);
int transformationFichier(char nomFichier[]);
int estDansTabEtiq(char T[TAILLE_MAX][TAILLE_ETIQ],char a[]);
int estEntier(char mot[]);
void supSautDeLigne(char tmp[]);
#endif
