public class DepthFirstSearch {
	private Maze maze;
	//private int counter;

	public DepthFirstSearch(String maze) {
		this.maze = new Maze(maze);
	}

	public boolean solveMaze(int row, int col) {
		switch (maze.getMaze(row, col)) {
		case Maze.GLADER:
			return true;
		case Maze.UNEXPLORED:
			//counter++;
			maze.setMaze(row, col, Maze.PATH);
			// Recursion
			if (solveMaze(row - 1, col) || solveMaze(row, col - 1) || solveMaze(row + 1, col) || solveMaze(row, col + 1))
				return true;
			// Backtrack
			maze.setMaze(row, col, Maze.VISITED);
		default:
			return false;
		}
	}
	
	public String returnString() {
		return maze.returnString();
	}
}
