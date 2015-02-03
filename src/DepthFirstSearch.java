public class DepthFirstSearch {
	private Maze theMaze = null;
	private MazeGraphics theGraphics = null;

	public DepthFirstSearch() {
		
	}

	boolean solveMaze(int row, int col) {
		if (theMaze.getMaze(row, col) == Maze.UNEXPLORED) {
			theMaze.setMaze(row, col, Maze.PATH); // Cell Assignment
			theGraphics.putSquare(row, col, Maze.PATH); // Cell Graphics Change

			// Path has reached goal.
//			if (row == rows - 2 && col == columns - 2)
//				return true;

			// Try to solve maze by extending path in each possible direction.
			if (solveMaze(row - 1, col) || solveMaze(row, col - 1) || solveMaze(row + 1, col) || solveMaze(row, col + 1))
				return true;

			// Maze can't be solved from this cell, so backtrack out of the cell.
			theMaze.setMaze(row, col, Maze.VISITED); // Cell Assignment
			theGraphics.putSquare(row, col, Maze.VISITED); // Cell Graphics Change
		}
		return false;
	}
}
