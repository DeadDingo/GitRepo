//lab9.c
//cscd240
//
//Written by Josh Harshman
//
//============================
//=========================

#include "lab10.h"

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

  int i, j;

  for(i = 0; i < total; i++) {
    for(j = 0; j < total-1; j++) {
      if(strcmp( array[j].street, array[j+1].street ) > 0 ) {
	structBubbleSort(array, j);
      }
    }
  }

  printAll(array, total);


}
void printCitySortedArray(Address *array, int total) {

  int i, j;

  for(i = 0; i < total; i++) {
    for(j = 0; j < total-1; j++) {
      if(strcmp( array[j].city, array[j+1].city ) > 0 ) {
	structBubbleSort(array, j);
      }
    }
  }

  printAll(array, total);

}
void printStateCitySortedArray(int total, Address *array) {

  int i, j;

  for(i = 0; i < total; i++) {
    for(j = 0; j < total-1; j++) {
      if( strcmp( array[j].city, array[j+1].city ) > 0 ) {
	structBubbleSort(array, j);
      }
    }
  }
  
  printAll(array, total);

}
void printZipSortedArray(int total, Address *array) {

  int i, j;

  for(i = 0; i < total; i++) {
    for(j = 0; j < total-1; j++) {
      if(array[j].zip < array[j+1].zip) {
	structBubbleSort(array, j);
      }
    }
  }

  printf("\nZips are sorted in decending order\n");

  printAll(array, total);

}
void structBubbleSort(Address *array, int index) {
  char temp[100];
  int t;

  strcpy( temp, array[index+1].street );
  strcpy( array[index+1].street, array[index].street);
  strcpy( array[index].street, temp );
  //
  strcpy( temp, array[index+1].city );
  strcpy( array[index+1].city, array[index].city );
  strcpy( array[index].city, temp );
  //
  strcpy( temp, array[index+1].state );
  strcpy( array[index+1].state, array[index].state );
  strcpy( array[index].state, temp );
  //
  t = array[index+1].zip;
  array[index+1].zip = array[index].zip;
  array[index].zip = t;

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
