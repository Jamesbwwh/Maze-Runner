#include "stdafx.h"
#include "MazeGraphics.h"

const COLORREF MazeGraphics::color[] = { RGB(255, 255, 255), RGB(0, 0, 0), RGB(255, 255, 0), RGB(255, 0, 0), RGB(255, 192, 203), RGB(255, 165, 0) };

MazeGraphics::MazeGraphics() {
}

MazeGraphics::MazeGraphics(Maze *maze) {
	this->theMaze = maze;
}

void MazeGraphics::paint(HDC hdc) {
	HPEN thePen;
	for (int i = 0; i < (*theMaze).getRow(); i++) {
		for (int j = 0; j < (*theMaze).getCol(); j++) {
			switch ((*theMaze).getMaze(i, j)) {
			case Maze::WALL:
				thePen = CreatePen(PS_SOLID, 2, color[Maze::WALL]);
				break;
			case Maze::UNEXPLORED:
			case Maze::GLADER:
				thePen = CreatePen(PS_SOLID, 2, color[Maze::UNEXPLORED]);
				break;
			case Maze::VISITED:
				thePen = CreatePen(PS_SOLID, 2, color[Maze::VISITED]);
				break;
			case Maze::PATH:
			case Maze::GRIEVER:
				thePen = CreatePen(PS_SOLID, 2, color[Maze::PATH]);
				break;
			default:
				break;
			}
			SelectObject(hdc, thePen);
			Rectangle(hdc, j * cellWidth + left, i * cellHeight + top, cellWidth, cellHeight);
			switch ((*theMaze).getMaze(i, j)) {
			case Maze::GLADER:
				thePen = CreatePen(PS_SOLID, 2, color[Maze::GLADER]);
				break;
			case Maze::GRIEVER:
				thePen = CreatePen(PS_SOLID, 2, color[Maze::GRIEVER]);
				break;
			default:
				break;
			}
			SelectObject(hdc, thePen);
			Ellipse(hdc, j * cellWidth + left, i * cellHeight + top, cellWidth, cellHeight);
		}
	}
}

void MazeGraphics::canvasSize() {
	left = 0;
	top = 35;
	width = 300 - left;
	height = 300 - top;
	cellWidth = width / (*theMaze).getCol();
	cellHeight = height / (*theMaze).getRow();
}

void MazeGraphics::updateGraphics(MazeGraphics g) {
	//g.paintComponents(g.getGraphics());
	//g.update(g.getGraphics());
}
