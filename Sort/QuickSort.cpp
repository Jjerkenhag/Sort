#include "QuickSort.h"

int QuickSort::index;
vector<int> QuickSort::sortList;

//Sorts the vector with quicksort
void QuickSort::Sort(vector<int>& list)
{
	index = 0;
	sortList.resize(list.size());
	sortList = list;
	actualSort(sortList);
	list = sortList;
} 

void QuickSort::actualSort(vector<int> list)
{
	vector<int> sub1;
	vector<int> sub2;
	int pivot = list[0];
	for (int i = 1; i < list.size(); i++)
	{
		if (list[i] <= pivot)
			sub1.push_back(list[i]);
		else
			sub2.push_back(list[i]);
	}
	if (sub1.size() > 1)
		actualSort(sub1);
	else if (sub1.size() == 1)
	{
		sortList.erase(sortList.begin() + index);
		sortList.insert(sortList.begin() + index, sub1[0]);
		index++;
	}
	sortList.erase(sortList.begin() + index);
	sortList.insert(sortList.begin() + index, pivot);
	index++;
	if (sub2.size() > 1)
		actualSort(sub2);
	else if (sub2.size() == 1)
	{
		sortList.erase(sortList.begin() + index);
		sortList.insert(sortList.begin() + index, sub2[0]);
		index++;
	}
}