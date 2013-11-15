//
//  pgmUtility.c
//  cscd240PGM
//
//  Created by Josh Harshman
//  All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "pgmUtility.h"

#define ROWS 4
#define COLS 100


// implement or define each function prototypes listed in pgmUtility.h file.
// NOTE: You can NOT change the input, output, and argument type of the functions in pgmUtility.h
// NOTE: YOu can NOT change the prototype of any functions listed in pgmUtility.h


int ** pgmRead(char ** header, int *numRows, int *numCols) {
  int r, c;
  int **array;

  for(r = 0; r < ROWS; r++) {
    if(header[r] == NULL) {
      header[r] = (char *)malloc(COLS * sizeof(char));
    }
    fgets(header[r], COLS, stdin);
    if(header[r] == NULL)
      return NULL;
  }

  //sscanf parses the numRows and numCols
  sscanf(header[ROWS - 2], "%d %d", numCols, numRows);

  //read in pixel map
  array = (int **)malloc(*numRows * sizeof(int *));
  for(r = 0; r < *numRows; r++) {
    array[r] = (int *)malloc(*numCols * sizeof(int));
  }

  for(r = 0; r < *numRows; r++) {
    for(c = 0; c < *numCols; c++) {
      scanf("%d", *(array + r) + c );
    }
  }

  return array;
}
int pgmDrawCircle(int **pixels, int numRows, int numCols, int centerRow, int centerCol, int radius, char **header) {

  int r, c;
  int p1[2];
  p1[0] = centerRow;
  p1[1] = centerCol;
  int p2[2];

  for(r = 0; r < numRows; r++) {
    for(c = 0; c < numCols; c++) {
      p2[0] = r;
      p2[1] = c;
      if( distance(p1, p2) <= radius ) {
	pixels[r][c] = 0;
      }
    }
  }

  return 0;

}
int pgmDrawEdge(int **pixels, int numRows, int numCols, int edgeWidth, char **header) {

  int r, c;

  for(r = 0; r < numRows; r++) {
    for(c = 0; c < numCols; c++) {
      if(r <= edgeWidth || c <= edgeWidth) {
	pixels[r][c] = 0;
      }
      if(r >= (numRows-edgeWidth) || c >= (numCols-edgeWidth)) {
	pixels[r][c] = 0;
      }
    }
  }

  return 0;

}
int pgmWrite(const char **header, const int **pixels, int numRows, int numCols) {

  int r, c;

  for(r = 0; r < ROWS; r++) {
    for(c = 0; c < COLS; c++) {
      printf("%c", *(*(header + r) + c) );
    }
  }
  for(r = 0; r < numRows; r++) {
    for(c = 0; c < numCols; c++) {
      printf("%d ", *(*(pixels + r) + c) );
    }
  }

  return 0;

}
double distance(int p1[ ], int p2[ ]) {

  //find distance between two points on a 2 dimensional plane

  return sqrt( pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2) );

}
