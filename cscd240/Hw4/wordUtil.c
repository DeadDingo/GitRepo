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

/**
 *Function Extracts each word from a line
 */
listNode *extract( const char *line, listNode *oldHead ) {

  int i;
  int len = 0; //length of word
  int inword = 0; //start of word flag
  char * wordstart;
  char *buffer;
  char *sentence;

  buffer = (char *)malloc(MAXWORDLEN * sizeof(char)); //allocate memory for buffer. Memory freed at end of function
  
  sentence = line;

  //tokenize!
  while ( *sentence != '\n' ) {

    if( isLetter( *sentence ) ) {

      if( ! inword ) {
	inword = 1;
	wordstart = sentence;
      }
      len++;

    }
    else if( inword ) {


      strncpy(buffer, wordstart, len);
      buffer[len] = '\0';
      if(strlen(buffer) == 1) {

	if(*buffer == 'a' || *buffer == 'A' || *buffer == 'I') {
	  //call to addWord.  Will return new head pointer
	  return addWord(buffer, oldHead);
	}

      }
      else {
	//call to addWord.  Will return new head pointer
	return addWord(buffer, oldHead);

      }

      inword = 0;
      len = 0;

    }

    sentence++;

  }

  //Free the allocated buffer
  free(buffer);

}
/**
 * Function Tests for valid character
 */
int isLetter( char c ) {

  if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) {
    //the character is a letter!
    return 1;
  }
  
  return 0; //returns if not a character

}
/**
 * Function Adds word into node
 * Functions used:
 *   
 */
listNode *addWord(const char *word, listNode *head) {

  


}
listNode *hasRepeat(const char *word, listNode *head) {

  listNode *curPos = head;
  int len = strlen(word);

  do {

    switch(len) {
    case ( 1 ) :
      if(curPos->word == word)
	return curPos;
      break;
    default :
      if(strcmp(curPos->word, word) == 0)
	return curPos;
      break;
    }

    //move to next node
    curPos = curPos->next;

  }while(curPos != NULL);

  return NULL;

}
listNode *addPos(const char *word, listNode *head) {

  listNode *curPos = head;

  do {

    if(strcmp(curPos->word, word) > 0 )
      return curPos;

    curPos = curPos->next;

  }while(curPos->next != NULL);

  //return end of list
  return curPos;

}
listNode *addFirst(listNode *head, listNode *toAdd) {

  if(head == NULL) {
    return toAdd;
  }
  else {

    toAdd->next = head;
    return toAdd;

  }

}
/**
 * Helper function to create new nodes
 * */
listNode *createNode(const char *word, int count) {

  listNode *newNode = (listNode *)malloc(sizeof(listNode));
  newNode->word = (char *)malloc(sizeof(listNode));
  strcpy(newNode-word, word);
  newNode->count = count;
  return newNode;

}


//NOTES
/*How to make a new node
* listNode *createNode(char word[], int count) {
*   listNode * ret =  (listNode *)malloc(sizeoof(listNode));
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
