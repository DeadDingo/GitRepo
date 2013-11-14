//
//  main.c
//  cscd240PGM
//
//  Created by Josh Harshman
//  All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pgmUtility.h"

#define ROWS 4
#define COLS 100

void usage( void ) {
  printf("Usage\n");
  printf(" -h Help Dialog\n");
  printf(" -e < OldImageFile > NewImageFile\n");
  printf(" -c < OldImageFile > NewImageFile\n");
  exit (8);
}


int main(int argc, const char * argv[]) {

  int i, j;
  int flag1 = 0; //-e switch (edge draw)
  int flag2 = 0; //-c switch (circle draw)
  int numRows, numCols, centerRow, centerCols, radius;
  
  char **header;
  int **pixels;


  //command line argument parsing
  //turn flag switches on or off

  for(i = 1; i < argc; i++) {

    if(strncmp(argv[i], "-e", 2) == 0) {
      //set flag on
      //get edge with values
      flag1 = 1;
    }
    if(strncmp(argv[i], "-c", 2) == 0) {
      //set flag on
      //get radius and center values
      flag2 = 1;
    }
    if(strncmp(argv[i], "-h", 2) == 0) {
      usage();
    }

  }

  //allocate memory for header array
  header = (char **)malloc(ROWS * sizeof(char));
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      header[i] = (char *)malloc(COLS * sizeof(char));
    }
  }

  //read pgm file with pgmRead() function
  pixels = pgmRead(header, &numRows, &numCols);


  switch(flag1) {
  case 1 :
    if(flag2 == 1) {
      //execute circle draw and edge draw
    }
    else { 
      //execute only circle draw only
    }
    break;
  case 0 :
      if(flag2 == 1) {
	//execute frame draw
      }
    //done
    break;
  default : 
    usage();
    break;

  }


  //write new pgm file
  pgmWrite((const char **)header, (const int **)pixels, numRows, numCols);


  free(pixels);
  free(header);

    // write your code here
    
    // draw
    // draw in picture, write you code here
    
    // write image back
    // write your code here
    
    return 0;
}

