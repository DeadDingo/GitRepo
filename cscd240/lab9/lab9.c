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
