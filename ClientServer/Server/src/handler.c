/**
 * handler.c
 * 
 * Written By Josh Harshman
 * April 23, 2014
 * */

//define some global variables
int g_flag = 0; //default off

void handler(int *onflag) {

  int listenfd = 0, connfd = 0, *new_sock;
  struct_sockaddr_in serv_addr;
  pthread_attr_t attr;

  //char sendbuf[1025];

  listenfd = socket(AF_INET, SOCK_STREAM, 0); //create an un-named socket inside the kernel

  //set memory
  //memset(sendbuf, '0', sizeof(sendbuf));
  memset(&serv_addr, '0', sizeof(serv_addr));

  //set struct member variables
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(PORT); //define variable PORT in handler.h file

  bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

  listen(listenfd, BACKLOG_SIZE);

  //init attributes
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, DETATCHED);
  
  
  while(g_flag) {

    connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
    if(connfd < 0)
      printf(ANSI_COLOR_RED "[-]" ANSI_COLOR_RESET " Error on Client Accept\n");
    else
      printf(ANSI_COLOR_YELLOW "[+]" ANSI_COLOR_RESET " Connection Established\n");

    pthread_t sniffer_thread;
    new_sock = malloc(1);
    *new_sock = connfd;
    
    //dispatch thread to handle connection
    pthread_create(&sniffer_thread, &attr, process_connection, (void *)new_sock);

  }

  //notification of quitting
  printf(ANSI_COLOR_CYAN "[*]" ANSI_COLOR_RESET " Server exiting cleanly...\n");

  //clean up attributes
  free(new_sock);
  pthread_attr_destroy(&attr);
  pthread_exit(NULL);
}


void *process_connection(void *socket) {

  int sock = *(int *)socket; //get socket descriptor

  printf(ANSI_COLOR_CYAN "[*]" ANSI_COLOR_RESET);
  printf(" In thread processing connection %d\n" sock);

  //interact with client

  pthread_exit(NULL);
}
