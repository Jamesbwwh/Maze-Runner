import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

public class MazeGraphics extends JPanel {
	private static final long serialVersionUID = -1328413435121135874L;
	//private static final int speedSleep = 30;

	//final static int SQUARE = 0;
	//final static int OVAL = 1;

	private int width, height, cellWidth, cellHeight;
	//private Graphics me = null;
	private Maze theMaze = null;
	private Color[] color = { Color.white, Color.black, Color.yellow, Color.red, Color.pink, Color.orange };

	public MazeGraphics(Maze maze) {
		theMaze = maze;
	}

	public void paint(Graphics g) {
		for (int i = 0; i < theMaze.getRow(); i++) {
			for (int j = 0; j < theMaze.getCol(); j++) {
				switch (theMaze.getMaze(i, j)) {
				case Maze.WALL:
					g.setColor(color[Maze.WALL]);
					g.fillRect(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
					break;
				case Maze.UNEXPLORED:
					g.setColor(color[Maze.UNEXPLORED]);
					g.fillRect(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
					break;
				case Maze.VISITED:
					g.setColor(color[Maze.VISITED]);
					g.fillRect(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
					break;
				case Maze.PATH:
					g.setColor(color[Maze.PATH]);
					g.fillRect(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
					break;
				case Maze.GLADER:
					g.setColor(color[Maze.UNEXPLORED]);
					g.fillRect(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
					g.setColor(color[Maze.GLADER]);
					g.fillOval(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
					break;
				case Maze.GRIEVER:
					g.setColor(color[Maze.UNEXPLORED]);
					g.fillRect(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
					g.setColor(color[Maze.GRIEVER]);
					g.fillOval(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
					break;
				default:
				}
			}
		}
	}

	public void canvasSize() {
		width = getWidth();
		height = getHeight();
		cellWidth = width / theMaze.getCol();
		cellHeight = height / theMaze.getRow();
	}

//	public synchronized void refreshCanvas() {
//		if (canvasSize() || me == null) {
//			if (me != null) me.dispose();
//			me = getGraphics();
//		}
//		me.setColor(color[colorNum]);
//		if (type == SQUARE) me.fillRect(col * cellWidth, row * cellHeight, cellWidth, cellHeight);
//		else me.fillOval(col * cellWidth, row * cellHeight, cellWidth, cellHeight);
//		try {
//			Thread.sleep(speedSleep);
//		} catch (InterruptedException e) {
//		}
//	}
}
