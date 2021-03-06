//lab10.h
//cscd240
//
//Josh Harshman
//

#ifndef lab10_h
#define lab10_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Address {

  char *street;
  char *city;
  char *state;
  int zip;

}Address;

FILE *openFile(void);

Address *fillArray(int *total, FILE *fin);

int menu(void);

void printStreetSortedArray(Address *array, int total);

void printCitySortedArray(Address *array, int total);

void printStateCitySortedArray(int total, Address *array);

void printZipSortedArray(int total, Address *array);

void structBubbleSort(Address *array, int index);

void printAll(Address *array, int total);

void cleanUp(Address *array, int total);

#endif
