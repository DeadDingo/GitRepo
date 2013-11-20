//cscd240 lab9
//
//Written By Josh Harshman
//
//

#ifndef cscd240_lab9_h
#define cscd240_lab9_h

#include <stdio.h>
#include <stdlib.h>

typedef struct info {

  char Street[100];
  char City[100];
  char State[3];
  int zip;

}Address;

FILE *openFile();

int fillArray(struct Address *array, FILE *fin);

void menu (void);

void printStreetSortedArray(struct Address array[], int total);

void printCitySortedArray(struct Address array[], int total);

void printStateCitySortedArray(struct Address array[], int total);

void printZipSortedArray(struct Address array[], int total);


#endif
