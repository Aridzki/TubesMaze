#include <iostream>
#include "Way.h"

using namespace std;

Way::Way(Maze &maze) {						//Constructor ini berfungsi membuat vector 2d
											//yang ukurannya sama dengan maze dan diisi 0 pada setiap koordinat
	for(int i=0; i<maze.m_row; i++)
	{
		vector <bool> row;
		for(int j=0; j<maze.m_col; j++)
		{
			row.push_back(false);
		}
		m_visited.push_back(row);
	}
}

//Syaratnya adalah berada di dalam maze
bool Way::isRight( Maze &maze, int row, int col) {								
	return (row >= 0) && (row < maze.m_row) && (col>=0) && (col<maze.m_col);
}

int Way::BFS(Maze &maze) {
	
	m_visited[maze.start.x][maze.start.y] = true;						//Menandakan posiss start telah dibaca

	queueNode s = {maze.start, 0};										//Memasukan start ke dalam queue
	m_step.push(s);

	while(!m_step.empty())												//queue kosong ketika tidak ada jalan lagi (bukan buntu)
	{																	//yang artinya finish
		queueNode front = m_step.front();
		Point pt = front.pt;

		if (pt.x == maze.finish.x && pt.y == maze.finish.y)				//Ketika sampai finish banyak langkahnya akan direturn
			return front.dist;

		m_step.pop();													//Posisi yang sudah dicek pada tahap sebelumnya akan dikeluarkan

		checkAdj(maze, pt.x, pt.y, front);
	}

	return -1;
}

//Cell yang dicek adalah bawah, kiri, kanan, atas
void Way::checkAdj(Maze &maze, int x, int y, queueNode front) {
	int rowNum[] = {-1, 0, 0, 1};
	int colNum[] = {0, -1, 1, 0};

	for (int i=0; i<4; i++)
	{
		int row = x + rowNum[i];
		int col = y + colNum[i];

		if (isRight(maze, row, col) && maze.m_maze[row][col] && !m_visited[row][col])		//Syaratnya adalah di dalam maze, isi cell bukan 0, dan belum dikunjungi
		{
			m_visited[row][col] = true;
			queueNode Adjcell = {{row, col}, front.dist + 1};
			m_step.push(Adjcell);
		}
	}

}

bool Way::solveMaze(Maze &maze) {
	int a=0;			//Sebagai indikator dari jumlah langkah
	if (backtracking(maze,maze.getStart().x, maze.getStart().y, a)==false)			//Tercapi saat tidak ada solusi
	{
		cout << "Tidak ada solusi"<< endl;
		return false;
	}

	return true;
}

bool Way::backtracking(Maze &maze,int x, int y, int &a) {	
	
	if (x == maze.finish.x-1 && y == maze.finish.y-1)
	{
		 if (a==BFS(maze)) return true;									//Mengeluarkan hasnya solusi terpendek
	}

	if (isSafe(maze, x, y) == true || (x == maze.getStart().x && y==maze.getStart().y))
	{
		a++;															//Setiap kali maju akan menambah nilai a jika mundur akan dikurangi
		maze.m_maze[x][y]= 2;											//Setiap cell yang dilalui akan tetap 2 jika mundur lagi
		int rowNum[] = {-1, 0, 0, 1};									//akan menjadi 1
		int colNum[] = {0, -1, 1, 0};

		for (int i=0; i<4; i++)
		{
			int row = x + rowNum[i];
			int col = y + colNum[i];

			if (backtracking(maze, row, col, a)==true)					//Konsep utama backtracking
			{ 															//Jika salah akan kembali ke sebelumnya dang ngecek jalan lain
				return true;
			}
		}

		a--;
		maze.m_maze[x][y] = 1;
		return false;													//Jika disekitarnya gak ada jalan yang mungkin
	}

		return false;													//Jika sel tidak berisi 1
}

//Untuk ngecek apakah sel berada dalam maze dan berisi 1
bool Way::isSafe(Maze &maze, int x, int y) {
	if(x >= 0 && x < maze.m_row && y>=0 && y<maze.m_col && maze.m_maze[x][y]==1)
		return true;

	return false;
}