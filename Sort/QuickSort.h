#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

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

public:
	static void Sort(vector<int>& list);
};

#endif
