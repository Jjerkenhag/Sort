#include "Menu.h"
#include "List.h"

int main()
{
	//User able to choose between generate, sort, print.
	int menuChoice = 0;

	List* numbers = new List();

	while (menuChoice != 4)
	{
		menu(menuChoice);

		switch (menuChoice)
		{
			//Generate list
		case 1:
			numbers->generate();
			break;
		case 2:
			break;
		case 3:
			numbers->print();
			break;
		case 4:
			cout << "Shutting down." << endl;
			break;
		default:
			cout << "Error d4." << endl;
			break;
		}
	}

	delete numbers;
}