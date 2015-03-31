#include "MazeAlgorithm.h"

void MazeAlgorithm::HAK(Maze *maze) {
	srand(time(NULL));
	int row = rand() % maze->getRow();
	int col = rand() % maze->getCol();
	int rowOdd = row % 2;
	int colOdd = col % 2;
	pair<int, int> value = { row, col };
	pair<int, int> prev = value;
	while (true)
	{
		maze->setMaze(value.first, value.second, Maze::UNEXPLORED);

		if (prev != value)
		{
			if (abs(prev.first + prev.second - value.first - value.second) == 2)
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
			else
			{
				if (maze->getMaze(value.first, value.second - 2) == Maze::UNEXPLORED)
					maze->setMaze(value.first, value.second - 1, Maze::UNEXPLORED);

				else if (maze->getMaze(value.first - 2, value.second) == Maze::UNEXPLORED)
					maze->setMaze(value.first - 1, value.second, Maze::UNEXPLORED);

				else if (maze->getMaze(value.first, value.second + 2) == Maze::UNEXPLORED)
					maze->setMaze(value.first, value.second + 1, Maze::UNEXPLORED);

				else if (maze->getMaze(value.first + 2, value.second) == Maze::UNEXPLORED)
					maze->setMaze(value.first + 1, value.second, Maze::UNEXPLORED);
			}
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

		if (tmpVector.empty())
		{
			for (int i = rowOdd; i < maze->getRow(); i += 2)
			{
				for (int j = colOdd; j < maze->getCol(); j += 2)
				{
					if (maze->getMaze(i, j) == Maze::WALL)
					{
						if (maze->getMaze(i, j - 2) == Maze::UNEXPLORED)
							tmpVector.push_back({ i, j - 2 });

						if (maze->getMaze(i - 2, j) == Maze::UNEXPLORED)
							tmpVector.push_back({ i - 2, j });

						if (maze->getMaze(i, j + 2) == Maze::UNEXPLORED)
							tmpVector.push_back({ i, j + 2 });

						if (maze->getMaze(i + 2, j) == Maze::UNEXPLORED)
							tmpVector.push_back({ i + 2, j });

						if (!tmpVector.empty()) break;
					}
				}
				if (!tmpVector.empty()) break;
			}
			if (tmpVector.empty()) break;
		}
		prev = value;
		value = tmpVector[rand() % tmpVector.size()];
	}
}
