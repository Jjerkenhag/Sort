#include "List.h"

void List::print()
{
	cout << "\nStarting to print: " << endl;

	for (int i = 0; i < nrOfElements; i++)
	{
		cout << i + 1 << ". " << numbers[i] << endl;
	}

	cout << endl << nrOfElements << " numbers printed.\n" << endl;
}

void List::generate()
{
	if (nrOfElements > 0)
	{
		free(numbers);
	}
	cout << "\nInput seed: ";
	cin >> seed;
	cout << "Number of elements: ";
	cin >> nrOfElements;
	cout << "Input span: ";
	cin >> numberCap;
	cout << "You will have " << nrOfElements << " element(s) from 1 to " << numberCap << " generated with seed " << seed << "." << endl;

	srand(seed);

	numbers = (int*)malloc(sizeof(int) * (nrOfElements + 1));

	for (int i = 0; i < nrOfElements; i++)
	{
		numbers[i] = rand() % numberCap + 1;
	}

	cout << "\nList generated.\n" << endl;
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