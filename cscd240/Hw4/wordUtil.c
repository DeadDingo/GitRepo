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
#include <ctype.h>
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

  listNode *listHead;

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

      for(i = 0; buffer[i] != '\0'; i++) {
	buffer[i] = tolower(buffer[i]);
      }

      if(strlen(buffer) == 1) {
	if(*buffer == 'a' || *buffer == 'i') {
	  //call to addWord.  Will return new head pointer
	  oldHead =  addWord(buffer, oldHead);
	}

      }
      else {
	//call to addWord.  Will return new head pointer
	oldHead = addWord(buffer, oldHead);
      }

      inword = 0;
      len = 0;

    }

    sentence++;

  }

  //Free the allocated buffer
  free(buffer);


  return oldHead;

}
/**
 * Function Tests for valid character
 */
int isLetter( char c ) {

  if( c >= 'a' && c <= 'z' ) {
    //the character is a letter!
    return 1;
  }
  if(c >= 'A' && c <= 'Z') {
    return 1;
  }
  
  return 0; //returns if not a character

}
/**
 * Function Adds word into node
 * 
 */
listNode *addWord(const char *word, listNode *head) {

  listNode *temp;

  printf("Word being passed in currently: %s\n", word);
  printf("Length of word being passed currently: %lu\n", strlen(word));

  //start off the list
  if(head == NULL) {
    head = createNode(word, 1);
  }
  else {
    temp = hasRepeat(word, head);
    if(temp != NULL) {
      printf("Duplicate word detected.  The word is %s\n", word);
      temp->count += 1;
    }
    else {
      temp = addPos(word, head);
      if(temp == head) {
	temp = createNode(word, 1);
	return addFirst(head, temp);
      }
      else {
	listNode *newNode = createNode(word, 1);
	newNode->next = temp->next;
	temp->next = newNode;
      }

    }

  }

  return head;
  
}
listNode *hasRepeat(const char *word, listNode *head) {

  listNode *curPos = head;
  int len = strlen(word);

  while(curPos != NULL) {
    
    switch(len) {
    case ( 1 ) :
      if(*curPos->word == *word)
	return curPos;
      break;
    default :
      if(strcmp(curPos->word, word) == 0)
	return curPos;
      break;
      }

    //move to next node
    curPos = curPos->next;

  }

  return NULL;

}
listNode *addPos(const char *word, listNode *head) {

  listNode *curPos = head->next;
  listNode *prev = head;
  int len = strlen(word);

  while(curPos != NULL) {
    if(len == 1) {
      if(*curPos->word > *word)
	return prev;
    }
    else {
      if(strcmp(curPos->word, word) > 0)
	return prev;
    }

    prev = curPos;
    curPos = curPos->next;

  }

  return prev;

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
  strcpy(newNode->word, word);
  newNode->count = count;
  newNode->next = NULL;
  return newNode;

}
/**
 *showList() function prints out neatly organized listing of all the words in the linked list
 * */
void showList(const listNode *head) {
  listNode *crawl = head;

  printf("---------------------------------\n|\t word\t | count\t |\n");
  while(crawl != NULL) {
    printf("----------------------------------\n");
    printf("|%-15s | %-5d\t | \n", crawl->word, crawl->count);

    crawl = crawl->next;

  }

}
/**
 * writeList() function writes the list to file specified in parameter
 * */
void writeList(const listNode *head, const char *outFile) {

  FILE *fout = fopen(outFile, "w");

  

  //at end close file
  fclose(fout);

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
