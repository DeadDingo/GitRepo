/**
 * secureinput.c
 * Written By voodoo
 * May 3, 2014
 * 
 * This program will experiment with memory checking to safegaurd input
 * */

int main(void) {

  char buffer[1024];
  char *input = (char *)calloc('0', sizeof(buffer));
  void *mem_check = &input + (sizeof(buffer) * 2);
  mem_check = &input + (sizeof(buffer)*2);
  
  
  //read input character by character.  A char takes up 1 bytes in memory
  //check if the memory address is currently pointing to the location pointed to by mem_check
  //if it is, quit input.


}
