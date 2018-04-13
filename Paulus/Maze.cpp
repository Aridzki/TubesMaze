#include "Maze.h"
#include <iostream>
#include <fstream>

using namespace std;

//Default constructor
Maze::Maze(){					//Defaul constructor berisi m_maze yang kosong
	m_row = 0;
	m_col = 0;
}

Maze::Maze(string file) {			//Constructor saat proses input file
	char x;
	ifstream fin;					

	fin.open(file);					//Membuka input file
	
	fin >> m_col; 					//Data pertama pada input file berupa angka
	fin >> m_row;					//yang akan menjadi kolomxbaris

	for(int i=0; i<m_row; i++)							//Proses membuat vector 2d m_maze
	{
		vector <int> row;

		for(int j=0; j<m_col; j++)
		{
			fin >> x;

			if (x=='#') row.push_back(0);
			else if (x=='-') row.push_back(1);
			else if (x=='S') {
				row.push_back(1);
				start.x = i;
				start.y = j;
			}
			else if (x=='D') {
				row.push_back(1);
				finish.x = i;
				finish.y = j;
			}
		}
		m_maze.push_back(row);
	}

	fin.close();
}	

void Maze::inputManual() {

	cout << "Input jumlah baris = ";
	cin >> m_row;
	cout << "Input jumlah kolom = ";
	cin >> m_col;

	char x;

	cout << "Input maze" << endl;
	for(int i = 0; i<m_row; i++)
	{
		vector <int> row;
		for(int j = 0; j<m_col; j++)
		{
			cin >> x;
			if (x=='#') row.push_back(0);
			else if (x=='-') row.push_back(1);
			else if (x=='S') {
				row.push_back(-1);
				start.x = i;
				start.y = j;
			}
			else if (x=='D') {
				row.push_back(-2);
				finish.x = i;
				finish.y = j;
			}
		}
		m_maze.push_back(row);
	}
}

vector <vector<int> > Maze::getMaze() {
	return m_maze;
}

int Maze::getRow() {
	return m_row;
}

int Maze::getCol() {
	return m_col;
}

Point Maze::getStart() {
	return start;
}

Point Maze::getFinish() {
	return finish;
}

void Maze::printMaze() {
	for(int i=0; i<m_row; i++)
	{
		for(int j=0; j<m_col; j++)
		{
			cout << m_maze[i][j];
		}

		cout << endl;
	}
}

void Maze::foutMaze(string file) {					//Proses membuat file output
	ofstream fout;

	fout.open(file);

	for(int i=0; i<m_row; i++)
	{
		for(int j=0; j<m_col; j++)
		{
			if (m_maze[i][j] == 0) fout<<"#";
			if (m_maze[i][j] == 2) fout << "!";
			if (m_maze[i][j] == 1 && i != start.x) fout << "-";
			if (i == start.x && j == start.y) fout << "S";
			if (i == finish.x && j== finish.y) fout << "D"; 
		}
		fout << endl;
	}
	fout.close();
}
