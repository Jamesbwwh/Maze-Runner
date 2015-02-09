import java.util.ArrayList;

public class AStarSearch implements Runnable {
	private MazeGraphics theGraphics;
	private Maze theMaze;
	private Glader theGlader;
	private Griever theGriever;
	private ArrayList<Coordinate> unExplored;
	private int counter;

	public AStarSearch(Maze maze, MazeGraphics mg) {
		theGraphics = mg;
		theMaze = maze;
		theGlader = new Glader(theMaze);
		theGriever = new Griever(theMaze);
		unExplored = new ArrayList<Coordinate>();
	}

	public boolean solveMaze(int row, int col) {
		if (theMaze.getMaze(row, col) == Maze.GLADER)
			return true;
		ArrayList<Coordinate> mazeSide = new ArrayList<Coordinate>();
		int sides = 0;
		counter++;
		// Check Top
		if (theMaze.getMaze(row - 1, col) != Maze.WALL) {
			mazeSide.add(new Coordinate(row - 1, col));
			sides++;
		}
		// Check Left
		if (theMaze.getMaze(row, col - 1) != Maze.WALL) {
			mazeSide.add(new Coordinate(row, col - 1));
			sides++;
		}
		// Check Bottom
		if (theMaze.getMaze(row + 1, col) != Maze.WALL) {
			mazeSide.add(new Coordinate(row + 1, col));
			sides++;
		}
		// Check Right
		if (theMaze.getMaze(row, col + 1) != Maze.WALL) {
			mazeSide.add(new Coordinate(row, col + 1));
			sides++;
		}
		switch (sides) {
		case 2:
			theMaze.setMaze(row, col, Maze.GRIEVER);
			MazeGraphics.updateGraphics(theGraphics);
			theMaze.setMaze(row, col, Maze.PATH);
			for (Coordinate route : mazeSide) {
				if (theMaze.getMaze(route.getRow(), route.getCol()) == Maze.UNEXPLORED)
					if (solveMaze(route.getRow(), route.getCol()))
						return true;
			}
			break;
		case 1:
			theMaze.setMaze(row, col, Maze.VISITED);
			MazeGraphics.updateGraphics(theGraphics);
			counter++;
			return false;
		case 3:
		case 4:
			unExplored.add(new Coordinate(row, col));
			theMaze.setMaze(row, col, Maze.VISITED);
			int x = theGlader.getRow() - row;
			int y = theGlader.getCol() - col;
			for (Coordinate fork : unExplored) {
				int tmpx = theGlader.getRow() - fork.getRow();
				int tmpy = theGlader.getCol() - fork.getCol();
				if (Math.abs(tmpx + tmpy) < Math.abs(x + y)) {
					x = tmpx;
					y = tmpy;
				}
			}
			if (solveMaze(x, y))
				return true;
			break;
		default:
			return false;
		}
		return false;
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
