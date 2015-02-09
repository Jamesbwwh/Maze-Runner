public class Maze {
	private int row, col;
	private int[][] maze;

	final static int WALL = 0;
	final static int UNEXPLORED = 1;
	final static int VISITED = 2;
	final static int PATH = 3;
	final static int GLADER = 4;
	final static int GRIEVER = 5;

	/*
	 * description: Used to set the path and the wall in the program.
	 */

	public Maze(String raw) {
		String[] rows = raw.split("\n");
		row = rows.length;
		col = rows[0].length();
		maze = new int[row][col];
		for (int i = 0; i < row; i++) {
			char[] columns = rows[i].toCharArray();
			for (int j = 0; j < col; j++) {
				if (columns[j] == '1')
					maze[i][j] = 1;
				else
					maze[i][j] = 0;
			}
		}
	}

	public int getRow() { return this.row; }
	public int getCol() { return this.col; }
	public int getMaze(int Row, int Column) {
		if (Row >= 0 && Column >= 0 && Row < row && Column < col) return this.maze[Row][Column];
		else return -1;
		}

	public void setMaze(int Row, int Column, int value) { this.maze[Row][Column] = value; }
	public void setMaze(Coordinate pos, int value) { this.maze[pos.getRow()][pos.getCol()] = value; }

	public void printString() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				System.out.print(maze[i][j]);
			}
			System.out.println();
		}
	}
}
