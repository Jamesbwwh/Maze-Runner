public class Glader {
	private Maze theMaze;
	private int row, col, speed = 3;

	public Glader(Maze maze) {
		theMaze = maze;
		do {
			row = (int)(Math.random() * 10);
			col = (int)(Math.random() * 10);
		} while (theMaze.getMaze(row, col) == Maze.WALL);
		theMaze.setMaze(row, col, Maze.GLADER);
	}

	public int getRow() { return row; }
	public int getCol() { return col; }
}
