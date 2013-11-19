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


FILE *openFile();

int fillArray(struct Address *array, FILE *fin);
/*
void menu (void);

void printStreetSortedArray(Address array[], int total);

void printCitySortedArray(Address array[], int total);

void printStateCitySortedArray(Address array[], int total);

void printZipSortedArray(Address array[], int total);

*/
