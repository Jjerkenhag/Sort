#include <iostream>
#include <thread>
#include <vector>
#include <chrono>


#include <windows.h>

using namespace std;

void sortThread(int x, int off, vector<int> *arr)
{
	this_thread::sleep_for(chrono::milliseconds(10000+x+off));
	cout << x << " ";											//skriv da trmellanslag
	arr->push_back(x);
}

void AAAsort(vector<int> &other, int computerbadness)
{
	vector<thread*> threads;	//da tråds										
	cout << endl << "dram swat mah trehds:" << endl;
	const int start = GetTickCount();
	vector<int> arr;

	for (int i = 0; i < other.size(); i++)								// make da tråds
	{
		int off = start - GetTickCount();
		thread* t = new thread(sortThread, other[i], off, &arr);					
		threads.push_back(t);
	}
	cout << endl << endl << "shit is waking: " << endl;

	for (vector<thread*>::iterator t = threads.begin(); t != threads.end(); t++)//
	{
		(*t)->join();
		delete (*t);
	}

	cout << "Accounting for the badnessss :"<< endl;
	int nrofswaps = 0;
	for (int j = 0; j < computerbadness; j++)
	{
		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
				nrofswaps++;
			}
		}
	}
	other = arr;
	cout << "corrections: " << nrofswaps;
}
