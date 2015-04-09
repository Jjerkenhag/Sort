#include "Menu.h"
#include <stdio.h>

void sortMenu()
{
	cout << "Menu:\n1. GPU\n2. CPU\n" << endl;
}

void menu(int& menuChoice)
{
	//Menu choose between generate, sort, print and quit
	cout << "Menu:\n1. Generate\n2. Print\n3. Sort\n4. Check sort\n0. Quit\n" << endl;
	
	cin >> menuChoice;

	/*while (menuChoice > 4 || menuChoice < 1)
	{
		cout << "Invalid input. Try again." << endl;

		cin >> menuChoice;
	}*/

	return;
}