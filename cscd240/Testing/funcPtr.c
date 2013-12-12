#include <stdio.h>
#include <stdlib.h>


int calc(int x, int y);
void printResult( int x, int y, int (*function)(int, int) );

int calc(int x, int y) {

  return x-y;

}
void printResult( int x, int y, int (*function)(int, int)) {
  
  printf("The Resulting Answer is: %d\n", calc(x, y) );

}
int main ( void ) {

  int a, b;

  printf("enter 2 numbers: ");
  scanf("%d %d", &a, &b);

  //delcare function pointer
  int (*fptr)(int, int);

  //assign function pointer to function
  fptr = &calc;

  printResult(a, b, fptr);

}
