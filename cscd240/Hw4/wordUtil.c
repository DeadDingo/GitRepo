//
//  wordUtil.c
//  wordCount
//
//  Created by on 11/9/13.
//  Copyright (c) 2013. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "wordUtil.h"

//define all funcions in wordUtil.h here

listnode *extract( const char *line, listnode *oldHead ) {

  int i;
  char buffer[MAXWORDLEN];

  while(line[i] != '\0') {

    if( isLetter(line[i]) ) {
      strcpy( buffer[i], line[i]);
    }
  }

  //create and return node pointer
}
int isLetter( char c ) {

  if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' ) {
    //the character is a letter!
    return 1;
  }
  
  return 0; //returns if not a character

}
