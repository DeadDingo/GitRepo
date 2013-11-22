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

FILE *openFile(void);

int fillArray(Address array[ ], FILE *fin);

int menu(void);

void printStreetSortedArray(Address array[ ], int total);

void printCitySortedArray(Address array[ ], int total);

void printStateCitySortedArray(Address array[ ], int total);

void printZipSortedArray(int total, Address array[ ]);

#endif
