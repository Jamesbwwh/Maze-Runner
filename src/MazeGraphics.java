import java.awt.*;
import javax.swing.*;
public class MazeGraphics extends JFrame {
	
	public void paint(Graphics g) {
		g.setColor(Color.BLACK);
		g.fillRect(100, 130, 100, 50);
		
		g.setColor(Color.RED);
		g.fillOval(120, 170, 20, 20);
		g.fillOval(180, 170, 20, 20);
		
		g.setColor(Color.CYAN);
		g.fillRect(170, 140, 30, 20);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		MazeGraphics mg = new MazeGraphics();
//		mg.setSize(500, 500);
//		mg.setBackground(Color.LIGHT_GRAY);
//		mg.setVisible(true);
//		mg.repaint();
	}

}
