#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"transformation.h"
#include <time.h>

#define TAILLE_MEMOIRE 4000


typedef struct memoire{
int PC;
int SP;
int espaceDeTravail[TAILLE_MEMOIRE];
}Memoire;


typedef struct instructions{
  short instru;
  short donnes;
}Instructions;


int queFaire(Memoire *memoire,Instructions ligne);

int estVide(Memoire *memoire);

int estRempli(Memoire *memoire);

 int pop(Memoire *memoire,short donnes);

int push(Memoire *memoire,short donnes);

void iPop(Memoire *memoire);

void iPush(Memoire *memoire);

int push1(Memoire *memoire,short donnes);

 void call(Memoire *memoire,short donnes);

void ret(Memoire *memoire);

void jmp(Memoire *memoire,short donnes);

void jpc(Memoire *memoire,short donnes);

void write(Memoire *memoire,short donnes);

void read(Memoire *memoire,short donnes);

void rnd(Memoire *memoire,short donnes);

void dup(Memoire *memoire);

void op(Memoire *memoire,short donnes);











#endif
