#include "Check.h"

void checkSort(List* numbers)
{
	int sortChose;
	bool isSorted;

	cout << "\n1. Check big to small\n2. Check small to big" << endl;

	cin >> sortChose;

	switch (sortChose)
	{
	case 1:
		isSorted = bigToSmall(numbers);
		break;
	case 2:
		isSorted = smallToBig(numbers);
		break;
	default:
		cout << "\nSomething went wrong.\n" << endl;
		break;
	}

	if (isSorted)
	{
		cout << "\nThe numbers are sorted.\n" << endl;
	}
	else
	{
		cout << "\nThe numbers aren't sorted.\n" << endl;
	}
}

bool bigToSmall(List* numbers)
{
	int isSorted = 1;

	for (int i = 0; i < numbers->nrOfElements - 1; i++)
	{
		if (numbers->numbers[i] < numbers->numbers[i + 1]){
			isSorted = 0;
		}
	}

	return isSorted;
}

bool smallToBig(List* numbers)
{
	int isSorted = 1;

	for (int i = 0; i < numbers->nrOfElements - 1; i++)
	{
		if (numbers->numbers[i] > numbers->numbers[i + 1]){
			isSorted = 0;
		}
	}

	return isSorted;
}