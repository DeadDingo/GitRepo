//
//  pgmUtility.c
//  cscd240PGM
//
//  Created by Josh Harshman
//  All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
  }


  char *str;
  *numRows = atoi(strtok(str, " "));
  *numCols = atoi(strtok(NULL, " "));

  /*
  printf("%d\n", *numRows);
  printf("%d", *numCols);
  */

  //must get number of rows and columns from header

  array = (int **)malloc(*numRows * sizeof(int *));
  for(r = 0; r < *numRows; r++) {
    array[r] = (int *)malloc(*numCols * sizeof(int));
  }

  for(r = 0; r < *numRows; r++) {
    for(c = 0; c < *numCols; c++) {
      scanf("%d ", &array[r][c]);
    }
  }

  return array;
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

  //find distance between two points on a 2 dimensional plane

  double distance;
  double first, second, final;

  first = p1[0] - p2[0];
  second = p1[1] = p2[1];

  first = pow(first, 2);
  second = pow(second, 2);

  final = first - second;

  distance = sqrt(final);

  return distance;

}
