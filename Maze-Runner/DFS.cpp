#include "MazeAlgorithm.h"

void MazeAlgorithm::DFS(Maze *maze) {
	srand(time(NULL));
	stack<pair<int, int>> theStack;
	theStack.push({ rand() % maze->getRow(), rand() % maze->getCol() });
	pair<int, int> prev = theStack.top();
	while (!theStack.empty())
	{
		pair<int, int> value = theStack.top();
		theStack.pop();
		maze->setMaze(value.first, value.second, Maze::UNEXPLORED);

		if (prev != value)
		{
			if (prev.first < value.first)
				maze->setMaze(prev.first + 1, prev.second, Maze::UNEXPLORED);

			else if (prev.first > value.first)
				maze->setMaze(prev.first - 1, prev.second, Maze::UNEXPLORED);

			else if (prev.second < value.second)
				maze->setMaze(prev.first, prev.second + 1, Maze::UNEXPLORED);

			else if (prev.second > value.second)
				maze->setMaze(prev.first, prev.second - 1, Maze::UNEXPLORED);
		}

		vector<pair<int, int>> tmpVector;

		if (maze->getMaze(value.first, value.second - 2) == Maze::WALL)
			tmpVector.push_back({ value.first, value.second - 2 });

		if (maze->getMaze(value.first - 2, value.second) == Maze::WALL)
			tmpVector.push_back({ value.first - 2, value.second });

		if (maze->getMaze(value.first, value.second + 2) == Maze::WALL)
			tmpVector.push_back({ value.first, value.second + 2 });

		if (maze->getMaze(value.first + 2, value.second) == Maze::WALL)
			tmpVector.push_back({ value.first + 2, value.second });

		while (!tmpVector.empty())
		{
			int random = rand() % tmpVector.size();
			theStack.push(tmpVector[random]);
			tmpVector.erase(tmpVector.begin() + random);
		}
		prev = value;
	}
}
