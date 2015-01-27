package test;

import javax.swing.JFrame;

public class Maze {
	   public static void main (String [] args) {
	      JFrame world = new JFrame();
	      world.setSize(300, 300);
	      world.setTitle("Maze solver");
	      Test1 p = new Test1();
	      world.setContentPane(p);
	      world.setVisible(true);
	      Thread gameThread = new Thread(p);
	      gameThread.start();
	   }
	}