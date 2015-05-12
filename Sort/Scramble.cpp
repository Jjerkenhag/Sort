#include "Scramble.h"

void breakfastScramble(vector<int> &numbers)
{
	chrono::time_point<chrono::system_clock> start, stop;
	chrono::duration<double, ratio<1, 10000000>> time;

	start = chrono::system_clock::now();

	int temp, swapPlace;

	for (int i = 0; i < (numbers.size()); i++)
	{
		swapPlace = (rand() % numbers.size());
		temp = numbers[i];
		numbers[i] = numbers[swapPlace];
		numbers[swapPlace] = temp;
	}

	stop = chrono::system_clock::now();

	time = (stop - start);

	cout << endl << numbers.size() << " scrambled eggs in " << (time.count() / 10000000) << " seconds.\n" << endl;
}