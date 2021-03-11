#include"instructions.h"


int queFaire(Memoire *memoire,Instructions ligne){
  int instru=ligne.instru;
  short donnes=ligne.donnes;
  int a;

  if(instru==0){
    a=pop(memoire,donnes);
    return a;
  }

else if(instru==1){
  a=push(memoire,donnes);
  return a;
}

else if(instru==2){
  iPop(memoire);
  return 1;
}
else if(instru==3){

  iPush(memoire);
  return 1;
}
else if(instru==4){
  a=push1(memoire,donnes);
  return a;
}
else if(instru==5){
  call(memoire,donnes);
  return 1;
}

else if(instru==6){
  ret(memoire);
  return 1;
}
else if(instru==7){
  jmp(memoire,donnes);
  return 1;
}

else if(instru==8){
  jpc(memoire,donnes);
  return 1;
}

else if(instru==9){;
  write(memoire,donnes);
  return 1;
}

else if(instru==10){
  read(memoire,donnes);
  return 1;
}

else if(instru==11){
  rnd(memoire,donnes);
  return 1;
}

else if(instru==12){
  dup(memoire);
  return 1;
}

else if(instru==13){
    op(memoire,donnes);
    return 1;
}

return -1;
}

int estVide(Memoire *memoire){
     if(memoire->SP == 0){
       return 1;
     }
  return 0;
}

int estRempli(Memoire *memoire){
  if(memoire->SP == TAILLE_MEMOIRE){
    return 1;
  }
  return 0;
 }

 int pop(Memoire *memoire,short donnes){
   if(estVide(memoire)==0){
   memoire->espaceDeTravail[donnes]=memoire->espaceDeTravail[memoire->SP-1];
   memoire->SP--;
   return 1;
 }
 else{
   printf("La pile est vide\n");
   return -1;
 }
}

int push(Memoire *memoire,short donnes){
  if (estRempli(memoire)==0){
    memoire->espaceDeTravail[memoire->SP]=memoire->espaceDeTravail[donnes];
    memoire->SP++;
    return 1;
  }
  else{
    printf("Plus de place en mémoire\n");
    return -1;
  }
}

void iPop(Memoire *memoire){

  memoire->espaceDeTravail[memoire->SP-1]=memoire->espaceDeTravail[memoire->SP-2];
  memoire->SP-=2;
}

void iPush(Memoire *memoire){

  int x;
  x=memoire->espaceDeTravail[memoire->SP-1];
  memoire->espaceDeTravail[memoire->SP-1]=memoire->espaceDeTravail[x];

}


 int push1(Memoire *memoire, short donnes){//push#
   if (!estRempli(memoire)){
      memoire->espaceDeTravail[memoire->SP]=donnes;
      memoire->SP++;
      return 1;
 }
 else{
   printf("Plus de place en mémoire\n");
   return 1;
 }
}

 void call(Memoire *memoire,short donnes){

   memoire->espaceDeTravail[memoire->SP++]=memoire->PC;
   memoire->PC+=donnes;
 }

 void ret(Memoire *memoire){
   memoire->SP--;
   memoire->PC=memoire->espaceDeTravail[memoire->SP];
 }

void jmp(Memoire *memoire,short donnes){
   memoire->PC+=donnes;
 }

void jpc(Memoire *memoire,short donnes){
  memoire->SP--;
  int p=memoire->espaceDeTravail[memoire->SP];
  if(p!=0){
      memoire->PC+=donnes;
}
}

void write(Memoire *memoire,short donnes){
  printf("--> %d\n",memoire->espaceDeTravail[donnes]);
}

void read(Memoire *memoire,short donnes){
  printf("Veuillez entrez un nombre: \n");
  scanf("%d",&memoire->espaceDeTravail[donnes]);

}

void rnd(Memoire *memoire,short donnes){
  srand (time (NULL));
  int z=rand()%donnes;
  memoire->espaceDeTravail[memoire->SP++]=z;

}

void dup(Memoire *memoire){

  memoire->espaceDeTravail[memoire->SP]=memoire->espaceDeTravail[memoire->SP-1];
  memoire->SP++;
}

void op(Memoire *memoire,short donnes){

    if(donnes== 0){//test d'égalité
          memoire->SP--;
          if(memoire->espaceDeTravail[memoire->SP-1]==memoire->espaceDeTravail[memoire->SP]){
            memoire->espaceDeTravail[memoire->SP-1]=1;
          }
          else{
           memoire->espaceDeTravail[memoire->SP-1]=0;
          }
        }

    else if(donnes==1){//test d'inégalité
          memoire->SP--;
          if(memoire->espaceDeTravail[memoire->SP-1]!=memoire->espaceDeTravail[memoire->SP]){
          memoire->espaceDeTravail[memoire->SP-1]=1;
          }
          else{
          memoire->espaceDeTravail[memoire->SP-1]=0;
          }
        }

  else  if(donnes== 2){//test >
          memoire->SP--;
          if(memoire->espaceDeTravail[memoire->SP-1]>memoire->espaceDeTravail[memoire->SP]){
            memoire->espaceDeTravail[memoire->SP-1]=1;
          }
          else{
          memoire->espaceDeTravail[memoire->SP-1]=0;
        }
      }

  else  if(donnes == 3){//test >=
          memoire->SP--;
          if(memoire->espaceDeTravail[memoire->SP-1]>=memoire->espaceDeTravail[memoire->SP]){
            memoire->espaceDeTravail[memoire->SP-1]=1;
          }
          else{
          memoire->espaceDeTravail[memoire->SP-1]=0;
          }
        }

    else if(donnes== 4){//test <
          memoire->SP--;
          if(memoire->espaceDeTravail[memoire->SP-1]<memoire->espaceDeTravail[memoire->SP]){
            memoire->espaceDeTravail[memoire->SP-1]=1;
          }
          else{
            memoire->espaceDeTravail[memoire->SP-1]=0;
          }
        }

else  if(donnes == 5){ //test <=
          memoire->SP--;
          if(memoire->espaceDeTravail[memoire->SP-1]<=memoire->espaceDeTravail[memoire->SP]){
            memoire->espaceDeTravail[memoire->SP-1]=1;
          }
          else{
            memoire->espaceDeTravail[memoire->SP-1]=0;
          }
        }

  else  if(donnes == 6){//et logique bit à bit
          memoire->SP--;
          memoire->espaceDeTravail[memoire->SP-1]=memoire->espaceDeTravail[memoire->SP-1]&memoire->espaceDeTravail[memoire->SP];
        }

  else  if(donnes== 7){// ou logique bit à bit
          memoire->SP--;
          memoire->espaceDeTravail[memoire->SP-1]=memoire->espaceDeTravail[memoire->SP-1]|memoire->espaceDeTravail[memoire->SP];
        }

  else  if(donnes== 8){//ou exclusif logique bit à bit
          memoire->SP--;
          memoire->espaceDeTravail[memoire->SP-1]=memoire->espaceDeTravail[memoire->SP-1]^memoire->espaceDeTravail[memoire->SP-1];
        }

  else  if(donnes== 9){//non logique bit à bit

          memoire->espaceDeTravail[memoire->SP-1]=~memoire->espaceDeTravail[memoire->SP-1];
        }

  else  if(donnes == 10){//inverse le sommet de la pile

          memoire->espaceDeTravail[memoire->SP-1] =- memoire->espaceDeTravail[memoire->SP-1];
        }

  else if(donnes== 11){//addition des deux valeurs aux sommets

          memoire->SP--;
          memoire->espaceDeTravail[memoire->SP-1]=memoire->espaceDeTravail[memoire->SP-1]+memoire->espaceDeTravail[memoire->SP];
        }

  else  if(donnes ==12){//soustraction des deux valeurs aux sommets

          memoire->SP--;
          memoire->espaceDeTravail[memoire->SP-1]=memoire->espaceDeTravail[memoire->SP-1]-memoire->espaceDeTravail[memoire->SP];
        }

  else  if(donnes== 13){//multiplication des deux valeurs aux sommets
          memoire->SP--;
          memoire->espaceDeTravail[memoire->SP-1]=memoire->espaceDeTravail[memoire->SP-1]*memoire->espaceDeTravail[memoire->SP];
        }

  else  if(donnes==14){// division entière des deux valeurs aux sommets

          memoire->SP--;
          memoire->espaceDeTravail[memoire->SP-1]=memoire->espaceDeTravail[memoire->SP-1]/memoire->espaceDeTravail[memoire->SP];
        }


  else  if(donnes == 15){// modulo des deux valeurs aux sommets

          memoire->SP--;
          memoire->espaceDeTravail[memoire->SP-1]=memoire->espaceDeTravail[memoire->SP-1]%memoire->espaceDeTravail[memoire->SP];
        }
        

}
