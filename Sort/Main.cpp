#include "Menu.h"
#include "List.h"
#include "Check.h"
#include "Scramble.h"

int main()
{
	//User able to choose between generate, sort, print.
	int menuChoice = 1;

	int seed = 0;
	int span = 0;

	vector<int> numbers;

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
			sortMenu(numbers); //Get to choose sorting algorithm
			break;
		case 4:
			checkSort(numbers);
			break;
		case 5:
			breakfastScramble(numbers);
			break;
		case 0:
			cout << endl << "Shutting down." << endl;
			break;
		default:
			cout << "Error d4." << endl;
			break;
		}
	}
}