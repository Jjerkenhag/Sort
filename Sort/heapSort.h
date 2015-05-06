#ifndef BUILDHEAPS
#define BUILDHEAPS



template <typename Comparable>
void pullUp(Comparable arr[], int n, int d)
{
	if (n == 0)
	{
	}
	else if (arr[(n - 1) / d] < arr[n])
	{
		swap(arr[(n - 1) / d], arr[n]);
		pullUp(arr, (n - 1) / d, d);
	}
}


template <typename Comparable>
void buildHeapTopDown(Comparable arr[], int n, int d)
{
	for (int i = 1; i < n; i++)
	{
		pullUp(arr, i, d);
	}
}

template <typename Comparable>
void siftDown(Comparable arr[], int n, int d, int element)
{
	if (element >(n - 2) / d)
	{
	}
	else
	{
		int max = element*d + 1;
		for (int i = element*d + 2; i <= element*d + d && i < n; i++)
		{
			if (arr[max] < arr[i])
				max = i;
		}
		if (arr[max] > arr[element])
		{
			swap(arr[max], arr[element]);
			siftDown(arr, n, d, max);
		}
	}
}

template <typename Comparable>
void buildHeapBottomUp(Comparable arr[], int n, int d)
{
	for (int i = (n - 2) / d; i >= 0; i--)
	{
		siftDown(arr, n, d, i);
	}
}

template <typename Comparable>
void sortUsingTopDownConstructionOfHeap(Comparable arr[], int n, int d)
{
	buildHeapTopDown(arr, n, d);
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		siftDown(arr, i, d, 0);
	}
}

template <typename Comparable>
void sortUsingBottomUpConstructionOfHeap(Comparable arr[], int n, int d)
{
	buildHeapBottomUp(arr, n, d);
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		siftDown(arr, i, d, 0);
	}
}





#endif
