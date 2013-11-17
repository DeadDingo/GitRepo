#ifndef cscd240_lab8_h
#define cscd240_lab8_h

#define null NULL

#include <string.h>

#endif



/*Methods that interface directly with the user
* */
void usage( void );

/*Displays file format error*/
void fileFormatError( void );

//Displays Menu
int menu( void );

//================================


/*Opens file for reading and returns file pointer
* */
FILE *openFile(int argc, char *argv[]);

/*Reads the first element in the file and returns it
* */
int readMonth(FILE *fin);

/*Populates the Array
* */
int *fillArray(int month, FILE *fin);


//=================================

void displayMaxTemp(int *temps);

void displayMinTemp(int *temps);

void displayMedianTemp(int *temps);
