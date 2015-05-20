#include "List.h"

void print(vector<int> &numbers)
{
	//double time;
	//StartCounter();
	cout << "\nStarting to print: " << endl;
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << i + 1 << ". " << numbers[i] << endl;
	}
	//time = GetCounter();
	cout << endl << numbers.size() << " numbers printed." << endl; // (time) << " seconds.\n" << endl;
}

void generate(vector<int> &numbers, int &seed, int &span)
{
	//double time;
	int nrOfElements;
	if (numbers.size() > 0)
	{
		numbers.clear();
	}
	cout << "\nSeed: ";
	cin >> seed;
	cout << "Number of elements: ";
	cin >> nrOfElements;
	cout << "Maximum: ";
	cin >> span;
	cout << endl << "Creating " << nrOfElements << " element(s) from 1 to " << span << " generated with seed " << seed << "." << endl;

	srand(seed);
	//StartCounter();
	for (int i = 0; i < nrOfElements; i++)
	{
		numbers.push_back(rand() % span + 1);
	}
	//time = GetCounter();
	cout << "\nList generated." << endl; //(time) << " seconds.\n" << endl;
}

void generateFixed(vector<int> &numbers)
{
	//double time;
	int upTo = 0;
	if (numbers.size() > 0)
	{
		numbers.clear();
	}
	cout << "Number of elements: ";
	cin >> upTo;
	cout << endl << "Creating " << upTo << " element(s) from 1 to " << upTo << "." << endl;
	//StartCounter();
	for (int i = 0; i < upTo; i++)
	{
		numbers.push_back(i + 1);
	}
	//time = GetCounter();
	cout << "\nList generated." << endl; // (time) << " seconds.\n" << endl;
}