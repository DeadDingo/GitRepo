/**
 * secureinput.c
 * Written By voodoo
 * May 3, 2014
 * 
 * This program will experiment with memory checking to safegaurd input
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {

  char buffer[10];
  char *input = (char *)calloc('0', sizeof(buffer));

  while(1) {
    fgets(buffer, sizeof(buffer), stdin);
    strncpy(input, buffer, sizeof(buffer));
    puts(input);
  }

}
