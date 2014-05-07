/**
 * comms.h
 * Written By Josh Harshman
 * May 3, 2014
 * */

#ifndef COMMS_H
#define COMMS_H

#define PORT 4444

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

void join(const char *daddr);

int receive();

void reply(char *reply);


#endif
