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

	int nrOfElements;

	int* numbers;
private:
	int numberCap;
	int seed;
};

#endif