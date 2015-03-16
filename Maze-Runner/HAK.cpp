#include "stdafx.h"
#include "HAK.h"

void HAK::generate(Maze maze) {
	srand(time(NULL));
	stack<pair<int, int>> theStack;
	theStack.push({ rand() % maze.getRow(), rand() % maze.getCol() });
	while (!theStack.empty())
	{
		pair<int, int> value = theStack.top();
		theStack.pop();
		maze.setMaze(value.first, value.second, Maze::UNEXPLORED);
		vector<pair<int, int>> tmpVector;
		if (maze.getMaze[value.first][value.second - 1] == Maze::WALL)
		{
			tmpVector.push_back({ value.first, value.second - 1 });
		}
		if (maze.getMaze[value.first - 1][value.second] == Maze::WALL)
		{
			tmpVector.push_back({ value.first - 1, value.second });
		}
		if (maze.getMaze[value.first][value.second + 1] == Maze::WALL)
		{
			tmpVector.push_back({ value.first, value.second + 1 });
		}
		if (maze.getMaze[value.first + 1][value.second] == Maze::WALL)
		{
			tmpVector.push_back({ value.first + 1, value.second });
		}
		while (!tmpVector.empty())
		{
			int random = rand() % tmpVector.size();
			theStack.push(tmpVector[random]);
			tmpVector.erase(tmpVector.begin() + random);
		}
	}
}
