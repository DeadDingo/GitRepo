#include "lab11.h"

int main()
{
    FILE * fin = NULL;
    int total;
    Address * array = NULL;
    int choice;
    fin = openFile();

    array = fillArray(&total, fin);

    fclose(fin);
    fin = NULL;

    do
    {
        switch(choice = menu())
        {
			case 1:	printStreetSortedArray(array, total);
					break;

			case 2: printCitySortedArray(array, total);
					break;

			case 3: printStateCitySortedArray(total, array);
					break;

			case 4:	printZipSortedArray(total, array);
	   }

	}while(choice != 5);

	cleanUp(array, total);
	array = NULL;

    return 0;

}// end main
