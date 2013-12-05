//lab10.h
//cscd240
//
//Josh Harshman
//

#ifndef lab11_h
#define lab11_h

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

//compare by Street function
int streetCompare(const void *a, const void *b);
//compare by city function
int cityCompare(const void *a, const void *b);
//compare by state function
int stateCityCompare(const void *a, const void *b);
//compare by zip function
int zipCompare(const void *a, const void *b);

void structBubbleSort(Address *array, int index);

void printAll(Address *array, int total);

void cleanUp(Address *array, int total);


#endif
