#include "Scramble.h"

void breakfastScramble(vector<int> &numbers)
{
	int temp, swapPlace;

	for (int i = 0; i < (numbers.size()); i++)
	{
		swapPlace = (rand() % numbers.size());
		temp = numbers[i];
		numbers[i] = numbers[swapPlace];
		numbers[swapPlace] = temp;
	}

	cout << endl << numbers.size() << " scrambled eggs." << endl;
}