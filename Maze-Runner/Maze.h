#include <vector>
#include <string>

using namespace std;

#ifndef MAZE_H
#define MAZE_H

class Maze {
private:
	int row, col;
	vector<vector<int>> maze;
public:
	static const int WALL = 0;
	static const int UNEXPLORED = 1;
	static const int VISITED = 2;
	static const int PATH = 3;
	static const int GLADER = 4;
	static const int GRIEVER = 5;

	Maze(string);
	int getRow();
	int getCol();
	int getMaze(int, int);
	void setMaze(int, int, int);
	void printString();
};
#endif
