#include <iostream>
#include <fstream>
#include "Way.h"
#include "Maze.h"

using namespace std;

void inputfile() {													//Fungsi untuk input lewat file

	string filein;
	string fileout;

	cout << "Masukan nama file: ";
	cin >> filein;

	Maze maze(filein);

	cout << endl;

	maze.printMaze();
	cout << endl;

	cout << "Titik start adalah (" << maze.getStart().x << "," << maze.getStart().y << ")" << endl;
	cout << "Titik finish adalah (" << maze.getFinish().x << "," << maze.getFinish().y << ")" << endl;

	Way way(maze);

	int step = way.BFS(maze);

	if (step != -1) cout << "Langkah terpendek sebanyak " << step << endl;
	else cout << "Langkah terpendek tidak ada" << endl;

	cout << endl;

	way.solveMaze(maze);

	cout << "Masukan nama file output : ";
	cin >> fileout;

	maze.foutMaze(fileout);
}

void inputmanual() {																//Fungsi untuk input manual
	Maze maze;
	maze.inputManual();

	cout << "Titik start adalah (" << maze.getStart().x << "," << maze.getStart().y << ")" << endl;
	cout << "Titik finish adalah (" << maze.getFinish().x << "," << maze.getFinish().y << ")" << endl;

	Way way(maze);

	int step = way.BFS(maze);

	if (step != -1) cout << "Shortest Path is " << step << endl;
	else cout << "Shortest Path doesn't exist" << endl;

	cout << endl;

	way.solveMaze(maze);

	for(int i=0; i<maze.getRow(); i++)
	{
		for(int j=0; j<maze.getCol(); j++)
		{
			if (maze.getMaze()[i][j] == 0) cout<<"#";
			if (maze.getMaze()[i][j] == 2) cout << "!";
			if (maze.getMaze()[i][j] == 1 && i != maze.getStart().x) cout << "-";
			if (i == maze.getStart().x && j == maze.getStart().y) cout << "S";
			if (i == maze.getFinish().x && j== maze.getFinish().y) cout << "D"; 
		}
		cout << endl;
	}
}

int main() {

	int x;
	string filein;
	string fileout;

	cout << "Apakah anda mau input file atau manual" << endl;
	cout << "1 = input file     2 = input manual" << endl;

	cin >>x;

	if (x==1) inputfile();
	else if (x==2) inputmanual();
	else cout <<"error";

	return 0;
}