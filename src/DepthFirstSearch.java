public class DepthFirstSearch implements Runnable {
	private MazeGraphics theGraphics;
	private Maze theMaze;
	private Glader theGlader;
	private Griever theGriever;

	public DepthFirstSearch(Maze maze, MazeGraphics mg) {
		theGraphics = mg;
		theMaze = maze;
		theGlader = new Glader(theMaze);
		theGriever = new Griever(theMaze);
	}

	public boolean solveMaze(int row, int col) {
		//System.out.println(theMaze.getMaze(row, col));
		switch (theMaze.getMaze(row, col)) {
		case Maze.GLADER:
			return true;
		case Maze.UNEXPLORED:
		case Maze.GRIEVER:
			theMaze.setMaze(row, col, Maze.PATH); // Cell Assignment
			theGraphics.paintComponents(theGraphics.getGraphics());
			theGraphics.update(theGraphics.getGraphics());
			try { Thread.sleep(50); } catch (Exception ex) { }

			// Try to solve maze by extending path in each possible direction.
			if (solveMaze(row - 1, col) || solveMaze(row, col - 1) || solveMaze(row + 1, col) || solveMaze(row, col + 1))
				return true;

			// Maze can't be solved from this cell, so backtrack out of the cell.
			theMaze.setMaze(row, col, Maze.VISITED); // Cell Assignment
			theGraphics.paintComponents(theGraphics.getGraphics());
			theGraphics.update(theGraphics.getGraphics());
			try { Thread.sleep(50); } catch (Exception ex) { }
		default:
			return false;
		}
	}

	public Griever getGriever() { return theGriever; }

	public void run() {
		solveMaze(theGriever.getRow(), theGriever.getCol());
	}
}
