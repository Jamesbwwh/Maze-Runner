import java.awt.*;
import javax.swing.*;

public class MazeGraphics extends JPanel {

	int row, col;
	int[][] maze;

	final static int BACKGROUND = 0;
	final static int WALL = 1;
	final static int PATH = 2;
	final static int EMPTY = 3;
	final static int VISITED = 4;
	Color[] color = { Color.green, Color.black, Color.red, Color.blue,
			Color.yellow };

	public MazeGraphics(String raw) {
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

	public void paint(Graphics g) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (maze[i][j] < 0)
					g.setColor(color[EMPTY]);
				else
					g.setColor(color[maze[i][j]]);
				g.fillRect(j * 25 + 0, i * 25 + 0, 25, 25);
			}
		}
	}

	public void printString() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				System.out.print(maze[i][j]);
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
	}
}
