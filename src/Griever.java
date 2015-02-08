/*
 * description: the starting point of the maze. The agent.
 */

public class Griever {
	private Maze theMaze;
	private int row, col, speed = 5;

	public Griever(Maze maze) {
		theMaze = maze;
		do {
			row = (int)(Math.random() * maze.getRow());
			col = (int)(Math.random() * maze.getCol());
		} while (theMaze.getMaze(row, col) == Maze.WALL);
		theMaze.setMaze(row, col, Maze.GRIEVER);
	}

	public int getRow() { return row; }
	public int getCol() { return col; }
}
