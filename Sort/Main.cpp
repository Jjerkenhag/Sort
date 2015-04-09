#include "Menu.h"
#include "List.h"
#include "Check.h"

#include <vector>
#include <iostream>

int main()
{
	//User able to choose between generate, sort, print.
	int menuChoice = 1;

	vector<int> numbers;
	int seed, span;

	while (menuChoice != 0)
	{
		menu(menuChoice);

		switch (menuChoice)
		{
			//Generate list
		case 1:
			generate(numbers, seed, span);
			break;
		case 2:
			print(numbers);
			break;
		case 3:
			sortMenu();
			break;
		case 4:
			checkSort(numbers);
			break;
		case 0:
			cout << "Shutting down." << endl;
			break;
		default:
			cout << "Error d4." << endl;
			break;
		}
	}

	numbers.clear();
}