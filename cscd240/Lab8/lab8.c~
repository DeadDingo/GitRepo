#include <stdio.h>
#include <stdlib.h>
#include "lab8.h"


/*Display Usage*/
void usage( void ) {
  printf("Usage:\n");
  printf(" -f FILENAME\n");
  printf(" -h Displays This Dialog\n");
  exit(8);
}
/*Display File Format Error*/
void fileFormatError( void ) {
  printf("File Format Error\n");
  printf("There is an issue with the input file\n");
  exit(8);
}
/*Open File For reading
* */
FILE *openFile(int argc, char *argv[]) {

  int i;
  FILE *file;


  if(argc < 2 || argc > 7) {
    usage();
  }
  else {

    for(i = 0; i < argc; i++) {
      //test arguments
      if(strncmp(argv[i], "-f", 2) == 0) {
	if(argv[i+1] != NULL) {
	  file = fopen(argv[i+1], "r");
	}
      }
      if(strncmp(argv[i], "-h", 2) == 0) {
	usage();
      }
    }

  }

  return file;

}
/*Reads the first entry in the file
* */
int readMonth(FILE *fin) {
  int month;
  fscanf(fin, "%d", &month);
  if(month <= 0 || month > 12) {
    //print file format warning
    fileFormatError();
  }
  return month;
}
/*Allocates Memory for array, populates the array and returns it to main
* */
int *fillArray(int month, FILE *fin) {

  int r, numDays;
  int *array;

  switch (month) {
  case 12 :
    numDays = 31;
    break;
  case 11 :
    numDays = 30;
    break;
  case 10 :
    numDays = 31;
    break;
  case 9 :
    numDays = 30;
    break;
  case 8 :
    numDays = 31;
    break;
  case 7 :
    numDays = 31;
    break;
  case 6 :
    numDays = 30;
    break;
  case 5 :
    numDays = 31;
    break;
  case 4 :
    numDays = 30;
    break;
  case 3 :
    numDays = 31;
    break;
  case 2 :
    numDays = 28;
    break;
  case 1 :
    numDays = 31;
    break;
  default :
    numDays = 31;
    break;

  }


  array = (int *)malloc(sizeof(numDays * sizeof(int)));
  for(r = 0; r < numDays; r++) {
    fscanf(fin, "%d", &array[r]);
  }


  for(r = 0; r < numDays; r++) {
    printf("%d\n", array[r]);
  }

  return array;

}
/*Displays Menu
* */
int menu( void ) {

  int choice;

  do {

    printf("1. Find Max Temperature\n");
    printf("2. Find Min Temperature\n");
    printf("3. Find Average Temperature\n");
    printf("4. Find Median Temperature\n");
    printf("5. Find the mode Temperature\n");
    printf("6. Enter a different file\n");
    printf("7. Quit\n");

    printf("~~> ");
    scanf("%d", &choice);

  } while(choice != 7);

  return choice;

}
/*Find the Maximum Temperature
* */
void displayMaxTemp(int *temps) {

  int r, size, max = -30;

  for(r = 0; r < size; r++) {
    if(temps[r] > max) {
      max = temps[r];
    }
  }

  printf("The Max Value is: %d\n", max);

}
/*Find the Minimum Temperature
* */
void displayMinTemp(int *temps) {

  //function

}
