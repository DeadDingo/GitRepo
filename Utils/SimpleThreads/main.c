/**
 * SimpleThreads
 * 
 * Given an input, the base input will by accessed by individual threads and multiplied by itself to create a new base.
 * Three threads will be used so the input will be multiplied by itself three separate times.
 * 
 * Written By Josh Harshman
 * April 22, 2014
 * */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

//global variables
#define NUMTHREADS 3
int total = 0; //default value
pthread_mutex_t total_mutex;

void *dowork(void *threadid) {
  long tid = (long)threadid;
  pthread_mutex_lock(&total_mutex);
  total *= total;
  printf(ANSI_COLOR_CYAN "[*]" ANSI_COLOR_RESET);
  printf(" thread %ld calculated sum = %d\n", tid, total);
  pthread_mutex_unlock(&total_mutex);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

  if(argc <= 1) {
    printf(ANSI_COLOR_RED "[-]" ANSI_COLOR_RESET);
    printf(" Invalid number of arguments\n");
    exit(-1); //exit poorly
  }

  total = atoi(argv[1]);
  printf(ANSI_COLOR_CYAN "[*]" ANSI_COLOR_RESET);
  printf(" The base value is: %d\n", total);

  long i;
  int rc;
  pthread_t threads[NUMTHREADS];
  pthread_attr_t attr;
  
  //inits
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_mutex_init(&total_mutex, NULL);

  for(i = 0; i < NUMTHREADS; i++) {
    rc = pthread_create(&threads[i], &attr, dowork, (void *)i);
    if(rc) {
      printf(ANSI_COLOR_RED "[-] failed to create thread" ANSI_COLOR_RESET "\n");
      printf("Return Code: %d", rc);
    }
  }

  for(i = 0; i < NUMTHREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  printf(ANSI_COLOR_YELLOW "[+]" ANSI_COLOR_RESET);
  printf(" Total = %d\n", total);

  pthread_attr_destroy(&attr);
  pthread_mutex_destroy(&total_mutex);
  pthread_exit(NULL);
  return 0;
}
