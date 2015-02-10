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
		unExplored = new ArrayList<Coordinate>();
	}

	public boolean solveMaze(int row, int col) {
		if (theMaze.getMaze(row, col) == Maze.GLADER)
			return true;
		int sides = 0;
		if (theMaze.getMaze(row - 1, col) != Maze.WALL)
			sides++;
		if (theMaze.getMaze(row, col - 1) != Maze.WALL)
			sides++;
		if (theMaze.getMaze(row + 1, col) != Maze.WALL)
			sides++;
		if (theMaze.getMaze(row, col + 1) != Maze.WALL)
			sides++;
		switch (sides) {
		case 2:
			theMaze.setMaze(row, col, Maze.GRIEVER);
			MazeGraphics.updateGraphics(theGraphics);
			theMaze.setMaze(row, col, Maze.PATH);
			if (theMaze.getMaze(row - 1, col) == Maze.UNEXPLORED) {
				if (solveMaze(row - 1, col))
					return true;
			}
			if (theMaze.getMaze(row, col - 1) == Maze.UNEXPLORED) {
				if (solveMaze(row, col - 1))
					return true;
			}
			if (theMaze.getMaze(row + 1, col) == Maze.UNEXPLORED) {
				if (solveMaze(row + 1, col))
					return true;
			}
			if (theMaze.getMaze(row, col + 1) == Maze.UNEXPLORED) {
				if (solveMaze(row, col + 1))
					return true;
			}
			break;
		case 1:
			theMaze.setMaze(row, col, Maze.VISITED);
			MazeGraphics.updateGraphics(theGraphics);
			return false;
		case 3:
		case 4:
			if (!unExplored.contains(new Coordinate(row, col)))
				unExplored.add(new Coordinate(row, col));
			Coordinate tryLoc = new Coordinate(row, col);
			for (Coordinate fork : unExplored) {
				sides = 0;
				if (theMaze.getMaze(fork.getRow() - 1, fork.getCol()) == Maze.UNEXPLORED)
					sides++;
				if (theMaze.getMaze(fork.getRow(), fork.getCol() - 1) == Maze.UNEXPLORED)
					sides++;
				if (theMaze.getMaze(fork.getRow() + 1, fork.getCol()) == Maze.UNEXPLORED)
					sides++;
				if (theMaze.getMaze(fork.getRow(), fork.getCol() + 1) == Maze.UNEXPLORED)
					sides++;
				if (sides > 0) {
					int tmpx = theGlader.getRow() - fork.getRow();
					int tmpy = theGlader.getCol() - fork.getCol();
					if (Math.abs(tmpx + tmpy) < Math.abs(theGlader.getRow() - tryLoc.getRow() + theGlader.getCol() - tryLoc.getCol()))
						tryLoc.setCoord(fork.getRow(), fork.getCol());
				}
			}
			int xDiff = theGlader.getRow() - tryLoc.getRow();
			int yDiff = theGlader.getCol() - tryLoc.getCol();
			boolean up = false, down = false, left = false, right = false;
			if (theMaze.getMaze(tryLoc.getRow() - 1, tryLoc.getCol()) == Maze.UNEXPLORED)
				up = true;
			if (theMaze.getMaze(tryLoc.getRow(), tryLoc.getCol() - 1) == Maze.UNEXPLORED)
				left = true;
			if (theMaze.getMaze(tryLoc.getRow() + 1, tryLoc.getCol()) == Maze.UNEXPLORED)
				down = true;
			if (theMaze.getMaze(tryLoc.getRow(), tryLoc.getCol() + 1) == Maze.UNEXPLORED)
				right = true;
			if (Math.abs(xDiff) < Math.abs(yDiff)) {
				if (right && xDiff > 0) {
					if (solveMaze(tryLoc.getRow(), tryLoc.getCol() + 1))
						return true;
				}
				if (left && xDiff < 0) {
					if (solveMaze(tryLoc.getRow(), tryLoc.getCol() - 1))
						return true;
				}
				if (up && yDiff > 0) {
					if (solveMaze(tryLoc.getRow() + 1, tryLoc.getCol()))
						return true;
				}
				if (down && yDiff < 0) {
					if (solveMaze(tryLoc.getRow() - 1, tryLoc.getCol()))
						return true;
				}
			}
			else {
				if (up && yDiff > 0) {
					if (solveMaze(tryLoc.getRow() + 1, tryLoc.getCol()))
						return true;
				}
				if (down && yDiff < 0) {
					if (solveMaze(tryLoc.getRow() - 1, tryLoc.getCol()))
						return true;
				}
				if (right && xDiff > 0) {
					if (solveMaze(tryLoc.getRow(), tryLoc.getCol() + 1))
						return true;
				}
				if (left && xDiff < 0) {
					if (solveMaze(tryLoc.getRow(), tryLoc.getCol() - 1))
						return true;
				}
			}
			for (Coordinate fork : unExplored) {
				sides = 0;
				if (theMaze.getMaze(fork.getRow() - 1, fork.getCol()) == Maze.UNEXPLORED)
					sides++;
				if (theMaze.getMaze(fork.getRow(), fork.getCol() - 1) == Maze.UNEXPLORED)
					sides++;
				if (theMaze.getMaze(fork.getRow() + 1, fork.getCol()) == Maze.UNEXPLORED)
					sides++;
				if (theMaze.getMaze(fork.getRow(), fork.getCol() + 1) == Maze.UNEXPLORED)
					sides++;
				if (sides > 0) {
					if (solveMaze(fork.getRow(), fork.getCol()))
						return true;
				}
			}
			break;
		default:
			return false;
		}
		return false;
	}

	public Griever getGriever() { return theGriever; }
	public void setGriever(Griever griever) { theGriever = griever; }
	public Glader getGlader() { return theGlader; }
	public void setGlader(Glader glader) { theGlader = glader; }

	public void run() {
		System.out.println(solveMaze(theGriever.getRow(), theGriever.getCol()));
		System.out.println(counter);
	}
}
