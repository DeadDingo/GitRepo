/**
 * comms.c
 * Written By Josh Harshman
 * May 3, 2014
 * */

#include "../headers/comms.h"

void join(const char *daddr) {

  int sockfd = 0;
  struct sockaddr_in serv_addr;
  
  memset(&serv_addr, '0', sizeof(serv_addr));
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    printf(ANSI_COLOR_RED "[-]" ANSI_COLOR_RESET "Could not open socket\n");
  
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT); //port defined in .h file
  
  if(inet_pton(AF_INET, daddr, &serv_addr.sin_addr) <= 0)
    printf(ANSI_COLOR_RED "[-]" ANSI_COLOR_RESET "inet pton error occured\n");
  else if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    printf(ANSI_COLOR_RED "[-]" ANSI_COLOR_RESET " Failed to Connect\n");
  else {
    printf(ANSI_COLOR_YELLOW "[+]" ANSI_COLOR_RESET " Connection Established\n");
    receive(sockfd);
  }
} 

int receive(int sockfd) {
  int n = 0;
  // void *memlimit = NULL;
  char recvbuff[1024];
  //char *input = (char *)calloc('0', sizeof(char));
  memset(recvbuff, '0', sizeof(recvbuff));

  while((n = read(sockfd, recvbuff, sizeof(recvbuff) - 1)) > 0) {
    recvbuff[n] = 0;
    fputs(recvbuff, stdout);
    fflush(stdout);
  }
  return 0;
}
