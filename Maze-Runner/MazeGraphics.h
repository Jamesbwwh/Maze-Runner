#include "stdafx.h"
#include "Maze.h"

#ifndef MAZEGRAPHICS_H
#define MAZEGRAPHICS_H

class MazeGraphics
{
private:
	int width, height, cellWidth, cellHeight, left, top;
	Maze *theMaze;
public:
	MazeGraphics(Maze*);
	MazeGraphics();
	static const COLORREF color[];
	void paint(HDC);
	void canvasSize();
	static void updateGraphics(MazeGraphics);
};
#endif
