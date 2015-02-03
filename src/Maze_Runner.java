import java.io.*;
import java.awt.EventQueue;
import java.awt.FileDialog;

import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JToolBar;

import java.awt.BorderLayout;

import javax.swing.JButton;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Maze_Runner {

	private JFrame frmMazeRunner;

	/**
	 * Launch the application.
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

	/**
	 * Create the application.
	 */
	public Maze_Runner() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmMazeRunner = new JFrame();
		frmMazeRunner.setTitle("Maze Runner");
		frmMazeRunner.setSize(600, 600);
		frmMazeRunner.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		JMenuBar menuBar = new JMenuBar();
		frmMazeRunner.setJMenuBar(menuBar);

		JMenu mnFile = new JMenu("File");
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
		mnHelp.add(mntmAbout);

		JToolBar toolBar = new JToolBar();
		toolBar.setFloatable(false);
		frmMazeRunner.getContentPane().add(toolBar, BorderLayout.NORTH);

		JButton btnFile = new JButton("File");
		btnFile.addActionListener(new fileEventHandler());
		toolBar.add(btnFile);

		JButton btnRun = new JButton("Run");
		toolBar.add(btnRun);

		JButton btnStop = new JButton("Stop");
		toolBar.add(btnStop);
	}

	private class fileEventHandler implements ActionListener {
		public void actionPerformed(ActionEvent arg0) {
			FileDialog fd = new FileDialog(new JFrame(), "Choose a file",
					FileDialog.LOAD);
			fd.setFile("*.txt");
			fd.setVisible(true);
			String filename = fd.getFile();
			if (filename == null)
				return;
			else {
				FileIO file = new FileIO(filename);
				try {
					MazeGraphics graphics = new MazeGraphics(file.loadMaze());
					// graphics.printString();
					frmMazeRunner.getContentPane().add(graphics,
							BorderLayout.CENTER);
					graphics.setBounds(0, 35, frmMazeRunner.getContentPane()
							.getWidth(), frmMazeRunner.getContentPane()
							.getHeight() - 35);
					graphics.setVisible(true);
					graphics.repaint();
					graphics.checkSize();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
}
