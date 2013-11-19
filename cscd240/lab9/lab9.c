#include <stdio.h>
#include <stdlib.h>
#include "lab9.h"


FILE *openFile(void) {

  char *fileName;
  FILE *file;
  
  //
  printf("Enter File Name: ");
  scanf("%s", fileName);
  do {
    file = fopen(fileName, "r");

  }while(file != NULL);

  return file;

}
int fillArray(struct Address array[], FILE *fin) {

  int i;
  int count = 0;
  for(i = 0; i < 10; i++) {
    fgets(array[i], 10, fin);
    if(array[i] != NULL) {
      count++;
    }
  }

  return count;

}

