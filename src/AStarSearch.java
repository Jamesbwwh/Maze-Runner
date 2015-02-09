public class AStarSearch implements Runnable {
	private MazeGraphics theGraphics;
	private Maze theMaze;
	private Glader theGlader;
	private Griever theGriever;
	private int[] unExplored;
	private int counter;

	public AStarSearch(Maze maze, MazeGraphics mg) {
		theGraphics = mg;
		theMaze = maze;
		theGlader = new Glader(theMaze);
		theGriever = new Griever(theMaze);
		unExplored = new int[theMaze.getRow()];
	}

	public void solveMaze(int row, int col) {
		int tmp = 0;
		int[] tmp2 = new int[8];
		// Check Top
		if (theMaze.getMaze(row - 1, col) != Maze.WALL) {
			tmp++;
			tmp2[0] = row - 1;
			tmp2[1] = col;
		}
		// Check Left
		if (theMaze.getMaze(row, col - 1) != Maze.WALL) {
			tmp++;
			tmp2[1] = theMaze.getMaze(row - 1, col);
		}
		// Check Bottom
		if (theMaze.getMaze(row + 1, col) != Maze.WALL) {
			tmp++;
			tmp2[2] = theMaze.getMaze(row - 1, col);
		}
		// Check Right
		if (theMaze.getMaze(row, col + 1) != Maze.WALL) {
			tmp++;
			tmp2[3] = theMaze.getMaze(row - 1, col);
		}
		switch (tmp) {
		case 1:
			for (int i = 0; i < 4; i++)
				if (tmp2[i] != 0)
					solveMaze();
			break;
		case 2:
		case 3:
		case 4:
			int distx = row - theGlader.getRow();
			int disty = col - theGlader.getCol();
			break;
		case 0:
			break;
		default:
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
