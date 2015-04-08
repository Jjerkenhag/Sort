#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

class List
{
public:
	void print();

	void generate();

	List();
	~List();

private:
	int nrOfElements;
	int numberCap;
	int seed;

	int* numbers;
};

#endif