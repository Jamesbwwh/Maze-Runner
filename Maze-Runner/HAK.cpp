#include "stdafx.h"
#include "HAK.h"

void HAK::generate(Maze maze) {
	srand(time(NULL));
	pair<int, int> value = { rand() % maze.getRow(), rand() % maze.getCol() };
	while (true)
	{
		maze.setMaze(value.first, value.second, Maze::UNEXPLORED);
		vector<pair<int, int>> tmpVector;
		if (maze.getMaze(value.first, value.second - 1) == Maze::WALL)
		{
			tmpVector.push_back({ value.first, value.second - 1 });
		}
		if (maze.getMaze(value.first - 1, value.second) == Maze::WALL)
		{
			tmpVector.push_back({ value.first - 1, value.second });
		}
		if (maze.getMaze(value.first, value.second + 1) == Maze::WALL)
		{
			tmpVector.push_back({ value.first, value.second + 1 });
		}
		if (maze.getMaze(value.first + 1, value.second) == Maze::WALL)
		{
			tmpVector.push_back({ value.first + 1, value.second });
		}
		if (tmpVector.empty())
		{
			for (int i = 0; i < maze.getRow(); i++)
			{
				for (int j = 0; j < maze.getCol(); j++)
				{
					if (maze.getMaze(i, j) == Maze::WALL)
					{
						if (maze.getMaze(value.first, value.second - 1) == Maze::WALL)
						{
							tmpVector.push_back({ value.first, value.second - 1 });
						}
						if (maze.getMaze(value.first - 1, value.second) == Maze::WALL)
						{
							tmpVector.push_back({ value.first - 1, value.second });
						}
						if (maze.getMaze(value.first, value.second + 1) == Maze::WALL)
						{
							tmpVector.push_back({ value.first, value.second + 1 });
						}
						if (maze.getMaze(value.first + 1, value.second) == Maze::WALL)
						{
							tmpVector.push_back({ value.first + 1, value.second });
						}
						if (!tmpVector.empty())
						{
							break;
						}
					}
				}
				if (!tmpVector.empty())
				{
					break;
				}
			}
			break;
		}
		value = tmpVector[rand() % (tmpVector.size() - 1)];
	}
}
