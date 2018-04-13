// Header untuk objek Maze yaang akan diselesaikan
//Objek ini akan memasukan data baik dari input manual maupun file eksternal
//Bentuk dari Maze adalah vector

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Point {		//Membantu dalam menginerpretasikan lokasi data dalam vector 2d
	int x;
	int y;
};

class Maze{
	int m_col;			//Jumlah kolom yang dibuat
	int m_row;			//Jumlah baris yang dibuat
	Point start;		//Titik dimana maze akan mulai disolve
	Point finish;		// Titik dimana maze selesai
	vector <vector<int> > m_maze;	//Labirin dalam 1 dan 0)
public:
	Maze();								//Default contructor
	Maze(string file);					//Constructor

	void inputManual(); 		//Proses input manual

	vector <vector<int> > getMaze();				//Mendapatkan beberapa nilai member variable
	int getRow();
	int getCol();
	Point getStart();
	Point getFinish(); 

	void printMaze();

	void foutMaze(string file);

	friend class Way;				//Agar objek Way dapat mengakses private member objek MAze
};

#endif