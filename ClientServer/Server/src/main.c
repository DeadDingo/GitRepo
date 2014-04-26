/**
 * main.c
 * 
 * Written By Josh Harshman
 * April 24, 2014
 * */

#include "../headers/handler.h"

int main ( int argc, char *argv[ ] ) {
  
  int *onflag = 0; //server is off
  pthread_attr_t attr;

  //inits
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  printf(ANSI_COLOR_CYAN "[*]" ANSI_COLOR_RESET " Starting server\n");
  handler(&onflag);
  if(*onflag == 1)
    printf(ANSI_COLOR_CYAN "[*]" ANSI_COLOR_RESET " Server running...\n");
  else if(*onflag == 0)
    printf(ANSI_COLOR_CYAN "[*]" ANSI_COLOR_RESET " Server not running...\n");

  pthread_exit(NULL);

}
