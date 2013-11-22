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
  while( fgets(buffer, 100, fin ) != NULL) {

    //process each line
    if(strlen(buffer) < 3)
      strcpy(array[i].state, buffer);

    if(strchr(buffer, ' '))
      strcpy(array[i].street, buffer);

    if(strlen(buffer) > 3 && strlen(buffer) < 12)
      strcpy(array[i].city, buffer);

    else {
      sscanf(buffer, "%d", &array[i].zip);
    }

    //
    total++;
    i++;

  }

  return (total/4);

}
