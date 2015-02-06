public class AStarSearch implements Runnable {
	private MazeGraphics theGraphics;
	private Maze theMaze;
	private Glader theGlader;
	private Griever theGriever;
	private int counter;

	public AStarSearch(Maze maze, MazeGraphics mg) {
		theGraphics = mg;
		theMaze = maze;
		theGlader = new Glader(theMaze);
		theGriever = new Griever(theMaze);
	}

	public void solveMaze(int row, int col) {
		int tmp = 0;
		// Check Top
		if (theMaze.getMaze(row - 1, col) != Maze.WALL)
			tmp++;
		// Check Left
		if (theMaze.getMaze(row, col - 1) != Maze.WALL)
			tmp++;
		// Check Bottom
		if (theMaze.getMaze(row + 1, col) != Maze.WALL)
			tmp++;
		// Check Right
		if (theMaze.getMaze(row, col + 1) != Maze.WALL)
			tmp++;
		if (tmp > 1) {
			int distx = row - theGlader.getRow();
			int disty = col - theGlader.getCol();
		}
//		switch (theMaze.getMaze(row, col)) {
//		case Maze.GLADER:
//			return true;
//		case Maze.UNEXPLORED:
//			counter++;
//			theMaze.setMaze(row, col, Maze.GRIEVER);
//			MazeGraphics.updateGraphics(theGraphics);
//			theMaze.setMaze(row, col, Maze.PATH);
//			// Recursion
//			if (solveMaze(row - 1, col) || solveMaze(row, col - 1) || solveMaze(row + 1, col) || solveMaze(row, col + 1))
//				return true;
//			// Backtrack
//			theMaze.setMaze(row, col, Maze.VISITED);
//			MazeGraphics.updateGraphics(theGraphics);
//			counter++;
//		default:
//			return false;
//		}
	}

	public Griever getGriever() { return theGriever; }

	public void run() {
		solveMaze(theGriever.getRow(), theGriever.getCol());
	}
}
