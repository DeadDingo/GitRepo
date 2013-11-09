#include <stdio.h>

int main(void) {

  int twod[4][3] = { {0,1,2}, {10,11,12}, {20,21,22}, {30,31,32} };

  int *ptr = *twod;

  /*Memory Map*/

  printf("sizeof(ptr) %ld\n", sizeof(ptr)); //prints the size of the ptr pointer
  printf("sizeof(twod[0]) %ld\n", sizeof(twod[0])); //prints the size twod array at base index
  printf("sizeof(twod[0][0]) %ld\n", sizeof(twod[0][0]));  //prints the size of the twod array at the base index
  //should the the same value as the last print statement

  printf("twod %p\n", twod); //prints the base address of twod array
  printf("ptr %p\n", ptr); //prints the base address of the twod array which is pointed to by ptr

  printf("&twod[0] %p\n", &twod[0]); //this is going to print the base address of the twod array
  printf("&twod[0][0] %p\n", &twod[0][0]); //this will print out the base address of the twod array
  printf("&twod[0][1] %p\n", &twod[0][1]); //this will print out the address of *(*(twod) +1)
  printf("&twod[0][2] %p\n", &twod[0][2]); //this will print out the address of *(*(twod) +2)

  printf("&twod[1] %p\n", &twod[1]);  //this will print out the address of twod[1][0]
  printf("&ptr %p\n", &ptr);  //this will print out the address of ptr

  /*End memory map*/
  printf("\n\n");
  //-----------------------------

  printf("twod + 3 is: %p\n", twod + 3); //pointer
  printf("*(*(twod+1)) is: %d\n", *(*(twod+1))); //decimal
  printf("*twod + 1 is: %p\n", *twod + 1); //pointer.. which is interesting because of the dereferencing *
  printf("*towd[2] is: %d\n", *twod[2]); //decimal
  printf("*(twod+2)+2 is: %p\n", *(twod+2)+2); //pointer
  printf("twod[1] is: %p\n", twod[1]); //pointer
  printf("twod[1][2] is: %d\n", twod[1][2]); //decimal
  printf("\n");
  printf("ptr %p\n", ptr); //pointer
  printf("twod[1] %p\n", twod[1]); //pointer
  printf("ptr[1] %d\n", ptr[1]); //decimal
  printf("ptr + 1 %p\n", ptr + 1); //pointer
  printf("*(ptr + 1) %d\n", *(ptr + 1)); //decimal
  printf("twod+1 %p\n", twod+1); //pointer
  printf("*twod+1 %p\n", *twod+1); //pointer;
  printf("ptr[8] %d\n", ptr[8]); //decimal

  //--------------------------------

  

}
