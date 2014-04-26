/**
 * main.c
 * 
 * Written By Josh Harshman
 * April 24, 2014
 * */

#include "handler.h"

int main ( int argc, char *argv[ ] ) {

  pthread_attr_t attr;

  //inits
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, CREATE_THREAD_JOINABLE);

  printf(ANSI_COLOR_CYAN "[*]" ANSI_COLOR_RESET " Starting server\n");

  pthread_exit(NULL);

}
