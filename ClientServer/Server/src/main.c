/**
 * main.c
 * 
 * Written By Josh Harshman
 * April 24, 2014
 * */

#include "../headers/handler.h"

int main ( int argc, char *argv[ ] ) {
  
  long tid = 0; //useless thread id.
  pthread_t server_thread;
  pthread_attr_t attr;

  //inits
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  printf(ANSI_COLOR_CYAN "[*]" ANSI_COLOR_RESET " Starting server\n");

  pthread_create(&server_thread, &attr, handler, (void *) tid);

  interact();

  pthread_join(server_thread, NULL);

  pthread_attr_destroy(&attr);
  pthread_exit(NULL);

}
