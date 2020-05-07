#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "strings.h"
#include "math.h"

const char * protocols[2] = {
"http:",
"smb:"
};

const char * domains[3] = {
"org",
"com",
"ru"
};


int replace_sym(char *str, char sym, char replace){
  if(!str)
    return -1;
  int count = 0;
  for(int i = 0;i<slen(str);i++){
    if(str[i]==sym){
      str[i]=replace;
      count++;
    }
  }
  return count;
}

int check(char path[]){
  char* tokens[10];
  int tokensCount = stok(path, '/', tokens);
  

  return 0; 
}


char * refresh(char * path, char * delim){
  if(!path)
    return NULL;
  char* paths[10];
  int pathsCount;
  pathsCount = stok(path,  delim[0], paths);
  char* tokens[10];
  char* new_paths[10];
  int tokensCount;
  int npathCount=0;
  for(int i=0 ;i<pathsCount;i++){
    tokensCount = stok(paths[i], '/', tokens);

    printf(" %s ",tokens[2]);
    char * buf=tokens[2];
    printf(" %s\n",buf);

    if(!scmp(tokens[0],protocols[0]) || !scmp(tokens[0],protocols[1])){

    


    char * temp=malloc(MAX_PATH);
    temp=scat(temp,"\\");
    for(int j=2 ;j<tokensCount;j++){
      //printf(" %s",tokens[j]);
      temp=scat(temp,"\\");
      temp=scat(temp,tokens[j]);
    }
    new_paths[npathCount]=temp;
    npathCount++;
    }
  }

  char * res=malloc(LENGTH);
  res=scat(res,new_paths[0]);
  for(int i=1 ;i<npathCount;i++){ 
    res=scat(res,"+"); 
    res=scat(res,new_paths[i]);  
  }
  return res;
}


int main(void) {
  char delim[0];
	char * path=malloc(LENGTH);

	scan_paths(path, delim);
  path = refresh(path, delim);

  printf("%s\n",path);
  free(path);




  
  return 0;
}