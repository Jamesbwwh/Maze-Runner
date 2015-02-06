public class DepthFirstSearch implements Runnable {
	private MazeGraphics theGraphics;
	private Maze theMaze;
	private Glader theGlader;
	private Griever theGriever;
	private int counter;

	public DepthFirstSearch(Maze maze, MazeGraphics mg) {
		theGraphics = mg;
		theMaze = maze;
		theGlader = new Glader(theMaze);
		theGriever = new Griever(theMaze);
	}

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

	public void run() {
		theMaze.setMaze(theGriever.getRow(), theGriever.getCol(), Maze.UNEXPLORED);
		if (solveMaze(theGriever.getRow(), theGriever.getCol()))
			System.out.println(counter);
	}
}
