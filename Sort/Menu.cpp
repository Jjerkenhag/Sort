#include <stdio.h>

#include "Menu.h"
#include "AAA.h"
#include "QuickSort.h"

void sortMenu(vector<int> &numbers)
{
	chrono::time_point<chrono::system_clock> start, stop;
	chrono::duration<double, ratio<1, 10000000>> time;

	int menuChoice;

	cout << "Menu:\n1. GPU\n2. CPU\n" << endl;

	cin >> menuChoice;

	switch (menuChoice)
	{
	case 1:
		start = chrono::system_clock::now();

		AAAsort(numbers, 10);

		stop = chrono::system_clock::now();

		time = (stop - start);

		cout << endl << numbers.size() << " numbers sorted in " << (time.count() / 10000000) << " seconds.\n" << endl;
		break;
	case 2:
		start = chrono::system_clock::now();

		QuickSort::Sort(numbers);

		stop = chrono::system_clock::now();

		time = (stop - start);

		cout << endl << numbers.size() << " numbers sorted in " << (time.count() / 10000000) << " seconds.\n" << endl;

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