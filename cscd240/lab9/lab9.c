//lab9.c
//cscd240
//
//Written by Josh Harshman
//
//

#include "lab9.h"

FILE *openFile() {
  char *name = { NULL };

  do {

    printf("Enter Valid Filename: ");
    scanf("%s", name);

  }while(name != NULL);

  return fopen(name, "r");

}
int fillArray(Address array[ ], FILE *fin) {
  int size;
  int i;
  int count;
  //
  size = sizeof(array)/sizeof(array[0]);

  for(i = 0; i < size; i++) {
    

  }


}
