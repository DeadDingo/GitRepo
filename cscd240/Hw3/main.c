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


void usage( void ) {
  printf("Usage\n");
  printf(" -h Help Dialog");
  printf(" -e < OldImageFile > NewImageFile");
  printf(" -c < OldImageFile > NewImageFile");
  exit (8);
}


int main(int argc, const char * argv[]) {
  int i, j;
  int flag1 = 0; //-e switch (edge draw)
  int flag2 = 0; //-c switch (circle draw)
  int numRows, numCols;
  
  char **header;
  int **content;

  //command line argument parsing
  //turn flag switches on or off
  for(i = 1; i < argc; i++) {

    if(strncmp(argv[i], "-e", 2) == 0) {
      //set flag on
      flag1 = 1;
    }
    if(strncmp(argv[i], "-c", 2) == 0) {
      //set flag on
      flag2 = 1;
    }
    if(strncmp(argv[i], "-h", 2) == 0) {
      usage();
    }

  }


  //read pgm file with pgmRead() function
  content = pgmRead(&header[0], &numRows, &numCols);

  /*To test what I have working so far.  Gonna print the information I have
   * */
  printf("%d\n", numRows);
  printf("%d\n", numCols);





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



    // write your code here
    
    // draw
    // draw in picture, write you code here
    
    // write image back
    // write your code here
    
    return 0;
}

