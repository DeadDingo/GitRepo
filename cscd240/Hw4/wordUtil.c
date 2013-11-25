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
  int size = strlen(line);
  char buffer[MAXWORDLEN];

  while(line[i] != '\0') {

    if(isLetter( line[i] ) {
	strcpy(buffer[i], line[i]); //copy into temporary word buffer
    }

  }

    //insert word into node

    //return new pointer to linked list

}
