#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void print(vector<int> &numbers);

void generate(vector<int> &numbers, int &seed, int &span);

void generateFixed(vector<int> &numbers);

#endif