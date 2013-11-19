//Fun With Structures
//
//Written By Josh Harshman
//All rights reserved
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct database {

  int id;
  char *name;
  float salary;

};

int main (int argc, char *argv[]) {

  struct database emp1;

  //set employee id
  emp1.id = 100123;
  
  //set employee base salary
  emp1.salary = 10.75;

  //allocate space for array
  emp1.name = (char *)malloc(20 * sizeof(char));

  strcpy(emp1.name, "John Smith");

  //print information about employee

  printf("%s\n", emp1.name);
  printf("%d\n", emp1.id);
  printf("%.2f\n", emp1.salary);

  free(emp1.name);

  return 0;

}
