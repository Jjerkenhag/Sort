#include "Menu.h"
#include <stdio.h>

void menu(int& menuChoice){
	//Menu choose between generate, sort, print and quit
	cout << "Menu:\n1. Generate\n2. Sort\n3. Print\n4. Quit\n" << endl;
	
	cin >> menuChoice;

	/*while (menuChoice > 4 || menuChoice < 1)
	{
		cout << "Invalid input. Try again." << endl;

		cin >> menuChoice;
	}*/

	return;
}