#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Way{
	int m_row;
	int m_col;
	stack <int> jalan;
public:

	Way();

	void setValue(int x; int y);
	void getValue(int x; int y);
	void addValue();
	void deleteValue();
	int size();

	~Way();
	
};