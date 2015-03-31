#include <iostream>
#include <sstream>
#include "Maze.h"

using namespace std;

Maze::Maze(string raw) {
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
			switch (rows[i][j])
			{
			case 'A':
				maze[i][j] = Maze::WALL;
				break;
			case '1':
			case 'B':
				maze[i][j] = Maze::UNEXPLORED;
				break;
			case 'C':
				maze[i][j] = Maze::VISITED;
				break;
			case 'D':
				maze[i][j] = Maze::PATH;
				break;
			case 'E':
				maze[i][j] = Maze::GLADER;
				break;
			case 'F':
				maze[i][j] = Maze::GRIEVER;
				break;
			default:
				break;
			}
		}
	}
}

Maze::Maze(int row, int col) {
	this->row = row;
	this->col = col;
	maze.resize(this->row);
	for (int i = 0; i < this->row; i++)
	{
		maze[i].resize(this->col);
		for (int j = 0; j < this->col; j++) maze[i][j] = Maze::WALL;
	}
}

int Maze::getRow() { return this->row; }

int Maze::getCol() { return this->col; }

int Maze::getMaze(int Row, int Column) {
	if (Row >= 0 && Column >= 0 && Row < row && Column < col) return this->maze[Row][Column];
	else return -1;
}

void Maze::setMaze(int Row, int Column, int value) { this->maze[Row][Column] = value; }

void Maze::printString() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) cout << maze[i][j];
		cout << endl;
	}
}

string Maze::returnString() {
	string returnStr = "";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			switch (maze[i][j])
			{
			case Maze::WALL:
				returnStr += 'A';
				break;
			case Maze::UNEXPLORED:
				returnStr += 'B';
				break;
			case Maze::VISITED:
				returnStr += 'C';
				break;
			case Maze::PATH:
				returnStr += 'D';
				break;
			case Maze::GLADER:
				returnStr += 'E';
				break;
			case Maze::GRIEVER:
				returnStr += 'F';
				break;
			default:
				break;
			}
		}
		returnStr += '\n';
	}
	return returnStr;
}
