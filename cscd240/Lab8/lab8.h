#ifndef cscd240_lab8_h
#define cscd240_lab8_h

#define null NULL
#include <string.h>

#endif


/*Displays Usage*/
void usage( void );

/*Displays file format error*/
void fileFormatError( void );

/*Opens file for reading and returns file pointer
* */
FILE *openFile(int argc, char *argv[]);

/*Reads the first element in the file and returns it
* */
int readMonth(FILE *fin);

/*Populates the Array
* */
int *fillArray(int month, FILE *fin);
