#include "List.h"

void print(vector<int> &numbers)
{
	chrono::time_point<chrono::system_clock> start, stop;

	start = chrono::system_clock::now();

	cout << "\nStarting to print: " << endl;

	for (int i = 0; i < numbers.size(); i++)
	{
		cout << i + 1 << ". " << numbers[i] << endl;
	}

	stop = chrono::system_clock::now();

	chrono::duration<double, ratio<1, 10000000>> time = (stop - start);

	cout << endl << numbers.size() << " numbers printed in " << (time.count() / 10000000) << " seconds.\n" << endl;
}

void generate(vector<int> &numbers, int &seed, int &span)
{
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

	chrono::time_point<chrono::high_resolution_clock> start, stop;

	start = chrono::high_resolution_clock::now();

	numbers.reserve(nrOfElements);

	for (int i = 0; i < nrOfElements; i++)
	{
		numbers.push_back(rand() % span + 1);
	}

	stop = chrono::high_resolution_clock::now();

	chrono::duration<double, ratio<1, 10000000>> time = (stop - start);

	cout << "\nList generated in " << (time.count()/10000000) << " seconds.\n" << endl;
}