/**
 * Demonstrates the use of mutexes in conjunction with condition variables
 * 
 * */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


/*
 * Define Global Variables
 * */
#define NUM_THREADS 3
#define TCOUNT 10
#define COUNT_LIMIT 12

int count = 0;
int thread_ids[3] = {0, 1, 2};
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;


void *inc_count(void *t) {

  int i;
  long my_id = (long)t;

  for(i = 0; i < TCOUNT; i++) {
    pthread_mutex_lock(&count_mutex);
    count++;

    //check the value of count and signal waiting thread when condition is reached
    //note:  that this occurs while mutex is locked.

    if(count == COUNT_LIMIT) {
      pthread_cond_signal(&count_threshold_cv);
      printf("inc_count(): thread %ld, count = %d Threshold reached\n", my_id, count);
    }
    printf("inc_count(): thread %ld, count = %d, Unlocking mutex variable\n", my_id, count);
    pthread_mutex_unlock(&count_mutex);

    //do some work so threads can alternate on mutex lock
    sleep(1);

  }

  pthread_exit(NULL);

}


void *watch_count(void *t) {


  long my_id =  (long)t;

  printf("Starting watch_count(): thread %ld\n", my_id);

  /*
   * Lock Mutex and wait for signal.  Note that the pthread_cond_wait rountine will automatically
   * unlock the mutex while it waits.  Also note that if COUNT_LIMIT is reached before this rountine is run
   * by the waiting thread, the loop will be skipped to prevent pthread_cond_wait from never running.
   */

  pthread_mutex_lock(&count_mutex);
  while(count<COUNT_LIMIT) {
    pthread_cond_wait(&count_threshold_cv, &count_mutex);
    printf("watch_count(): thread %ld Condition Signal received.\n", my_id);
    count+=125;
    printf("watch_count(): thread %ld count now = %d.\n", my_id, count);
  }
  pthread_mutex_unlock(&count_mutex);

  pthread_exit(NULL);
}


int main(void) {

  int i, rc;
  long t1=1, t2=2, t3=3;
  pthread_t threads[3];
  pthread_attr attr;
  
  //init mutex and condition vars
  pthread_mutex_init(&count_mutex, NULL);
  pthread_cond_init(&count_threshold_cv, NULL); //note null attribute (previous line as well)

  pthread_attr_init(&attr);
  pthread_setdetatchstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_create(&threads[0], &attr, watch_count, (void *)t1);
  pthread_create(&threads[1], &attr, inc_count, (void *)t2);
  pthread_create(&threads[2], &attr, inc_count, (void *)t3);


  


  pthread_exit(NULL);

}
