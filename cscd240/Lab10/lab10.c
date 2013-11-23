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
    

    i++;
    total++;
  }

  

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
void printStreetSortedArray(Address array[ ], int total) {

  int i, j;
  char temp[100];
  //

  for(i = 0; i < total; i++) {
    for(j = 0; j < total-1; j++) {
      
      if(strcmp( array[j].street, array[j+1].street ) > 0 ) {
	strcpy( temp, array[j+1].street );
	strcpy( array[j+1].street, array[j].street );
	strcpy( array[j].street, temp );
      }
    }

  }

  for(i = 0; i < total; i++) {
    printf("%s", array[i].street);
  }

}
void printCitySortedArray(Address array[ ], int total) {

  int i, j;
  char temp[100];

  for(i = 0; i < total; i++) {
    for(j = 0; j < total-1; j++) {
      if(strcmp( array[j].city, array[j+1].city ) > 0 ) {
	strcpy( temp, array[j+1].city );
	strcpy( array[j+1].city, array[j].city );
	strcpy( array[j].city, temp);
      }
    }
  }

  for(i = 0; i < total; i++) {
    printf("%s", array[i].city);
  }

}
void printStateCitySortedArray(int total, Address array[ ]) {

  int i, j;
  char temp[100];
  
  /*Something is wrong here.  I need to figure out how to take along the correlating state with the city durring the sort
  * */
  
  for(i = 0; i < total; i++) {
    for(j = 0; j < total-1; j++) {
      if( strcmp( array[j].city, array[j+1].city ) > 0 ) {
	strcpy( temp, array[j+1].city );
	strcpy( array[j+1].city, array[j].city );
	strcpy( array[j].city, temp);
      }
    }
  }
  
  for(i = 0; i < total; i++) {
    printf("%s %s", array[i].state, array[i].city);
  }

}
void printZipSortedArray(int total, Address array[ ]) {
  
  int i, j;

  for(i = 0; i < total; i++) {
    for(j = 0; j < total-1; j++) {
      if(array[j].zip > array[j+1].zip) {
	Address temp = array[j+1];
	array[j+1] = array[j];
	array[j] = temp;
      }
    }

  }

  for(i = 0; i < total; i++) {

    printf("%d\n", array[i].zip);

  }


}
