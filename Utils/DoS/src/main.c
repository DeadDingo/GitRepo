/**
 * DoS : Denial Of Service Attack
 * Accomplished via ICMP Flooding
 *
 * Orriginally Written By Silver Moon
 *
 * Version 2 Written By Josh Harshman (DeadDingo)
 * All Rights Reserved 12.21.2013
 *
 * */

#include "packetsoup.h"

int main ( int argc, char *argv[ ] ) {

  unsigned long daddr;
  unsigned long saddr;
  int payload_size = 0, sent, sent_size, i;


  /*
  * Argument Parsing...*/

  if(argc < 3) {
    Usage();
  }

  for( i = 0; i < argc; i ++ ) {
    
    if(strncmp(argv[i], "-s", 2) == 0) {
      saddr = (unsigned long) argv[i] + 1;
    }
    if(strncmp(argv[i], "-d", 2) == 0) {
      daddr = (unsigned long) argv[i] + 1;
    }
    if(strncmp(argv[i], "-p", 2) == 0) {
      payload_size = atoi(argv[i] + 1);
    }
  } //end for loop
  //end arg parsing

  //echo back arguments for testing
  printf("Source Address (saddr): %lu\n", saddr);
  printf("Destination Address (daddr) %lu\n", daddr);
  printf("Payload Size (payload_size) %d\n", payload_size);

  return 0;
}
