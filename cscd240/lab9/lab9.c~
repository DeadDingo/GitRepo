//lab9.c
//cscd240
//
//Written by Josh Harshman
//
//

#include "lab9.h"

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
int fillArray(Address array[ ], FILE *fin) {
  
  int i = 0, total = 0;
  char buffer[100];
  //
  

  while(!feof(fin)) {

    fgets(buffer, 100, fin);
    strcpy(array[i].street, buffer);

    fgets(buffer, 100, fin);
    strcpy(array[i].city, buffer);

    fscanf(fin, "%s\n", array[i].state);

    fscanf(fin, "%d\n", &array[i].zip);

    total++;
    i++;
  }

  return total;

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
void printStreetSortedArray(Address array[ ], int total) {

  int i, j;

  for(j = 0; j < total; j++) {
    if(array[j].street > array[j+1].street) {
	Address temp = array[j];
	array[j] = array[j+1];
	array[j+1] = temp;
    }
  }
  

  for(i = 0; i < total; i++) {

    printf("%s\n", array[i].street);

  }

}
void printCitySortedArray(Address array[ ], int total) {



}
void printStateCitySortedArray(Address array[ ], int total) {


}
void printZipSortedArray(int total, Address array[ ]) {
  int i;
  
  for(i = 0; i <  total; i++) {
    if(array[i].zip > array[i+1].zip) {
      Address temp = array[i];
      array[i] = array[i+i];
      array[i+1] = temp;

    }

  }

  for(i = 0; i < total; i++) {
    printf("%d\n", array[i].zip);
  }


}
