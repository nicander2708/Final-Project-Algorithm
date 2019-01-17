#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include <cstddef>
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <climits>
#include <sstream>
#include <locale>
#include <cstdio>
using namespace std;
#define INFINITY INT_MAX

class GRAPH{
	
	private:
		
		string names [200];	// array of strings to hold station names

	public:
	
		GRAPH();
		void setStation(int, string);
		void findNameByID(int);
		void findNumberByName(char arr[]);
		void printAll();
		void initialize(char arr[]);						
};

#endif
