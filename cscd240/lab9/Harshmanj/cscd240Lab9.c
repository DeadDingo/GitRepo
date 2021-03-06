#include "lab9.h"

int main()
{
    FILE * fin = NULL;
    int total, choice = 0;
    Address array[10]; // guaranteed 1 to 10 inclusive

    fin = openFile();
    
    total = fillArray(array, fin);
    fclose(fin);
    fin = NULL;
    
    do
    {
        switch(choice = menu())
        {
	case 1 :
	  printStreetSortedArray(array, total);
	  break;

	case 2 : 
	  printCitySortedArray(array, total);
	  break;

	case 3 : 
	  printStateCitySortedArray(total, array);
	  break;

	case 4 :
	  printZipSortedArray(total, array);
	  break;
	}

	}while(choice != 5);
    
    return 0;

}// end main
