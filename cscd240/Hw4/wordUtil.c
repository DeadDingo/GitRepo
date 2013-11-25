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

  for(i = 0; line[i] != '\0'; i++) {
    if( isLetter(line[i]) ) {
      strcpy(buffer[i], line[i]);
    }
  }

  //

}
int isLetter( char c ) {

  if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' ) {
    //the character is a letter!
    return 1;
  }
  
  return 0; //returns if not a character

}


/*How to make a new node
* listNode *createNode(char word[], int count) {
*   listNode * ret = new (listNode *)malloc(sizeoof(listNode));
*    ret->word = (char *)malloc(MAXLENWORD * sizeof(char));
*    strcpy(ret->word, word);
*    ret->count = count;
*    return ret;
}*/
