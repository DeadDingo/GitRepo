/**
 * Packsoup.c
 *
 *
 * Written by Voodoo
 * 12.21.2013
 *
 * */

#include "packetsoup.h"

unsigned short in_cksum(unsigned short *ptr, int nbytes) {

  register long sum;
  u_short oddbyte;
  register u_short answer;

  sum = 0;
  while(nbytes > 1) {
    sum += *ptr++;
    nbytes -= 2;
  }

  if(nbytes == 1) {
    oddbyte = 0;
    *((u_char *) & oddbyte ) = *(u_char *) ptr;
    sum += oddbyte;
  }

  sum = (sum >> 16) + (sum & 0xffff);
  sum += (sum >> 16);
  answer = ~sum;

  return answer;

}

void Usage( void ) {

  puts("Usage: ");
  puts(" -s <source address>");
  puts(" -d <destination address>");
  puts(" -p <payload size>");

  printf("FloodTarget -s <source address> -d <destination address> -p <payload size>\n");

  exit(8);

}
