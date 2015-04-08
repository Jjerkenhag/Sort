#include "List.h"

void List::print()
{
	chrono::time_point<chrono::system_clock> start, stop;

	start = chrono::system_clock::now();

	cout << "\nStarting to print: " << endl;

	for (int i = 0; i < nrOfElements; i++)
	{
		cout << i + 1 << ". " << numbers[i] << endl;
	}

	stop = chrono::system_clock::now();

	chrono::duration<double, ratio<1, 10000000>> time = (stop - start);

	cout << endl << nrOfElements << " numbers printed in " << (time.count() / 10000000) << " seconds.\n" << endl;
}

void List::generate()
{
	if (nrOfElements > 0)
	{
		free(numbers);
	}
	cout << "\nSeed: ";
	cin >> seed;
	cout << "Number of elements: ";
	cin >> nrOfElements;
	cout << "Maximum: ";
	cin >> numberCap;
	cout << endl << "Creating " << nrOfElements << " element(s) from 1 to " << numberCap << " generated with seed " << seed << "." << endl;

	srand(seed);

	chrono::time_point<chrono::high_resolution_clock> start, stop;

	start = chrono::high_resolution_clock::now();

	numbers = (int*)malloc(sizeof(int) * (nrOfElements + 1));

	for (int i = 0; i < nrOfElements; i++)
	{
		numbers[i] = rand() % numberCap + 1;
	}

	stop = chrono::high_resolution_clock::now();

	chrono::duration<double, ratio<1, 10000000>> time = (stop - start);

	cout << "\nList generated in " << (time.count()/10000000) << " seconds.\n" << endl;
}

List::List()
{
	nrOfElements = 0;
	seed = 0;
	numberCap = 0;
}

List::~List()
{
	free(numbers);
}