import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class MazeGraphics extends JPanel {
	private static final long serialVersionUID = -1328413435121135874L;
	private static final int speedSleep = 30;
	
	private int width, height, cellWidth, cellHeight;
	private Graphics me = null;
	private Maze theMaze = null;
	private Color[] color = { Color.white, Color.black, Color.yellow, Color.red };

	public MazeGraphics(Maze maze) {
		theMaze = maze;
	}

	public void paint(Graphics g) {
		for (int i = 0; i < theMaze.getRow(); i++) {
			for (int j = 0; j < theMaze.getCol(); j++) {
				if (theMaze.getMaze(i, j) == 0)
					g.setColor(color[Maze.WALL]);
				else
					g.setColor(color[Maze.UNEXPLORED]);
				g.fillRect(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
			}
		}
	}

	boolean canvasSize() {
		if (getWidth() != width || getHeight() != height) {
			width = getWidth();
			height = getHeight();
			cellWidth = width / theMaze.getCol();
			cellHeight = height / theMaze.getRow();
			return true;
		}
		return false;
	}

	synchronized void putSquare(int row, int col, int colorNum) {
		if (canvasSize() || me == null) {
			if (me != null) me.dispose();
			me = getGraphics();
		}
		me.setColor(color[colorNum]);
		me.fillRect(col * cellWidth, row * cellHeight, cellWidth, cellHeight);
		try {
			Thread.sleep(speedSleep);
		} catch (InterruptedException e) {
		}
	}
}
