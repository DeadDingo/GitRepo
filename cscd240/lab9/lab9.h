//cscd240 lab9
//
//Written By Josh Harshman
//
//

#ifndef cscd240lab9_h
#define cscd240lab9_h

#include <stdio.h>


#endif

struct Address {

  char street[100];
  char city[100];
  char state[3];
  int zip;

}


FILE *openFile(void);

int fillArray(struct Address *array, FILE *fin);

void menu (void);

void printStreetSortedArray(struct Address array[], int total);

void printCitySortedArray(struct Address array[], int total);

void printStateCitySortedArray(struct Address array[], int total);

void printZipSortedArray(struct Address array[], int total);
