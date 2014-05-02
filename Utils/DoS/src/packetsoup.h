/**
 * Packetsoup.h
 * 
 * Prototype Functions for ICMP Repeater
 *
 * Written By Voodoo
 * 12.21.2013
 * 
 * */


#ifndef PACK_SOUP_H_
#define PACK_SOUP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

typedef unsigned char u8;
typedef unsigned short int u16;


/**
 * Calculates the checksum on a packet to packet basis
 * */
unsigned short in_cksum(unsigned short *ptr, int nbytes);


/**
 * Displays Usage Dialog
 * */
void Usage( void );


#endif
