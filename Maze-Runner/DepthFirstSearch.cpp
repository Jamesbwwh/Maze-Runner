#include <iostream>

using namespace std;

class DepthFirstSearch {
	int row, col;
public:
	DepthFirstSearch(int, int);
	void Generate();
};

DepthFirstSearch::DepthFirstSearch(int rowSize, int colSize)
{
	row = rowSize;
	col = colSize;
}

void DepthFirstSearch::Generate()
{
}