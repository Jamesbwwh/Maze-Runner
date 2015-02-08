import java.awt.EventQueue;
import java.awt.FileDialog;
import java.awt.BorderLayout;
import java.awt.Image;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JToolBar;
import javax.swing.JButton;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.io.IOException;

public class Maze_Runner {

	private JFrame frmMazeRunner;
	private MazeGraphics mazeGraphics;
	private Maze maze;
	
	/*
	 * description: This is the main function of the program. Opens up the frame window.
	 */

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Maze_Runner window = new Maze_Runner();
					window.frmMazeRunner.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public Maze_Runner() {
		initialize();
	}
	
	/*
	 * description: This function is used to set the frame of the program. 
	 * 				
	 * file menu:		Load File: Used to open up the text file (Maze) given.
	 * 					Exit: Exit the program.
	 * 
	 * secondary menu: 	File: Used to open up the text file (Maze) given.
	 * 					Run: Use to generate agent and track the target
	 * 				
	 */

	private void initialize() {
		frmMazeRunner = new JFrame();
		frmMazeRunner.setTitle("Maze Runner");
		frmMazeRunner.setSize(600, 600);
		frmMazeRunner.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		JMenuBar menuBar = new JMenuBar();
		frmMazeRunner.setJMenuBar(menuBar);
		

		/* JMenu mnFile = new JMenu("File");
		menuBar.add(mnFile);

		JMenuItem mntmLoadFile = new JMenuItem("Load File");
		mntmLoadFile.addActionListener(new fileEventHandler());
		mnFile.add(mntmLoadFile);

		JMenuItem mntmExit = new JMenuItem("Exit");
		mntmExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
			}
		});
		mnFile.add(mntmExit);

		JMenu mnHelp = new JMenu("Help");
		menuBar.add(mnHelp);

		JMenuItem mntmAbout = new JMenuItem("About");
		mnHelp.add(mntmAbout); */

		JToolBar toolBar = new JToolBar();
		toolBar.setFloatable(false);
		frmMazeRunner.getContentPane().add(toolBar, BorderLayout.PAGE_START);

		JButton btnFile = new JButton();
		try {
		    Image img = ImageIO.read(getClass().getResource("file.png"));
		    btnFile.setIcon(new ImageIcon(img));
		  } catch (IOException ex) {
		  }
		btnFile.addActionListener(new fileEventHandler());
		toolBar.add(btnFile);

		JButton btnRun = new JButton();
		try {
		    Image img = ImageIO.read(getClass().getResource("run.png"));
		    btnRun.setIcon(new ImageIcon(img));
		  } catch (IOException ex) {
		  }
		btnRun.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				DepthFirstSearch dfs = new DepthFirstSearch(maze, mazeGraphics);
				Thread newThread = new Thread(dfs);
				newThread.start();
			}
		});
		toolBar.add(btnRun);

		JButton btnStop = new JButton();
		try {
		    Image img = ImageIO.read(getClass().getResource("stop.png"));
		    btnStop.setIcon(new ImageIcon(img));
		  } catch (IOException ex) {
		  }
		btnStop.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
			}
		});
		toolBar.add(btnStop);
	}
	
	/*
	 * description: This function is for selecting and opening a text file to display in the frame.
	 */

	private class fileEventHandler implements ActionListener {
		public void actionPerformed(ActionEvent arg0) {
			if (maze != null) {
				frmMazeRunner.getContentPane().remove(mazeGraphics);
			}
			FileDialog fd = new FileDialog(new JFrame(), "Choose a file",FileDialog.LOAD);
			fd.setFile("*.txt");
			fd.setVisible(true);
			String filename = fd.getFile();
			if (filename == null)
				return;
			else {
				try {
					maze = new Maze(FileIO.loadMaze(filename));
					mazeGraphics = new MazeGraphics(maze);
					frmMazeRunner.getContentPane().add(mazeGraphics,BorderLayout.CENTER);
					mazeGraphics.setSize(frmMazeRunner.getContentPane().getWidth(), frmMazeRunner.getContentPane().getHeight());
					mazeGraphics.canvasSize();
					frmMazeRunner.repaint();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}
}
