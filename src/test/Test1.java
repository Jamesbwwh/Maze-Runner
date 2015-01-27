package test;

import java.awt.*;
import javax.swing.*;

class Test1 extends JPanel implements Runnable {
   public Test1() {
   }

   final private int SquareSize = 15;
   final private int BoardSize = 17;
   private boolean free = false;
   int locX = 1, locY = 1;

   private String [][] iboard = 
	   { {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},
	     {"1","r","0","0","1","1","0","0","0","0","0","0","0","0","0","0","1"},
	     {"1","1","1","0","0","0","0","1","1","1","0","1","1","1","1","0","1"},
	     {"1","0","0","1","o","1","1","0","1","0","0","1","0","0","0","0","1"},
	     {"1","1","0","1","o","1","0","0","1","0","1","1","0","1","1","1","1"},
	     {"1","1","0","0","0","0","0","1","0","0","1","0","0","1","0","0","1"},
	     {"1","0","0","1","1","0","1","0","0","1","1","0","1","0","0","1","1"},
	     {"1","0","1","0","o","0","1","0","1","0","0","0","1","0","0","0","1"},
	     {"1","0","0","0","1","1","0","0","1","0","1","1","1","1","1","0","1"},
	     {"1","1","1","0","1","0","0","1","0","0","1","0","0","0","0","0","1"},
	     {"1","0","0","0","1","0","0","1","0","0","1","1","1","0","1","1","1"},
	     {"1","0","1","1","o","1","0","0","1","0","0","0","1","0","0","0","1"},
	     {"1","0","1","0","o","0","1","0","1","1","1","0","0","1","1","0","1"},
	     {"1","0","1","0","1","0","1","0","0","0","0","1","0","0","0","0","1"},
	     {"1","0","1","0","1","0","1","1","1","1","0","1","0","1","1","1","1"},
	     {"1","0","0","0","1","0","1","G","0","0","0","1","0","0","0","0","1"},
	     {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"}};
		
   
	
	/*
		description: Checks the whole array
    */
   	public void paintComponent(Graphics g) {
    	super.paintComponent(g);
    	for(int i = 0;  i < iboard.length; i++){
    		for(int j = 0; j< iboard.length; j++){
  				if(i==locX && j==locY){
  					g.setColor(Color.red);
      				g.fillOval(j*15,i*15,15,15);
  				}
      			else if(iboard[i][j]=="1"){
      				g.setColor(Color.black);
      				g.fillRect(j*SquareSize,i*SquareSize,BoardSize,BoardSize);
      			}
      			else if(iboard[i][j]=="G"){
      				g.setColor(Color.blue);
      				g.fillOval(j*15,i*15,15,15);
      			}
      			else if(iboard[i][j]=="r"){
      				g.setColor(Color.red);
      				g.fillOval(j*15,i*15,15,15);
      			}
      			else if(iboard[i][j]=="y"){
      				g.setColor(Color.yellow);
      				g.fillOval(j*15,i*15,15,15);
      			}
      			else{
      				g.setColor(Color.white);
      				g.fillRect(j*SquareSize,i*SquareSize,BoardSize,BoardSize);
      			}
      		}
      	}
   	}
   /*
		description: starts it at 1,1
   */
   public void run () {
      moveFrom(1,1);
   }
   
   /*
		description: checks to see if it's the Goal
   */
   public boolean isGoal(int x, int y){
   		if(iboard[x][y]=="G")
   			return true;
   		else 
   			return false;
   }
   /*
		description: sets the board to a y wherever its at to be visited
   */
   public void setVisited(int x, int y){	
   			iboard[x][y] = "y";
   			locX = x;
   			locY = y;
   }
   
   /*
		description: checks to see if there is a wall
   */
   public boolean isWall(int x, int y){
   		if(iboard[x][y]=="1")
   			return true;
   		else 
   			return false;
   }
   /*
		description:checks the array to see if it has been visited
   */
   public boolean isVisited(int x, int y){
   		if(iboard[x][y]=="y")
   				return true;
   			else 
   				return false;
   }
   /*
		description: Recursive function, this is what makes this work. 
		The base case has three parts: 
		1. It returns if there is a wall or has been visited before.
		2. If it hits the goal it brings up a message that says that you found it and then exits.
		3. For the recursive part it sets where its at as visited, repaints,
		sleeps and then calls itself to move in every direction.
	*/
   private void moveFrom(int x, int y) {
      	if(isWall(x,y))
      		return;
      	if(isVisited(x,y))
      		return;
      	if(isGoal(x,y)){
      		free = true;
      		JOptionPane.showMessageDialog(this, "You reached your goal");
  			System.exit(0);
      	}
      	if(!free){
      		setVisited(x,y);
      		repaint();
      		try {Thread.sleep(300); } catch (Exception e) { }
    		
			moveFrom(x-1,y);
			moveFrom(x+1,y);
			moveFrom(x,y-1);
			moveFrom(x,y+1);
		}		
   }
}