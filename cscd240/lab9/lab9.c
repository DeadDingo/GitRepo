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
  

  while(fgets(buffer, 100, fin) != NULL) {


    total++;
    i++;
  }

  printf("%d\n---", total);

  printf("%s", array[2].street);
  printf("%s", array[2].city);
  printf("%s\n", array[2].state);
  printf("%d\n", array[2].zip);

  return (total/4);

}
