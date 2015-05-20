#include <stdio.h>

#include "Menu.h"
#include "List.h"
#include "AAA.h"
#include "Sorting.h"
#include "bitishSort.h"
#include "heapSort.h"
#include "JoakimHeap.h"
#include "Timer.h"

void gpuMenu(vector<int> &numbers)
{
	double time;
	int gpuMenuChoice;
	cout << "\nGPU Menu:\n1. Dreamsort\n" << endl;
	cin >> gpuMenuChoice;	
	StartCounter();
	switch (gpuMenuChoice)
	{
	case 1:
		cout << "\nDreamsort initiated." << endl;
		AAAsort(numbers, 20);
		break;
	default:
		break;
	}
	time = GetCounter();
	cout << endl << numbers.size() << " numbers sorted in " << (time) << " seconds.\n" << endl;
}

void cpuMenu(vector<int> &numbers)
{
	double time;
	int cpuMenuChoice;
	cout << "\nCPU Menu:\n1. Quicksort\n2. \"Bitish\"sort\n3. Insertionsort\n4. Heapsort topdown\n5. Heapsort bottomup\n6. Joakim Heapsort BU\n" << endl;
	cin >> cpuMenuChoice;
	StartCounter();
	switch (cpuMenuChoice)
	{
	case 1:
		cout << "\nQuicksort initiated." << endl;
		Sorting::QuickSort(numbers);
		break;
	case 2:
		cout << "\n\"Bitish\"sort initiated" << endl;
		bitishSort(numbers);
		break;
	case 3:
		cout << "\nInsertionsort initiated." << endl;
		Sorting::InsertionSort(numbers);
		break;
	case 4:
		cout << "\n\Heapsort initiated" << endl;
		sortUsingTopDownConstructionOfHeap(&numbers[0], numbers.size(), 3);
		break;
	case 5:
		cout << "\n\Heapsort initiated" << endl;
		sortUsingBottomUpConstructionOfHeap(&numbers[0], numbers.size(), 3);
		break;
	case 6:
		cout << "\n\Heapsort initiated" << endl;
		jSortUsingBottomUpConstructionOfHeap(&numbers[0], numbers.size(), 3);
		break;
	default:
		break;
	}
	time = GetCounter();
	cout << endl << numbers.size() << " numbers sorted in " << (time) << " seconds.\n" << endl;
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

void genMenu(vector<int> &numbers, int &seed, int &span)
{
	int menuChoice = 0;

	cout << "Menu:\n1. Generate With Seed\n2. Generate Fixed\n" << endl;

	cin >> menuChoice;

	switch (menuChoice)
	{
	case 1:
		generate(numbers, seed, span);
		break;
	case 2:
		generateFixed(numbers);
	default:
		break;
	}
}