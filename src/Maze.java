public class Maze {
	private int row, col;
	private int[][] maze;

	final static int WALL = 0;
	final static int UNEXPLORED = 1;
	final static int VISITED = 2;
	final static int PATH = 3;

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
	public int getMaze(int i, int j) { return this.maze[i][j]; }

	public void setMaze(int i, int j, int value) { this.maze[i][j] = value; }

	public void printString() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				System.out.print(maze[i][j]);
			}
			System.out.println();
		}
	}
}
