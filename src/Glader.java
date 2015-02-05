public class Glader {
	private Maze theMaze;
	private int row, col, speed = 3;

	public Glader(Maze maze) {
		theMaze = maze;
		do {
			row = (int)(Math.random() * maze.getRow());
			col = (int)(Math.random() * maze.getCol());
		} while (theMaze.getMaze(row, col) == Maze.WALL);
		theMaze.setMaze(row, col, Maze.GLADER);
	}

	public int getRow() { return row; }
	public int getCol() { return col; }
}
