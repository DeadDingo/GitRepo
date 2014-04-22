/**
 * Demonstrates the use of mutex variables
 * 
 * Written By Josh Harshman
 * April 21, 2014
 * */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMTHREADS 4
#define VECLEN 100

typedef struct {
  double *a;
  double *b;
  double *sum;
  int veclen;
} DOTDATA;

DOTDATA dotstr;
pthread_t callThd[NUMTHREADS];
pthread_mutex_t mutexsum;

void *dotprod(void * arg) {

  int i, start, end, len;
  long offset;
  double mysum, *x, *y;
  offset = (long)arg;

  len = dotstr.veclen;
  start = offset*len;
  end = start + len;
  x = dotstr.a;
  y = dotstr.b;

  //preform the dot product and assign value to variable in structure

  mysum = 0;
  for(i = start; i < end; i++) {
    mysum += (x[i] * y[i]);
  }

  //lock the mutex prior to updating the value in the shared structure
  pthread_mutex_lock(&mutexsum);
  dotstr.sum += mysum;
  pthread_mutex_unlock(&mutexsum);

  pthread_exit((void *) 0);

}

int main(void) {

  long i;
  double *a, *b;
  void *status;
  pthread_attr_t attr;

  //assign storage and init variables
  a = (double*)malloc(NUMTHREADS*VECLEN*sizeof(double));
  b = (double*)malloc(NUMTHREADS*VECLEN*sizeof(double));

  for(i = 0; i < VECLEN*NUMTHREADS; i++) {
    a[i]=1.0;
    b[i]=a[i];
  }

  dotstr.veclen = VECLEN;
  dotstr.a = a;
  dotstr.b = b;
  dotstr.sum = 0;

  pthread_mutex_init(&mutexsum, NULL);

  //create threads to perform the dotproduct
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


  pthread_exit(NULL);

}
