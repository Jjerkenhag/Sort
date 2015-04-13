//#include <iostream>

//int QuickSort::mIndex;
//vector<int> QuickSort::sortList;
//int* QuickSort::list1;
//int* QuickSort::list2;
//bool QuickSort::list1sTurn;
//int QuickSort::size;

//Sorts the vector with quicksort
//template<typename Comparable>
//void QuickSort::Sort(vector<int>& list)
//{
//	//Version 1
//	//mIndex = 0;
//	//sortList.resize(list.size());
//	//sortList = list;
//	//actualSort(sortList);
//	//list = sortList;
//
//	//Verion 2
//	//size = list.size();
//	//list1 = new int[list.size()];
//	//list2 = new int[list.size()];
//	//for (int i = 0; i < list.size(); i++)
//	//{
//	//	list1[i] = list[i];
//	//	//list2[i] = list[i];
//	//}
//	//list1sTurn = true;
//	//actualSort2(0, list.size() - 1);
//	//for (int i = 0; i < list.size(); i++)
//	//{
//	//	if (list1sTurn)
//	//		list[i] = list2[i];
//	//	else
//	//		list[i] = list1[i];
//	//}
//	//delete[] list1;
//	//delete[] list2; 
//
//	//Version 3
//
//}
//
//template<typename Comparable>
//void QuickSort::actualSort(vector<int> list)
//{
//	vector<int> sub1;
//	vector<int> sub2;
//	int pivot = list[0];
//	for (int i = 1; i < list.size(); i++)
//	{
//		if (list[i] <= pivot)
//			sub1.push_back(list[i]);
//		else
//			sub2.push_back(list[i]);
//	}
//	if (sub1.size() > 1)
//		actualSort(sub1);
//	else if (sub1.size() == 1)
//	{
//		sortList.erase(sortList.begin() + mIndex);
//		sortList.insert(sortList.begin() + mIndex, sub1[0]);
//		mIndex++;
//	}
//	sortList.erase(sortList.begin() + mIndex);
//	sortList.insert(sortList.begin() + mIndex, pivot);
//	mIndex++;
//	if (sub2.size() > 1)
//		actualSort(sub2);
//	else if (sub2.size() == 1)
//	{
//		sortList.erase(sortList.begin() + mIndex);
//		sortList.insert(sortList.begin() + mIndex, sub2[0]);
//		mIndex++;
//	}
//}
//
//template<typename Comparable>
//void QuickSort::actualSort2(int startIndex, int endIndex)
//{
//	int lesserListSize = 0;
//	int biggerListSize = 0;
//	int pivotIndex = (startIndex + endIndex) / 2;
//	int pivot;
//	int freeSpot = pivotIndex;
//	if (list1sTurn)
//	{
//		pivot = list1[pivotIndex];
//		for (int i = startIndex; i <= endIndex; i++)
//		{
//			int pos;
//			if (i != pivotIndex)
//			{
//				if (list1[i] <= pivot)
//				{
//					pos = startIndex + lesserListSize;
//					list2[pos] = list1[i];
//					lesserListSize++;
//					if (pos == freeSpot)
//						freeSpot++;
//				}
//				else
//				{
//					pos = endIndex - biggerListSize;
//					list2[pos] = list1[i];
//					biggerListSize++;
//					if (pos == freeSpot)
//						freeSpot--;
//				}
//			}
//		}
//		list2[freeSpot] = pivot;
//	}
//	//else
//	//{
//	//	pivot = list2[pivotIndex];
//	//	for (int i = startIndex; i <= endIndex; i++)
//	//	{
//	//		int pos;
//	//		if (i != pivotIndex)
//	//		{
//	//			if (list2[i] <= pivot)
//	//			{
//	//				pos = startIndex + lesserListSize;
//	//				list1[pos] = list2[i];
//	//				lesserListSize++;
//	//				if (pos == freeSpot)
//	//					freeSpot++;
//	//			}
//	//			else
//	//			{
//	//				pos = endIndex - biggerListSize;
//	//				list1[pos] = list2[i];
//	//				biggerListSize++;
//	//				if (pos == freeSpot)
//	//					freeSpot--;
//	//			}
//	//		}
//	//	}
//	//	list1[freeSpot] = pivot;
//	//}
//	for (int i = 0; i < size; i++)
//	{
//		list1[i] = list2[i];
//	}
//	//list1sTurn = !list1sTurn;
//	if (lesserListSize > 1)
//		actualSort2(startIndex, startIndex + lesserListSize - 1);
//	if (biggerListSize > 1)
//		actualSort2(endIndex - biggerListSize + 1, endIndex);
//}
//
//template<typename Comparable>
//void QuickSort::actualSort3(int* list, int left, int right)
//{
//	
//}
