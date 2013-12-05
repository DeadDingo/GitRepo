//lab11.c
//cscd240
//
//Written by Josh Harshman
//
//============================
//=========================

#include "lab11.h"

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
Address *fillArray(int *total, FILE *fin) {
  
  int i = 0;
  int count = 0;
  Address *array;
  char buffer[100];
  //

  //allocate memory array
  array = (Address *)malloc(10 * sizeof(Address));
  
  while( !feof(fin) ) {

    //read street
    fgets(buffer, 100, fin);
    array[i].street = (char *)malloc(100 * sizeof(char));
    strcpy(array[i].street, buffer);

    //read city
    fgets(buffer, 100, fin);
    array[i].city = (char *)malloc(100 * sizeof(char));
    strcpy(array[i].city, buffer);

    //read state
    array[i].state = (char *)malloc(3 * sizeof(char));
    fscanf(fin, "%s\n", array[i].state);

    //read zip
    fscanf(fin, "%d\n", &array[i].zip);

    i++;
    count++;
  }

  *total = count;

  return array;

}
int menu(void) {

  int choice;

  printf("1.  Print the array sorted by street.\n");
  printf("2.  Print the array sorted by city.\n");
  printf("3.  Print the array sorted by state then city\n");
  printf("4.  Print the array sorrted by zip.\n");
  printf("5.  Quit");
  
  printf("~~> ");

  scanf("%d", &choice);

  return choice;

}
void printStreetSortedArray(Address *array, int total) {

  qsort(array, total, sizeof(Address), streetCompare);
  printAll(array, total);
  

}
void printCitySortedArray(Address *array, int total) {

  qsort(array, total, sizeof(Address), cityCompare);
  printAll(array, total);

}
void printStateCitySortedArray(int total, Address *array) {

  qsort(array, total, sizeof(Address), stateCityCompare);
  printAll(array, total);

}
void printZipSortedArray(int total, Address *array) {

  qsort(array, total, sizeof(Address), zipCompare);
  printAll(array, total);

}
void printAll(Address *array, int total) {

  int i;

  for(i = 0; i < total; i++) {
    printf("---------------\n");
    printf("%s %s %s\n %d\n", array[i].street, array[i].city, array[i].state, array[i].zip);
  }

}
void cleanUp(Address *array, int total) {

  int i;
  for(i = 0; i < total; i++) {
    free(array[i].street);
    free(array[i].city);
    free(array[i].state);
  }
  free(array);

}


/**
 *Compare functions
 * */
int streetCompare(const void *a, const void *b) {

  const Address *elem1 = a;
  const Address *elem2 = b;

  return strcmp(elem1->street, elem2->street);

}
int cityCompare(const void *a, const void *b) {

  const Address *elem1 = a;
  const Address *elem2 = b;

  return strcmp(elem1->city, elem2->city);

}
int stateCityCompare(const void *a, const void *b) {

  const Address *elem1 = a;
  const Address *elem2 = b;

  if( strcmp(elem1->state, elem2->state) > 0 ) {
    return (1);
  }
  else if( strcmp(elem1->state, elem2->state) < 0 ) {
    return (-1);
  }
  else if( strcmp(elem1->city, elem2->city) > 0 ) {
    return (1);
  }
  else if( strcmp(elem1->city, elem2->city) < 0 ) {
    return (-1);
  }
  else
    return 0;

}
int zipCompare(const void *a, const void *b) {

  const Address *elem1 = a;
  const Address *elem2 = b;

  return ( (elem1->zip) - (elem2->zip) );

}
