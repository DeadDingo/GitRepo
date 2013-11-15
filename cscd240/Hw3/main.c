//
//  main.c
//  cscd240PGM
//
//  Created by Josh Harshman
//  All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pgmUtility.h"

#define ROWS 4
#define COLS 100

void usage( void ) {
  printf("Usage\n");
  printf(" -h Help Dialog\n");
  printf(" -e edgeWidth < OldImageFile > NewImageFile\n");
  printf(" -c centerRow centerCol radius < OldImageFile > NewImageFile\n");
  printf(" -e edgeWidth -c radius centerRow centerCol < OldImageFile > NewImageFile\n");
  exit (8);
}


int main(int argc, const char * argv[]) {

  int i, j;
  int flag1 = 0; //-e switch (edge draw)
  int flag2 = 0; //-c switch (circle draw)
  int numRows, numCols, centerRow, centerCol, radius, edgeWidth;
  
  char **header;
  int **pixels;


  //command line argument parsing
  //turn flag switches on or off

  if(argc == 1)
    usage();

  for(i = 1; i < argc; i++) {

    if(strncmp(argv[i], "-e", 2) == 0) {
      //set flag on
      //get edge with values)
      edgeWidth = atoi(argv[i+1]);
      flag1 = 1;
    }
    if(strncmp(argv[i], "-c", 2) == 0) {
      //set flag on
      //get radius and center values
      centerRow = atoi(argv[i+1]);
      centerCol = atoi(argv[i+2]);
      radius = atoi(argv[i+3]);
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
      header[i] = (char *)malloc(COLS * sizeof(char *));
    }
  }

  //read pgm file
  pixels = pgmRead(header, &numRows, &numCols);
  if(pixels == NULL)
    usage();

  switch(flag1) {
  case 1 :
    if(flag2 == 1) {
      //execute circle draw and edge draw
      pgmDrawCircle(pixels, numRows, numCols, centerRow, centerCol, radius, header);
      pgmDrawEdge(pixels, numRows, numCols, edgeWidth, header);
    }
    else { 
      //execute only edge draw only
      pgmDrawEdge(pixels, numRows, numCols, edgeWidth, header);
    }
    break;
  case 0 :
      if(flag2 == 1) {
	//execute circle draw
	pgmDrawCircle(pixels, numRows, numCols, centerRow, centerCol, radius, header);
      }
    break;
  default : 
    usage();
    break;
  }


  //write new pgm file
  pgmWrite((const char **)header, (const int **)pixels, numRows, numCols);


  free(pixels);
  free(header);

  return 0;

}

