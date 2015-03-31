#include <time.h>
#include <stack>
#include "Maze.h"

using namespace std;

#ifndef MAZEALGORITHM_H
#define MAZEALGORITHM_H

class MazeAlgorithm {
public:
	static void DFS(Maze*);
	static void HAK(Maze*);
};
#endif
