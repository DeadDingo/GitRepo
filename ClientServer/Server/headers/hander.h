/**
 * handler.h
 * 
 * Written By Josh Harshman
 * April 23, 2014
 * 
 * */

#ifndef HANDLER_H
#define HANDLER_H

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
void handler(int *onflag);



//----[end prototypes]----

#endif
