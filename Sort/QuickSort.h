#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

using namespace std;

class QuickSort
{
private:
	static int index;
	static vector<int> sortList;

	static void actualSort(vector<int> list);

public:
	static void Sort(vector<int>& list);
};

#endif