import java.awt.*;
import javax.swing.*;

public class MazeGraphics extends JPanel {
	private static final long serialVersionUID = -6327627470181746977L;
	int row, col, width, height, cellWidth, cellHeight;
	int[][] maze;

	final static int WALL = 0;
	final static int UNEXPLORED = 1;
	final static int VISITED = 2;
	final static int PATH = 3;
	Color[] color = { Color.white, Color.black, Color.yellow, Color.red };

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
				if (maze[i][j] == 0)
					g.setColor(color[WALL]);
				else
					g.setColor(color[UNEXPLORED]);
				g.fillRect(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
			}
		}
	}

	public void checkSize() {
		if (getWidth() != width || getHeight() != height) {
			width = getWidth();
			height = getHeight();
			cellWidth = width / col;
			cellHeight = height / row;
			System.out.println(width + " " + height);
			System.out.println(cellWidth + " " + cellHeight);
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
