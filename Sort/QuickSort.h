#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

#include <iostream>

using namespace std;

class QuickSort
{
private:
	static int mIndex;
	static vector<int> sortList;
	static int* list1;
	static int* list2;
	static bool list1sTurn;
	static int size; 

	static void actualSort(vector<int> list);
	static void actualSort2(int startIndex, int endIndex);
	template<typename Comparable> 
	static void actualSort3(vector<Comparable> & a, int left, int right);
	template<typename Comparable> 
	static const Comparable & median3(vector<Comparable> & a, int left, int right);
	template<typename Comparable>
	static void insertionSort(vector<Comparable> & a, int left, int right);

public:
	template<typename Comparable> 
	static void Sort(vector<Comparable>& list);
};

int QuickSort::mIndex;
vector<int> QuickSort::sortList;
int* QuickSort::list1;
int* QuickSort::list2;
bool QuickSort::list1sTurn;
int QuickSort::size;

//Sorts the vector with quicksort
template<typename Comparable>
void QuickSort::Sort(vector<Comparable>& list)
{
	//Version 1
	//mIndex = 0;
	//sortList.resize(list.size());
	//sortList = list;
	//actualSort(sortList);
	//list = sortList;

	//Verion 2
	//size = list.size();
	//list1 = new int[list.size()];
	//list2 = new int[list.size()];
	//for (int i = 0; i < list.size(); i++)
	//{
	//	list1[i] = list[i];
	//	//list2[i] = list[i];
	//}
	//list1sTurn = true;
	//actualSort2(0, list.size() - 1);
	//for (int i = 0; i < list.size(); i++)
	//{
	//	if (list1sTurn)
	//		list[i] = list2[i];
	//	else
	//		list[i] = list1[i];
	//}
	//delete[] list1;
	//delete[] list2; 

	//Version 3
	actualSort3(list, 0, list.size() - 1);
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
		sortList.erase(sortList.begin() + mIndex);
		sortList.insert(sortList.begin() + mIndex, sub1[0]);
		mIndex++;
	}
	sortList.erase(sortList.begin() + mIndex);
	sortList.insert(sortList.begin() + mIndex, pivot);
	mIndex++;
	if (sub2.size() > 1)
		actualSort(sub2);
	else if (sub2.size() == 1)
	{
		sortList.erase(sortList.begin() + mIndex);
		sortList.insert(sortList.begin() + mIndex, sub2[0]);
		mIndex++;
	}
}

void QuickSort::actualSort2(int startIndex, int endIndex)
{
	int lesserListSize = 0;
	int biggerListSize = 0;
	int pivotIndex = (startIndex + endIndex) / 2;
	int pivot;
	int freeSpot = pivotIndex;
	if (list1sTurn)
	{
		pivot = list1[pivotIndex];
		for (int i = startIndex; i <= endIndex; i++)
		{
			int pos;
			if (i != pivotIndex)
			{
				if (list1[i] <= pivot)
				{
					pos = startIndex + lesserListSize;
					list2[pos] = list1[i];
					lesserListSize++;
					if (pos == freeSpot)
						freeSpot++;
				}
				else
				{
					pos = endIndex - biggerListSize;
					list2[pos] = list1[i];
					biggerListSize++;
					if (pos == freeSpot)
						freeSpot--;
				}
			}
		}
		list2[freeSpot] = pivot;
	}
	//else
	//{
	//	pivot = list2[pivotIndex];
	//	for (int i = startIndex; i <= endIndex; i++)
	//	{
	//		int pos;
	//		if (i != pivotIndex)
	//		{
	//			if (list2[i] <= pivot)
	//			{
	//				pos = startIndex + lesserListSize;
	//				list1[pos] = list2[i];
	//				lesserListSize++;
	//				if (pos == freeSpot)
	//					freeSpot++;
	//			}
	//			else
	//			{
	//				pos = endIndex - biggerListSize;
	//				list1[pos] = list2[i];
	//				biggerListSize++;
	//				if (pos == freeSpot)
	//					freeSpot--;
	//			}
	//		}
	//	}
	//	list1[freeSpot] = pivot;
	//}
	for (int i = 0; i < size; i++)
	{
		list1[i] = list2[i];
	}
	//list1sTurn = !list1sTurn; 
	if (lesserListSize > 1)
		actualSort2(startIndex, startIndex + lesserListSize - 1);
	if (biggerListSize > 1)
		actualSort2(endIndex - biggerListSize + 1, endIndex);
}

template<typename Comparable>
void QuickSort::actualSort3(vector<Comparable> & a, int left, int right)
{
	if (left + 10 <= right)
	{
		const Comparable & pivot = median3(a, left, right);
		int i = left, j = right - 1;
		for (;;)
		{
			while (a[++i] < pivot){}
			while (pivot < a[--j]){}
			if (i < j)
				std::swap(a[i], a[j]);
			else
				break;
		}
		std::swap(a[i], a[right - 1]);
		actualSort3(a, left, i - 1);
		actualSort3(a, i + 1, right);
	}
	else
		insertionSort(a, left, right);
}

template<typename Comparable>
const Comparable & QuickSort::median3(vector<Comparable>& a, int left, int right)
{
	int center = (left + right) / 2;

	if (a[center] < a[left])
		std::swap(a[left], a[center]);
	if (a[right] < a[left])
		std::swap(a[left], a[right]);
	if (a[right] < a[center])
		std::swap(a[center], a[right]);

	std::swap(a[center], a[right - 1]);
	return a[right - 1];
}

template<typename Comparable>
void QuickSort::insertionSort(vector<Comparable> & a, int left, int right)
{
	for (int p = left + 1; p < right + 1; p++)
	{
		Comparable tmp = std::move(a[p]);
		int j;
		for (j = p; j > 0 && tmp < a[j - 1]; j--)
		{
			a[j] = std::move(a[j - 1]);
		}
		a[j] = std::move(tmp);
	}
}

#endif
