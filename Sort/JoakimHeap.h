#ifndef JOAKIM_HEAP
#define JOAKIM_HEAP

#include <stdio.h>
#include <math.h>
#include <time.h>

using namespace std;

template <typename Comparable>
void jbuildHeapTopDown(Comparable arr[], int n, int d);

template <typename Comparable>
void jbuildHeapBottomUp(Comparable arr[], int n, int d);

template <typename Comparable>
Comparable removeFromHeap(Comparable heap[], int n, int d);

template <typename Comparable>
void jSortUsingTopDownConstructionOfHeap(Comparable arr[], int n, int d);

template <typename Comparable>
void jSortUsingBottomUpConstructionOfHeap(Comparable arr[], int n, int d);

template <typename Comparable>
void jbuildHeapTopDown(Comparable arr[], int n, int d){
	for (int i = 1; i < n; i++)
	{
		int current = i;
		int switchTo = (current - 1) / d;

		while (arr[current] > arr[switchTo])
		{
			int switchTemp = arr[switchTo];
			arr[switchTo] = arr[current];
			arr[current] = switchTemp;

			current = switchTo;
			switchTo = (current - 1) / d;
		}
	}
}

template <typename Comparable>
void jbuildHeapBottomUp(Comparable arr[], int n, int d){
	for (int z = (n - 2) / d; z >= 0; z--)
	{
		int biggestChild = 0;
		int parent = z;

		do
		{
			biggestChild = (parent * d) + 1;
			int firstChild = (parent * d) + 1;
			for (int i = 1; i < d; i++)
			{
				if (firstChild + i < n)
				{
					if (arr[biggestChild] < arr[firstChild + i]){
						biggestChild = firstChild + i;
					}
				}
			}

			if (arr[parent] < arr[biggestChild])
			{
				int switchTemp = arr[parent];
				arr[parent] = arr[biggestChild];
				arr[biggestChild] = switchTemp;
			}

			parent = biggestChild;

		} while (parent * d + 1 < n);
	}
}

template <typename Comparable>
Comparable jremoveFromHeap(Comparable heap[], int n, int d){
	int parent = 0;
	int firstChild = (parent * d) + 1;
	int biggestChild = firstChild;
	bool didSwap;

	Comparable temp = heap[0];

	heap[0] = heap[n - 1];

	do
	{
		didSwap = false;

		for (int i = 1; i < d; i++)
		{
			if (firstChild + i < n - 1)
			{
				if (heap[biggestChild] < heap[firstChild + i])
				{
					biggestChild = firstChild + i;
				}
			}
		}

		if (biggestChild < n - 1)
		{
			if (heap[parent] < heap[biggestChild])
			{
				Comparable switchTemp = heap[parent];
				heap[parent] = heap[biggestChild];
				heap[biggestChild] = switchTemp;

				parent = biggestChild;
				firstChild = (parent * d) + 1;
				biggestChild = firstChild;
				didSwap = true;
			}
		}
	} while (didSwap);

	return temp;
}

template <typename Comparable>
void jSortUsingTopDownConstructionOfHeap(Comparable arr[], int n, int d){
	jbuildHeapTopDown(arr, n, d);

	for (int i = n; i > 0; i--)
	{
		arr[i - 1] = jremoveFromHeap(arr, i, d);;
	}
}

template <typename Comparable>
void jSortUsingBottomUpConstructionOfHeap(Comparable arr[], int n, int d){
	jbuildHeapBottomUp(arr, n, d);

	for (int i = n; i > 0; i--)
	{
		arr[i - 1] = jremoveFromHeap(arr, i, d);
	}
}

#endif