#include "stdafx.h"
#include "Maze.h"

Maze::Maze()
{
}

Maze::Maze(int row, int col)
{
	this->row = row;
	this->col = col;
	maze.resize(this->row);
	for (int i = 0; i < this->row; i++)
	{
		maze[i].resize(this->col);
		for (int j = 0; j < this->col; j++)
		{
			maze[i][j] = Maze::WALL;
		}
	}
}

Maze::Maze(string raw)
{
	vector<string> rows;
	istringstream raws(raw);
	string tmp;
	while (!raws.eof())
	{
		getline(raws, tmp, '\n');
		rows.push_back(tmp);
	}
	row = rows.size() - 1;
	col = rows[0].size() - 1;
	maze.resize(row);
	for (int i = 0; i < row; i++) {
		maze[i].resize(col);
		for (int j = 0; j < col; j++) {
			if (rows[i][j] == '1')
				maze[i][j] = 1;
			else
				maze[i][j] = 0;
		}
	}
}

int Maze::getRow() { return this->row; }

int Maze::getCol() { return this->col; }

int Maze::getMaze(int Row, int Column) {
	if (Row >= 0 && Column >= 0 && Row < row && Column < col) return this->maze[Row][Column];
	else return -1;
}

void Maze::setMaze(int Row, int Column, int value) { this->maze[Row][Column] = value; }

void Maze::printString()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
}
