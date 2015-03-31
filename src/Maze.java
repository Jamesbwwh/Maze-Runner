public class Maze {
	private int row, col;
	private int[][] maze;

	final static int WALL = 0;
	final static int UNEXPLORED = 1;
	final static int VISITED = 2;
	final static int PATH = 3;
	final static int GLADER = 4;
	final static int GRIEVER = 5;

	public Maze(String raw) {
		String[] rows = raw.split("\n");
		row = rows.length;
		col = rows[0].length();
		maze = new int[row][col];
		for (int i = 0; i < row; i++) {
			char[] columns = rows[i].toCharArray();
			for (int j = 0; j < col; j++) {
				if (columns[j] == 'B') maze[i][j] = Maze.UNEXPLORED;
				else if (columns[j] == 'E') maze[i][j] = Maze.GLADER;
				else maze[i][j] = Maze.WALL;
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

	public void printString() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) System.out.print(maze[i][j]);
			System.out.println();
		}
	}

	public String returnString() {
		String returnStr = "";
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				switch (maze[i][j]) {
				case Maze.WALL:
					returnStr += 'A';
					break;
				case Maze.UNEXPLORED:
					returnStr += 'B';
					break;
				case Maze.VISITED:
					returnStr += 'C';
					break;
				case Maze.PATH:
					returnStr += 'D';
					break;
				case Maze.GLADER:
					returnStr += 'E';
					break;
				case Maze.GRIEVER:
					returnStr += 'F';
					break;
				default:
					break;
				}
			}
			returnStr += " \n";
		}
		return returnStr;
	}
}
