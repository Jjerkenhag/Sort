#include <stdio.h>

#include "Menu.h"
#include "AAA.h"
#include "QuickSort.h"

void sortMenu(vector<int> &numbers)
{
	int menuChoice;

	cout << "Menu:\n1. GPU\n2. CPU\n" << endl;

	cin >> menuChoice;

	switch (menuChoice)
	{
	case 1:
		AAAsort(numbers, 10);
		break;
	case 2:
		QuickSort::Sort(numbers);
		break;
	default:
		break;
	}
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