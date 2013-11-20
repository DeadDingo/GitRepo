#ifndef lab9_h
#define lab9_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Address {

  char *Street[100];
  char *City[100];
  char *State[3];
  int zip;

}Address;

FILE *openFile();

int fillArray(Address array[ ], FILE *fin);

#endif
