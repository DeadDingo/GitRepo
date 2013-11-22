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
  
  int i = 0, total = 0;
  char buffer[100];
  //
  

  while(!feof(fin)) {

    fgets(buffer, 100, fin);
    strcpy(array[i].street, buffer);

    fgets(buffer, 100, fin);
    strcpy(array[i].city, buffer);

    //fgets(buffer, 100, fin);
    //strcpy(array[i].state, buffer);

    fscanf(fin, "%s\n", array[i].state);

    fscanf(fin, "%d\n", &array[i].zip);

    total++;
    i++;
  }

  return total;

}
