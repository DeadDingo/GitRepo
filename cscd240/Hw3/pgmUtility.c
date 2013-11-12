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
  int i, j;
  int **content;
  //get header information
  for(i = 0; i < ROWS; i ++) {
    for(j = 0; j < COLS; j ++) {
      scanf("%c ", header[i][j] );
    }
  }
  *numRows = *(*(header + 2) + 0);
  *numCols = *(*(header + 2) + 1);

  //dynamically allocate memory for pixel map and populate
  content = (int **)malloc(*numRows * sizeof(int));
  for(i = 0; i < *numRows; i ++) {
    for(j = 0; j < *numCols; j ++) {
      content[i] = (int *)malloc(*numCols * sizeof(int));
      scanf("%d ", *(*(content + i) +j) );
    }
  }

  return content;

}
int pgmDrawCircle(int **pixels, int numRows, int numCols, int centerRow, int centerCol, int radius, char **header) {

  //function

}
int pgmDrawEdge(int **pixels, int numRows, int numCols, int edgeWidth, char **header) {

  //function

}
int pgmWrite(const char **header, const int **pixels, int numRows, int numCols) {

  //function

}
double distance(int p1[ ], int p2[ ]) {

  //function

}
