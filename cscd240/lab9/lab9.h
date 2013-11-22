#ifndef lab9_h
#define lab9_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

  char street[100];
  char city[100];
  char state[3];
  int zip;

}Address;

FILE *openFile();

int fillArray(Address array[ ], FILE *fin);

#endif
