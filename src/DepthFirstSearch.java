public class DepthFirstSearch {
	private MazeGraphics theGraphics;
	private Maze theMaze;
	private Glader theGlader;
	private Griever theGriever;

	public DepthFirstSearch(Maze maze, MazeGraphics mg) {
		theGraphics = mg;
		theMaze = maze;
		theGlader = new Glader(theMaze);
		theGriever = new Griever(theMaze);
		theGraphics.repaint();
	}

	public boolean solveMaze(int row, int col) {
		//System.out.println(theMaze.getMaze(row, col));
		if (theMaze.getMaze(row, col) == Maze.UNEXPLORED) {
			theMaze.setMaze(row, col, Maze.PATH); // Cell Assignment
			//try { Thread.sleep(200); } catch (Exception ex) { }
			theGraphics.repaint();

			// Path has reached goal.
			if (row == theGlader.getRow() && col == theGlader.getCol())
				return true;

			// Try to solve maze by extending path in each possible direction.
			if (solveMaze(row - 1, col) || solveMaze(row, col - 1) || solveMaze(row + 1, col) || solveMaze(row, col + 1))
				return true;

			// Maze can't be solved from this cell, so backtrack out of the cell.
			theMaze.setMaze(row, col, Maze.VISITED); // Cell Assignment
			//try { Thread.sleep(200); } catch (Exception ex) { }
			theGraphics.repaint();
		}
		return false;
	}

	public Griever getGriever() { return theGriever; }
}
