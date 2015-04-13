#ifndef SORTING_H
#define SORTING_H

#include <vector>

class Sorting
{
private:
	template<typename Comparable>
	static void insertionSort(vector<Comparable> & a);
	template<typename Comparable>
	static void insertionSort(vector<Comparable> & a, int left, int right);
	template<typename Comparable>
	static void quickSort(vector<Comparable> & a, int left, int right);
	template<typename Comparable>
	static const Comparable & median3(vector<Comparable> & a, int left, int right);

public:
	template<typename Comparable>
	static void InsertionSort(vector<Comparable>& list);
	template<typename Comparable>
	static void QuickSort(vector<Comparable>& list);
};

//Insertionsort driver
template<typename Comparable>
static void Sorting::InsertionSort(vector<Comparable>& list)
{
	insertionSort(list);
}

//Quicksort driver
template<typename Comparable>
static void Sorting::QuickSort(vector<Comparable>& list)
{
	quickSort(list, 0, list.size() - 1);
}

//insertionsort
template<typename Comparable>
void Sorting::insertionSort(vector<Comparable> & a)
{
	for (int p = 1; p < a.size(); p++)
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

//actual insertionsort special
template<typename Comparable>
void Sorting::insertionSort(vector<Comparable> & a, int leftIndex, int rightIndex)
{
	for (int p = leftIndex + 1; p < rightIndex + 1; p++)
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

//actual quicksort algorithm
template<typename Comparable>
static void Sorting::quickSort(vector<Comparable> & a, int left, int right)
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
		quickSort(a, left, i - 1);
		quickSort(a, i + 1, right);
	}
	else
		insertionSort(a, left, right);
}

//used by quicksort
template<typename Comparable>
const Comparable & Sorting::median3(vector<Comparable>& a, int left, int right)
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

#endif