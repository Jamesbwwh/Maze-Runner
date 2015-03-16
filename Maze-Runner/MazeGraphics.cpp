#include "MazeGraphics.h"
//#include "Maze.h"

using namespace MazeRunner;

//MazeGraphics::MazeGraphics(Maze maze) {
//	theMaze = &maze;
//}

void MazeGraphics::paint(Graphics^ g) {
	Pen^ thePen;
	for (int i = 0; i < (*theMaze).getRow(); i++) {
		for (int j = 0; j < (*theMaze).getCol(); j++) {
			switch ((*theMaze).getMaze(i, j)) {
			case Maze::WALL:
				thePen = gcnew Pen(*color[Maze::WALL]);
				break;
			case Maze::UNEXPLORED:
			case Maze::GLADER:
				thePen = gcnew Pen(*color[Maze::UNEXPLORED]);
				break;
			case Maze::VISITED:
				thePen = gcnew Pen(*color[Maze::VISITED]);
				break;
			case Maze::PATH:
			case Maze::GRIEVER:
				thePen = gcnew Pen(*color[Maze::PATH]);
				break;
			default:
				break;
			}
			g->DrawRectangle(thePen, j * cellWidth + left, i * cellHeight + top, cellWidth, cellHeight);
			switch ((*theMaze).getMaze(i, j)) {
			case Maze::GLADER:
				thePen = gcnew Pen(*color[Maze::GLADER]);
				break;
			case Maze::GRIEVER:
				thePen = gcnew Pen(*color[Maze::GRIEVER]);
				break;
			default:
				break;
			}
			g->DrawEllipse(thePen, j * cellWidth + left, i * cellHeight + top, cellWidth, cellHeight);
		}
	}
}

void MazeGraphics::canvasSize() {
	left = 0;
	top = 35;
	width = this->Size.Width - left;
	height = this->Size.Height - top;
	cellWidth = width / (*theMaze).getCol();
	cellHeight = height / (*theMaze).getRow();
}

void MazeGraphics::updateGraphics(MazeGraphics g) {
	//g.paintComponents(g.getGraphics());
	//g.update(g.getGraphics());
}
