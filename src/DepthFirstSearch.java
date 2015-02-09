public class DepthFirstSearch implements Runnable {
	private MazeGraphics theGraphics;
	private Maze theMaze;
	private Griever theGriever;
	private int counter;

	public DepthFirstSearch(Maze maze, MazeGraphics mg) {
		theGraphics = mg;
		theMaze = maze;
	}

	/* 
	 * description: This function is to solve the maze.
	 * case: 		If it is the target, return true.
	 * 				If it is not, move on the path until it find the target.
	 * 				
	 */

	public boolean solveMaze(int row, int col) {
		switch (theMaze.getMaze(row, col)) {
		case Maze.GLADER:
			return true;
		case Maze.UNEXPLORED:
			counter++;
			theMaze.setMaze(row, col, Maze.GRIEVER);
			MazeGraphics.updateGraphics(theGraphics);
			theMaze.setMaze(row, col, Maze.PATH);
			// Recursion
			if (solveMaze(row - 1, col) || solveMaze(row, col - 1) || solveMaze(row + 1, col) || solveMaze(row, col + 1))
				return true;
			// Backtrack
			theMaze.setMaze(row, col, Maze.VISITED);
			MazeGraphics.updateGraphics(theGraphics);
			counter++;
		default:
			return false;
		}
	}

	public Griever getGriever() { return theGriever; }
	public void setGriever(Griever griever) { theGriever = griever; }

	public void run() {
		theMaze.setMaze(theGriever.getRow(), theGriever.getCol(), Maze.UNEXPLORED);
		if (solveMaze(theGriever.getRow(), theGriever.getCol()))
			System.out.println(counter);
	}
}
