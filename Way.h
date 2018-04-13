//Header untuk objek solving maze
//Metode yang diginakan adalah BFS(Breadth-first search) dan Backtracking
//Bentuk dari BFS yang digunakan dalam menacri kemungkinan jalan adalah queue
//Sedangkan bentuk dari Backtracking adalah bool untuk mencari apakah jaln tersebut benar

#ifndef WAY_H
#define WAY_H

#include <iostream>
#include <vector>
#include <queue>
#include "Maze.h"

using namespace std;

struct queueNode{			//Isi queue adalah struct
	Point pt;
	int dist;
};

class Way {
	queue <queueNode> m_step;
	vector <vector<bool> > m_visited;		//Berfungsi sebagai penanda apakah di titik itu sudah dicek atau belom
public:
	 Way(Maze &maze);						//Kita tidak memakain default constructor karena vector dan queue pasti null pointer

	bool isRight(Maze &maze, int row, int col);							//Fungsi untuk meninjau apakah koordinat memenuhi syarat
	int BFS(Maze &maze);													//Menghitung jalan tercepat
	void checkAdj(Maze &maze, int row, int col, queueNode front);			//Ngecek sekitar Cell

	bool backtracking(Maze &maze, int x, int y, int &a);					//Menandakan jalan yang tercepat				
	bool isSafe(Maze &maze, int x, int y);
	bool solveMaze(Maze &maze);
};

#endif