public class DepthFirstSearch {
	private Maze theMaze = null;
	private Glader theGlader = null;

	public DepthFirstSearch() {
		
	}

	public boolean solveMaze(int row, int col) {
		if (theMaze.getMaze(row, col) == Maze.UNEXPLORED) {
			theMaze.setMaze(row, col, Maze.PATH); // Cell Assignment

			// Path has reached goal.
			if (row == theGlader.getRow() && col == theGlader.getCol())
				return true;

			// Try to solve maze by extending path in each possible direction.
			if (solveMaze(row - 1, col) || solveMaze(row, col - 1) || solveMaze(row + 1, col) || solveMaze(row, col + 1))
				return true;

			// Maze can't be solved from this cell, so backtrack out of the cell.
			theMaze.setMaze(row, col, Maze.VISITED); // Cell Assignment
		}
		return false;
	}
}
