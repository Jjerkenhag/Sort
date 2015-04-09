#include "Menu.h"
#include "List.h"
#include "Check.h"

int main()
{
	//User able to choose between generate, sort, print.
	int menuChoice = 1;

	List* numbers = new List();

	while (menuChoice != 0)
	{
		menu(menuChoice);

		switch (menuChoice)
		{
			//Generate list
		case 1:
			numbers->generate();
			break;
		case 2:
			numbers->print();
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

	delete numbers;
}