#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include"transformation.h"
#include"instructions.h"


int main(int argc, char* argv[]){

		if (argc<2){
			printf("Pas de fichier en argument\n");
        return 0;
		}

		int test;
		test=transformationFichier(argv[1]);

	if(test==-1){// il y a eu une erreur lors de la traduction sortie d programme
		return 0;
	}

	FILE *f;
	f=fopen("hexa.txt","r");

	if(f==NULL){
		printf("erreur à l'ouverture du ficher\n");
		return 0;
	}

	int i=0;
	int b;
	Instructions stockage[TAILLE_MAX];
	Memoire memoire;
	memoire.SP=0;
	memoire.PC=0;


	for(i=0;i<TAILLE_MEMOIRE;i++){
		if(feof(f)!=0){
			break;
		}
		fscanf(f,"%hx %hx\n",&stockage[i].instru,&stockage[i].donnes);// recupération des éléments dans le ficher hexa
			}
	fclose(f);


	while(1){
	  memoire.PC++;

		if(stockage[memoire.PC-1].instru==99){
			printf("____Sortie du programme____\n");
			break;
			}


	 	b=queFaire(&memoire,stockage[memoire.PC-1]);
		if(b==-1){ //il y a eu une erreur lors de l'éxécution, arrêt de l'éxécution
			printf("Erreur !\n");
			break;
		}
	}

	return 0;
}
