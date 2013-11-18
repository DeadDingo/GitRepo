//CSCD240 Lab8
//
//Written By Josh Harshman
//


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
  char fn[100];

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
	else if(argv[i+1] == NULL){
	  readFileName(fn);
	  return openInputFile(fn);
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


  //special stopping value at end of array
  array[numDays] = 900;

  return array;

}
/*Displays Menu
* */
int menu( void ) {

  int choice;

    printf("1. Find Max Temperature\n");
    printf("2. Find Min Temperature\n");
    printf("3. Find Average Temperature\n");
    printf("4. Find Median Temperature\n");
    printf("5. Find the mode Temperature\n");
    printf("6. Enter a different file\n");
    printf("7. Quit\n");

    printf("~~> ");
    scanf("%d", &choice);

  return choice;

}
/*Find the Maximum Temperature
* */
void displayMaxTemp(int *temps) {

  int r, max;
  max = 0;

  for(r = 0; temps[r] != 900; r++) {
    if(temps[r] > max) {
      max = temps[r];
    }
  }

  printf("The maximum temperature reached was: %d\n", max);

}
/*Find the Minimum Temperature
* */
void displayMinTemp(int *temps) {

  int r, min;
  min = 300;

  for(r = 0; temps[r] != 900; r++) {
    if(temps[r] < min) {
      min = temps[r];
    }
  }
  printf("The minimum temperature reached was: %d\n", min);

}
/*Find the Average Temperature
* */
void displayAvgTemp(int *temps) {

  int r;
  float avg;
  int count = 0;
  for(r = 0; temps[r] != 900; r++) {
    avg += temps[r];
    count++;
  }
  avg = avg/count;

  printf("The average temperature for the month is: %.2f\n", avg);

}
/*Find the Median Temp
* */
void displayMedianTemp(int *temps) {

  int r, c, mid;
  int len = 0;

  for(r = 0; temps[r] != 900; r++) {
    len++;
  }

  //qsort sorting method from stdlib.h
  qsort(temps, len, sizeof(int), cmpfunc);


  if(len%2 == 0) {
    printf("The median temperature value is: %.2f\n", (float)( temps[len/2] + temps[len/2-1] )/2 );
  }
  else {
    printf("The median temperature value is: %.2f\n", (float)temps[len/2]);
  }

}
/*Qsort Compare function
* */
int cmpfunc(const void * a, const void * b) {
  return ( *(int *)a - *(int *)b );
}
/*Find the Mode Temp... This was a pain for some reason...
* */
void displayModeTemp(int *temps) {

  int r, c, num, mode, counter = 0;
  int tally[31];
  for(r = 0; temps[r] != 900; r++) {
    for(c = 0; temps[c] != 900; c++) {
      if(temps[r] == temps[c]) {
	counter++;
      }
    }
    tally[r] = counter;
    counter = 0; //reset counter
  }

  num = -300;
  for(r = 0; temps[r] != 900; r++) {
    if(num < tally[r]) {
      num = r;
    }
  }

  printf("The mode temperature is: %d\n", temps[num]);

}
/*Clean up function
* */
void cleanUp(int *temps) {
  free(temps);
}
/*Read a filename directly from user
* */
void readFileName(char fn[]) {

  printf("Enter File Name: ");
  scanf("%s", fn);

}

FILE *openInputFile(char fn[]) {

  return fopen(fn, "r");

}
