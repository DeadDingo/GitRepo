//
//  main.c
//  cscd240PGM
//
//  Created by Josh Harshman
//

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
  int flag1 = 0; //-e switch
  int flag2 = 0; //-c switch
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
  //Will have to move switch statment in final program
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
    
  //Done with argument parsing


  //read pgm file with pgmRead( ) function.
  
  content = pgmRead(header[0], &numRows, &numCols);

    // write your code here
    
    // draw
    // draw in picture, write you code here
    
    // write image back
    // write your code here
    
    return 0;
}

