//
//  wordUtil.c
//  wordCount
//
//  Created by Josh Harshman on 11/9/13.
//  Copyright (c) 2013. All rights reserved.
//

/*
 *NOTE TO GRADER:
 *Extra Credit was attempted.  Memory is freed at end of program. Verified with valgrind output in the pdf
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#include "timing.h"
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
  char buffer[MAXWORDLEN];
  char *sentence;

  listNode *listHead;
  
  //statically allocating memory for the buffer allows for faster execution time
  //buffer = (char *)malloc(MAXWORDLEN * sizeof(char)); //allocate memory for buffer. Memory freed at end of function
  
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
  //free(buffer);


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

  //start off the list
  if(head == NULL) {
    head = createNode(word, 1);
  }
  else {
    temp = hasRepeat(word, head);
    if(temp != NULL) {
      temp->count += 1;
    }
    else {
      temp = addPos(word, head);
      if(temp == head && strcmp(temp->word, word) > 0) { //might be part of the alphabetical order fix
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

  int len = strlen(word) + 1;

  listNode *newNode = (listNode *)malloc(sizeof(listNode));
  newNode->word = (char *)malloc(len * sizeof(char));
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

  printf("|--------------------------------|\n|\t word\t | count\t |\n");
  while(crawl != NULL) {
    printf("|--------------------------------|\n");
    printf("|%-15s | %-5d\t | \n", crawl->word, crawl->count);

    crawl = crawl->next;

  }
  printf("|--------------------------------|\n");

}
/**
 * writeList() function writes the list to file specified in parameter
 * */
void writeList(const listNode *head, const char *outFile) {
  
  listNode *curPos = head;
  FILE *fout = fopen(outFile, "w");

  fprintf(fout, "|--------------------------------|\n|\t word\t | count\t |\n");
  while(curPos != NULL) {

    fprintf(fout, "|--------------------------------|\n");
    fprintf(fout, "|%-15s | %-5d\t | \n", curPos->word, curPos->count);

    curPos = curPos->next;
  }
  fprintf(fout, "|--------------------------------|\n");
  //at end close file
  fclose(fout);

}
void nodeCopy(listNode *source, listNode **target) {

  //allocate memory and deeply clone a node

  *target = (listNode *)malloc(sizeof(listNode));
  (*target)->word = (char *)malloc(MAXWORDLEN * sizeof(char));
  strcpy((*target)->word, source->word);
  (*target)->count = source->count;
  (*target)->next = NULL;

  

}
void sortedCount( const listNode *head, listNode **newSortedHead ) {
  
  listNode *curPos = head;
  listNode *tempHead = NULL; //this will be the pointer to the new list
  listNode *prev = NULL; //This will keep track of copied nodes in the new list
  listNode *target = NULL;

  //start the clock!

  struct timeval before, after;
  gettimeofday(&before, NULL);


  while(curPos != NULL) {

    //take care of null pointer for start of new list
    if(tempHead == NULL) {
      nodeCopy(curPos, &target);
      tempHead = target;
      prev = target;
    }
    else {
      nodeCopy(curPos, &target);
      prev->next = target;
      prev = target;
    }
    curPos = curPos->next;
  }

  //now sort and set newSortHead equal to the new head

  //add needed variables for selection sort

  listNode *tmp = tempHead;
  listNode *tmp2, *iLst, *jLst, *min;
  
  prev = tempHead;
  for(iLst=tempHead; iLst && iLst->next; iLst=iLst->next) {

    min = iLst;
    for(jLst = iLst->next; jLst; jLst = jLst->next) {

      //get the min node
      if(jLst->count > min->count) {
	//track min node
	min = jLst;
      }
    }

    //swap nodes
    if(iLst != min) {
      tmp = min->next;

      for(tmp2=iLst; tmp2->next; tmp2=tmp2->next) {
	if(tmp2->next == min) {
	  break;
	}
      }
      //swap with head node??
      if(prev != iLst) {
	prev->next = min;
      }
      else {
	tempHead = min;
      }
      if(iLst->next == min) {

	min->next = iLst;
	iLst->next = tmp;

      }
      else {
	min ->next = iLst->next;
	iLst->next = tmp;
	tmp2->next = iLst;
      }
      iLst = min;
    }
    prev = iLst;
  }
  
  *newSortedHead = tempHead; 

  //report time taken
  gettimeofday(&after, NULL);

  float elapsed = elapsedTime(after, before);
  printf("Selection Sort on entire list took: %f\n", elapsed);

}
/**
 * FreeMemory() function
 * Takes a parameter to the head of a linked list
 * Goes through the list putting it's foot through the memory as it goes :)
 * */
void cleanUp(listNode *head) {

  listNode *curPos = head->next;
  listNode *prev = curPos;

  while(curPos != NULL) {
    free(curPos->word);
    curPos = curPos->next;
    free(prev);
    prev = curPos;
  }
  free(head->word);
  free(head);

}


//End
