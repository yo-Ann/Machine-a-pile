#include <stdio.h>
#include <string.h>


// Fonction qui sert a transformer les instructions en int//

int fonctionCompa(char instru[]){
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
int len(char ch[]){
  int i=0
  while(ch[i]!='\0'){
    i++;
  }
  return i+1;
}

int detectionEtiquette(char etiq[]){
  a=len(etiq);
  int i;
  for(i=0;i<a;i++){
    if(etiq[i]==':'){
      return 1;
    }
  }

return 0;
}

// Fonction de stockage des etiquettes (pour s'endebarrasser lors de la conversion)//
void stockageEtiquette( char etiq[], char copie []){
  i=O;
  while (i!= ';'){
    etiq[i]=copie[i];
    i++;
  }
 
}


  }
}





int main(int argc,char *argv[]){
  FILE* hexa;
  hexa=fopen("hexa.txt","r");

}
