#include <pthread.h>
#include <stdio.h>


#define NUM_THREADS 5


void *PrintHello(void *threadid) {

  long tid;
  tid = (long)threadid;
  printf("Hello World!  I am thread #%ld\n", tid);
  pthread_exit(NULL);
  
}

int main(void) {


  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for(t = 0; t < NUM_THREADS; t++) {
    printf("In main, creating thread #%ld\n", t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);

    if (rc) { 
      printf("Error creating thread.  Return code: %d\n", rc);
      exit(-1);
    }
    
  }


  //last thing main should do...
  pthread_exit(NULL);


}
