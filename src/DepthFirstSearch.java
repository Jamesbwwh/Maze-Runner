public class DepthFirstSearch {
	boolean solveMaze(int row, int col) {
		if (maze[row][col] == EMPTY) {
			// Add this cell to the path.
			maze[row][col] = PATH;
			putSquare(row, col, PATH);

			// Path has reached goal.
			if (row == rows - 2 && col == columns - 2)
				return true;

			// Try to solve maze by extending path in each
			// possible direction.
			if (solveMaze(row - 1, col) || solveMaze(row, col - 1)
					|| solveMaze(row + 1, col) || solveMaze(row, col + 1))
				return true;

			// Maze can't be solved from this cell,
			// so backtrack out of the cell.
			maze[row][col] = VISITED;
			putSquare(row, col, VISITED);
		}
		return false;
	}
}
