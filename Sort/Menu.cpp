#include <stdio.h>

#include "Menu.h"
#include "AAA.h"
#include "QuickSort.h"
#include "bitishSort.h"

void gpuMenu(vector<int> &numbers)
{
	chrono::time_point<chrono::system_clock> start, stop;
	chrono::duration<double, ratio<1, 10000000>> time;

	int gpuMenuChoice;

	cout << "\nGPU Menu:\n1. Dreamsort\n" << endl;

	cin >> gpuMenuChoice;

	switch (gpuMenuChoice)
	{
	case 1:

		cout << "\nDreamsort initiated." << endl;

		start = chrono::system_clock::now();

		AAAsort(numbers, 20);

		stop = chrono::system_clock::now();

		time = (stop - start);

		cout << endl << numbers.size() << " numbers sorted in " << (time.count() / 10000000) << " seconds.\n" << endl;
		break;
	default:
		break;
	}
}

void cpuMenu(vector<int> &numbers)
{
	chrono::time_point<chrono::system_clock> start, stop;
	chrono::duration<double, ratio<1, 10000000>> time;

	int cpuMenuChoice;

	cout << "\nCPU Menu:\n1. Quicksort\n2. \"Bitish\"sort\n" << endl;

	cin >> cpuMenuChoice;

	switch (cpuMenuChoice)
	{
	case 1:

		cout << "\nQuicksort initiated." << endl;

		start = chrono::system_clock::now();

		QuickSort::Sort(numbers);

		stop = chrono::system_clock::now();

		time = (stop - start);

		cout << endl << numbers.size() << " numbers sorted in " << (time.count() / 10000000) << " seconds.\n" << endl;

		break;
	case 2:

		cout << "\n\"Bitish\"sort initiated" << endl;

		start = chrono::system_clock::now();

		bitishSort(numbers);

		stop = chrono::system_clock::now();

		time = (stop - start);

		cout << endl << numbers.size() << " numbers sorted in " << (time.count() / 10000000) << " seconds.\n" << endl;

		break;
	default:
		break;
	}

}

void sortMenu(vector<int> &numbers)
{

	int sortMenuChoice;

	cout << "\nSort Menu:\n1. GPU\n2. CPU\n" << endl;

	cin >> sortMenuChoice;

	switch (sortMenuChoice)
	{
	case 1:

		gpuMenu(numbers);

		break;
	case 2:

		cpuMenu(numbers);

		break;
	default:
		break;
	}
}

void menu(int& menuChoice)
{
	//Menu choose between generate, sort, print and quit
	cout << "Menu:\n1. Generate\n2. Print\n3. Sort\n4. Check sort\n5. Scramble\n0. Quit\n" << endl;
	
	cin >> menuChoice;

	/*while (menuChoice > 4 || menuChoice < 1)
	{
		cout << "Invalid input. Try again." << endl;

		cin >> menuChoice;
	}*/

	return;
}