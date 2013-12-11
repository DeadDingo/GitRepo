/**
 * ICMP ping flood
 *
 * Written By Josh Harshman
 * All Rights Reserved 12.10.2013
 **/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>

void usage( void );
//= = = = = = = = = = = = = = = = = = = = = = = = = = =

void usage( void ) {
  printf("Usage:\n");
  printf(" -s source address\n");
  printf(" -d destination address\n");
  printf(" -p payload size\n");
  exit (8);

}
int main(int argc, char *argv[]) {

  //argument parsing
  if(argc < 3)
    usage();


  //

}
