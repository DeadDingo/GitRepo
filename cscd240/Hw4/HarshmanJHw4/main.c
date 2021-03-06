//
//  main.c
//  wordCount
//
//  Created by Tony Tian on 11/9/13.
//  Copyright (c) 2013 Tony Tian. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordUtil.h"
#include "timing.h"

int main(int argc, const char * argv[])
{
  //start the clock
  struct timeval entireBefore, entireAfter;
  struct timeval extractBefore, extractAfter;
  gettimeofday(&entireBefore, NULL);
    
    //the following commented out piece of code demonstrates the unit test of extract() function
    //const char *s = "Basically, I'm scanning in the strings from a file using fscanf, then for each string calling my function From a file FILE \n";
    //listNode *oldHead = NULL;
    //listNode * head = extract( s, oldHead );
    //showList(head);
  
    
    char line[MAXLINESIZE];
    listNode *oldHead = NULL;
    listNode *newHead = NULL;
    listNode *sortedFreq = NULL;
    
    if ( argc < 4 )
    {
        printf( "Usage: ./wordCount inputFile  outputSortedAlpha  outputSortedOcurrentce\n");
        exit(1);
    }
    FILE *input = fopen( argv[1], "r" );
    if(input == NULL)
    {
        printf("Please type in the correct file name!\n");
        exit(1);
    }
    int c = 0;
    gettimeofday(&extractBefore, NULL); //set timer function
    while ( fgets( line, MAXLINESIZE, input ) != NULL )
    {
        if( strlen(line) <= 1 )  //we do NOT need to process empty lines or lines with only '\n'
            continue;            //check api of fgets() in the lecture notes to see how fgets works, what it appends to each read? 
        
        newHead = extract( line, oldHead );
        
        c ++;
        if ( c % 200 == 0)
            printf("%d lines been processed.\n", c);

        oldHead = newHead;
    }
    gettimeofday(&extractAfter, NULL);
    float total = elapsedTime(extractAfter, extractBefore);
    printf("Time taken to extract each word and add in order to list: %f\n", total);

    sortedCount( newHead, &sortedFreq );
    writeList( newHead, argv[2] );
    writeList( sortedFreq, argv[3] );
    
    showList( newHead );

    cleanUp(newHead);
    cleanUp(sortedFreq);
    
    fclose(input);

    //calculate execution time for entire program
    gettimeofday(&entireAfter, NULL);
    float elapsed = elapsedTime(entireAfter, entireBefore);
    printf("Program Execution from start to finish took: %f\n", elapsed);
    return 0;
}

