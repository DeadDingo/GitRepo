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

listNode *extract( const char *line, listNode *oldHead ) {

  int i;
  int len = 0; //length of word
  int inword = 0; //start of word flag
  char * wordstart;
  //char *curPos;
  char *buffer;

  buffer = (char *)malloc(MAXWORDLEN * sizeof(char));
  
  char * sentence = line;

  //tokenize!
  while ( *sentence != '\n' ) {

    //curPos = line + i;

    if( isLetter( *sentence ) ) {

      if( ! inword ) {
	inword = 1;
	wordstart = sentence;
      }
      len++;

    }
    else if( inword ) {

      //curPos = line + wordstart;

      strncpy(buffer, wordstart, len);
      buffer[len] = '\0';
      if(strlen(buffer) == 1) {

	if(buffer == 'a' || buffer == 'A' || buffer == 'I') {
	  //add to list
	}

      }
      else {

	//it is a word greater than 1 character in length.  Add to list

      }

      inword = 0;
      len = 0;

    }

    //i++;
    sentence++;

    // if(line[i] == '\0')
    //  break;

  }

  //

}
int isLetter( char c ) {

  if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) {
    //the character is a letter!
    return 1;
  }
  
  return 0; //returns if not a character

}




//NOTES
/*How to make a new node
* listNode *createNode(char word[], int count) {
*   listNode * ret = new (listNode *)malloc(sizeoof(listNode));
*    ret->word = (char *)malloc(MAXLENWORD * sizeof(char));
*    strcpy(ret->word, word);
*    ret->count = count;
*    return ret;
}*/


/*
listNode * addFirst(listNode *oldhead, listNode *toAdd) {

if(oldhead == NULL)
  return toAdd;
else {
  toAdd->next = oldhead;
  return toAdd;
}

} */
