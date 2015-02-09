import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

public class MazeGraphics extends JPanel {
	private static final long serialVersionUID = -1328413435121135874L;

	private int width, height, cellWidth, cellHeight, left, top;
	private Maze theMaze = null;
	private Color[] color = { Color.white, Color.black, Color.yellow, Color.red, Color.pink, Color.orange };

	public MazeGraphics(Maze maze) {
		theMaze = maze;
	}

	/*
	 * description: This is used to set the color of each components
	 */

	public void paint(Graphics g) {
		for (int i = 0; i < theMaze.getRow(); i++) {
			for (int j = 0; j < theMaze.getCol(); j++) {
				switch (theMaze.getMaze(i, j)) {
				case Maze.WALL:
					g.setColor(color[Maze.WALL]);
					break;
				case Maze.UNEXPLORED:
				case Maze.GLADER:
					g.setColor(color[Maze.UNEXPLORED]);
					break;
				case Maze.VISITED:
					g.setColor(color[Maze.VISITED]);
					break;
				case Maze.PATH:
				case Maze.GRIEVER:
					g.setColor(color[Maze.PATH]);
					break;
				default:
				}
				g.fillRect(j * cellWidth + left, i * cellHeight + top, cellWidth, cellHeight);
				switch (theMaze.getMaze(i, j)) {
				case Maze.GLADER:
					g.setColor(color[Maze.GLADER]);
					break;
				case Maze.GRIEVER:
					g.setColor(color[Maze.GRIEVER]);
					break;
				default:
				}
				g.fillOval(j * cellWidth + left, i * cellHeight + top, cellWidth, cellHeight);
			}
		}
	}

	public void canvasSize() {
		left = 0;
		top = 35;
		width = getWidth() - left;
		height = getHeight() - top;
		cellWidth = width / theMaze.getCol();
		cellHeight = height / theMaze.getRow();
	}

	/*
	 * description: This is used to update the components when it is moving
	 */

	public static void updateGraphics(MazeGraphics g) {
		g.paintComponents(g.getGraphics());
		g.update(g.getGraphics());
		try { Thread.sleep(100); } catch (Exception ex) { }
	}
}
