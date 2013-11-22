//lab9.c
//cscd240
//
//Written by Josh Harshman
//
//

#include "lab9.h"

FILE *openFile() {
  char name[20];
  FILE *fin;

  do {
    printf("Enter File Name: ");
    scanf("%s", name);
    fin = fopen(name, "r");
  }while(fin == NULL);

  return fin;

}
int fillArray(Address array[ ], FILE *fin) {
  
  int i = 0;, total = 0;
  char buffer[100];
  //
  while( fgets(buffer, 100, fin ) != NULL ) {

    //process each line
    
    if(strlen(buffer) < 3) {
      strncpy(array[i].state, buffer);
    }

    //
    total++;
    i++;

  }

  return (total/4);

}
