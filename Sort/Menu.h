#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void menu(int& menuChoice);

void sortMenu(vector<int>& numbers);

void gpuMenu(vector<int>& numbers);

void cpuMenu(vector<int>& numbers);

void genMenu(vector<int>& numbers, int &seed, int &span);

#endif