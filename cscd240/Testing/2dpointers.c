#include <stdio.h>
#include <stdlib.h>

//2 dimensional pointer arithmatic practice
//--


int main( void ) {

  int ara[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

  //we will be using the array name pointer as a pointer to access values since we do not wish to change them

  //print some values
  printf("%d\n", *(*(ara)+1) );

}
