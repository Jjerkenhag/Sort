#include <vector>
#include <iostream>
#include "Ko.h"
#include "bitishSort.h"



void bitishSort(std::vector<int> &arr)
{
	int mod = 10;
	int divider = 1;
	Ko<int> *koList = new Ko<int>[10];
	bool sorting;

	do
	{
		sorting = false;
		for (int i = 0; i < arr.size(); i++) // magic ;)
		{
			koList[((arr[i] % mod) / divider)].add(arr[i]); // modelus räkning YAY!!! ._.
		}
		arr.clear();
		//int k = 0;
		for (int i = 0; i < 10; i++)
		{
			if (koList[i].getNrOfElements() > 0)
			{
				if (i > 0)
				{
					sorting = true;
				}
				for (int j = koList[i].getNrOfElements(); j > 0; j--)
				{
					arr.push_back(koList[i].pop());
					//std::cout << arr[k] << " ";
					//k++;
				}
			}
		}
		mod *= 10;
		divider *= 10;
	} while (sorting);
	delete[] koList;
}