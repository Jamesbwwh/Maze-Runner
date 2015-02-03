import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

public abstract class MazeGraphics extends JPanel {
	private static final long serialVersionUID = -1328413435121135874L;
	int row, col, width, height, cellWidth, cellHeight;
	int[][] maze;

	final static int WALL = 0;
	final static int UNEXPLORED = 1;
	final static int VISITED = 2;
	final static int PATH = 3;
	Color[] color = { Color.white, Color.black, Color.yellow, Color.red };

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

	public void canvasSize() {
		if (getWidth() != width || getHeight() != height) {
			width = getWidth();
			height = getHeight();
			cellWidth = width / col;
			cellHeight = height / row;
			// System.out.println(width + " " + height);
			// System.out.println(cellWidth + " " + cellHeight);
		}
	}
}
