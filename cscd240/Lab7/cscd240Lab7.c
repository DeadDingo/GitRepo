#include <stdio.h>

void function1(int array[][3], int rows, int cols);
void function2(int array[][3], int rows, int cols);
void function3(int array[], int rows, int cols);
void function4(int array[], int rows, int cols);
void function5(int * array, int rows, int cols);
void function6(int (*twod)[3], int rows, int cols);

//=====================================================

void function1(int array[][3], int rows, int cols) {

  int i;
  int j;
  for(i=0;i<rows;i++) {
    for (j=0;j<cols;j++) {
      printf("%-d ", array[i][j]);
    }
    printf("\n");
  }

  printf("\n");

}
void function2(int array[][3], int rows, int cols) {

  int i, j;
  for( i = 0; i < rows ; i++ ) {
    for( j = cols-1; j >= 0; j-- ) {
      printf("%-d " , array[i][j]);
    }
    printf("\n");
  }

  printf("\n");
}
void function3(int array[], int rows, int cols) {

  int i, j;
  int size = rows * cols;
  i = 0;
  while(i < size) {
    for(j = 0; j < cols; j++) {
      printf("%-d ", array[i]);
      i++;
    }
    printf("\n");;

  }


  printf("\n");
}
void function4(int array[], int rows, int cols) {

  int *ptr, i, j, size;
  size = rows*cols;
  ptr = &array[0];
  i = 0;
  while(i < size) {
    for(j = cols-1; j >= 0; j--) {
      int k = i+j;
      printf("%-d ", *(ptr+k));
    }
    i+=3;
    printf("\n");
  }
  printf("\n");

}
void function5(int * array, int rows, int cols) {

  int i, j, size;

  size = rows*cols;
  i=0;
  while(i < size) {
    for(j = cols-1; j >=0; j--) {
      int k = i+j;
      printf("%-d ", array[k]);
    }
    i+=3;
    printf("\n");

  }
  printf("\n");


}
void function6(int (*twod)[3], int rows, int cols) {

  int i, j;
  
  for(i = 0; i < rows; i++) {
    for(j = 0; j < cols; j++) {
      printf("%-d ", twod[i][j]);
    }
    printf("\n");
  }
  printf("\n");

}

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

  function1(twod, 4, 3);
  function2(twod, 4, 3);
  function3(twod[0], 4, 3);
  function4(twod[0], 4, 3);
  function5(twod[0], 4, 3);
  function6(twod, 4, 3);
  //-------

  return 0;

}
