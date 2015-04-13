#ifndef MERGE_H
#define MERGE_H

#include <vector>

#include <iostream>

using namespace std;

class Merge
{
public:
	void Sort(vector<int> &list);
private:
	vector<int> *lists;
	int howManyLists, level;
};

#endif