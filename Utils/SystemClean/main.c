/**
 * Easy Run System Cleaner
 * Utilizes currently existing software to clean the system
 * 
 * Written By Josh Harshman (DeadDingo)
 * All Rights Reserved 12.20.2013
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int menu( void );

//============================

int menu( void ) {

  int choice;
  puts("1.  Run Cleaner");
  puts("2.  Run Anti Malware");
  puts("3.  Run Defrag");
  puts("4.  Quit");

  scanf("%d", &choice);
  return choice;

}
int main( void ) {

  int choice;

  do {

    choice = menu();
    
    switch(choice) {
    case (1) :
      //run cleaner
      if(system("Progs/CCleaner") == -1)
	puts("Could not run C-Cleaner");
      break;
    case (2) :
      //run Malware Bytes
      if(system("Progs/mbytes") == -1)
	puts("Could not run MalwareBytes");
      break;
    case (3) :
      //run Defrag
      if(system("defrag C: /H /U /V") == -1)
	puts("Defrag Failed");
      break;
    case (4):
      //Quit
      puts("Keep it clean ^.^");
      break;
    default :
      puts("Input not recognized");
      continue;
    }

  }while(choice != 4);

  return 0;

}
