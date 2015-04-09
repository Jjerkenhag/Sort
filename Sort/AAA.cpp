#include <iostream>
#include <thread>
#include <vector>
#include <chrono>


#include <windows.h>

using namespace std;

void sortThread(int x, int off, vector<int> *arr)
{
	this_thread::sleep_for(chrono::milliseconds(1000+ x+off));
	cout << x << " ";											//skriv da trmellanslag
	arr->push_back(x);
	 //return x;
}

int main()
{
	const int computerbadness = 6;
	vector<thread*> threads;	//da tråds
	vector<int> arr;
	srand(time(NULL));											
	cout << "dram swat mah trehds:" << endl;
	const int start = GetTickCount();

	for (int i = 0; i < 1000; i++)								// make da tråds
	{
		int r = rand() % 10000 + 1;
		int off = start - GetTickCount();
		cout << r << " ";
		thread* t = new thread(sortThread, r, off, &arr);					
		threads.push_back(t);
	}
	cout << endl << endl << "shit is waking: " << endl;

	for (vector<thread*>::iterator t = threads.begin(); t != threads.end(); t++)//
	{
		(*t)->join();
		delete (*t);
	}




	cout << "Accounting for the badnessss :"<< endl;
	for (int j = 0; j < computerbadness; j++)
	{
		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
			}
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	bool issort = true;
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i - 1] > arr[i])
		{
			issort = false;
		}
	}
	if (issort)
	{
		cout << endl << "niec" << endl;
	}
	else
	{
		cout << "bajs";
	}
	getchar();
	return 0;
}
