// CS 0401 Fall 2016
// Assignment 5 "starter" program.  You may use this as a starting point for
// Assignment 5.  

// Note 1: You will only receive credit for your additions and not for any of
// the functionality that is already provided.
 
// Note 2: You are not obliged to use this code at all.  If you can implement
// the requirements of Assignment 5 from scratch with your own code, that is
// also fine.  However, you must use the Mosaic, MCircle and MSquare classes
// as given without any changes.

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;
import java.util.*;
import java.io.*;
import javax.imageio.*;
import java.awt.image.*;
import java.awt.print.*;
import javax.swing.JFileChooser;
import javax.swing.filechooser.*;
import javax.swing.JColorChooser;
import javax.swing.GroupLayout;

public class Blocker
{
	public static String software = "Mosaic Art 1.0";
	
	// ArrayList of Mosaic to store the individual shapes.  Note that
	// since Mosaic is the superclass of both MCircle and MSquare, both
	// shapes can be stored in this ArrayList
	private ArrayList<Mosaic> chunks;
	
	private Mosaic m;
	private DrawPanel thePanel;
	private JPanel buttonPanel;
	private JFrame theWindow;
	private JButton paintIt, eraseIt;
	
	private double X, Y;
	private int selected;

	private boolean painting, erasing, changed, picFile, circleShape;
	
	private Color newColor;
	private String currFile;
		
	private JMenuBar theBar;
	private JMenu fileMenu, defaultsMenu, setShape;
	private JMenuItem endProgram, saveAs, newItem, saveItem, Square, Circle; 

	
	public Blocker()
	{
		theWindow = new JFrame(software);
		theWindow.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);

		thePanel = new DrawPanel(1650, 928); //make same resolution as your photo of floor

		newColor = Color.RED;

		selected = -1;
		painting = false;
		erasing = false;
		circleShape = true;
		
		paintIt = new JButton("Paint");
		eraseIt = new JButton("Erase");
		
		newItem = new JMenuItem("New");
		saveItem = new JMenuItem("Save");
		saveAs = new JMenuItem("Save As");
		endProgram = new JMenuItem("Exit");
		Square= new JMenuItem("Vertical");
		Circle= new JMenuItem("Horizontal");
		
		ActionListener bListen = new ButtonListener();
		paintIt.addActionListener(bListen);
		eraseIt.addActionListener(bListen);
		saveAs.addActionListener(bListen);
		endProgram.addActionListener(bListen);
		newItem.addActionListener(bListen);
		saveItem.addActionListener(bListen);
		Square.addActionListener(bListen);
		Circle.addActionListener(bListen);
		
		buttonPanel = new JPanel();
		buttonPanel.setLayout(new GridLayout(1,2));
		buttonPanel.add(paintIt);
		buttonPanel.add(eraseIt);
		theWindow.add(buttonPanel, BorderLayout.SOUTH);
		theWindow.add(thePanel, BorderLayout.NORTH);
		
		theBar = new JMenuBar();
		theWindow.setJMenuBar(theBar);
		fileMenu = new JMenu("File");
		defaultsMenu=new JMenu("Defaults");
		setShape=new JMenu("Set Shape");
		
		theBar.add(fileMenu);
		theBar.add(defaultsMenu);
		

		fileMenu.add(newItem);
		fileMenu.add(saveItem);		
		fileMenu.add(saveAs);
		fileMenu.add(endProgram);
		
		defaultsMenu.add(setShape);
		
		setShape.add(Square);
		setShape.add(Circle);

		String arg = "floor1.png"; //change for each floor image 
		
		ImageIcon icon = new ImageIcon(arg); 
		JLabel picLabel = new JLabel(); 
		picLabel.setIcon(icon); 
		thePanel.add(picLabel);

		theWindow.pack();
		theWindow.setVisible(true);
		
	}	
	
	private class DrawPanel extends JPanel
	{
		private int prefwid, prefht;
		
		// Initialize the DrawPanel by creating a new ArrayList for the images
		// and creating a MouseListener to respond to clicks in the panel.
		public DrawPanel(int wid, int ht)
		{
			prefwid = wid;
			prefht = ht;
			
			chunks = new ArrayList<Mosaic>();
			
			// Add MouseListener to this JPanel to respond to the user
			// pressing the mouse.  In your assignment you will also need a
			// MouseMotionListener to respond to the user dragging the mouse.
			addMouseListener(new MListen());	
		}
		
		// This method allows a window that encloses this panel to determine
		// how much space the panel needs.  In particular, when the "pack()"
		// method is called from an outer JFrame, this method is called
		// implicitly and the result determines how much space is needed for
		// the JPanel
		public Dimension getPreferredSize()
		{
			return new Dimension(prefwid, prefht);
		}
		
		// This method is responsible for rendering the images within the
		// JPanel.  You should not have to change this code.
		public void paintComponent (Graphics g)       
		{
			super.paintComponent(g);
			
			Graphics2D g2d = (Graphics2D) g;
			for (int i = 0; i < chunks.size(); i++)
			{
				chunks.get(i).draw(g2d);
			}
		}
		
		// Add a new Mosaic and repaint.  The repaint() method call requests
		// that the panel be redrawn.  Make sure that you call repaint()
		// after changes to your scenes so that the changes are actually
		// exhibited in the display.
		public void add(Mosaic m)
		{
			chunks.add(m);
			repaint();
			changed=true;
		}
		
		// Remove the Mosaic at index i and repaint
		public void remove(int i)
		{
			if (chunks.size() > i)
				chunks.remove(i);
			repaint();
			changed=true;
		}
		
		// Select a Mosaic that contains the point (x, y).  Note that this
		// is using the contains() method of the Mosaic class, which in turn
		// is checking within the underlying RectangularShape of the object.
		public int select(double x, double y)
		{
			for (int i = 0; i < chunks.size(); i++)
			{
				if (chunks.get(i).contains(x, y))
				{
					return i;
				}
			}
			return -1;
		}
	}
	
	// Save the images within the window to a file.  Run this program to see the 
	// format of the saved file.
	public void saveImages()
	{
		try
		{
			PrintWriter P = new PrintWriter(new File(currFile));
			for (int i = 0; i < chunks.size(); i++)
			{
				P.println(chunks.get(i).saveFile(i));
			}
			P.close();
			changed=false;
		}
		catch (IOException e)
		{
			JOptionPane.showMessageDialog(theWindow, "I/O Problem - File not Saved");
		}
	}

	// Listener for some buttons.  Note that the JMenuItems are also listened
	// for here.  Like JButtons, JMenuItems also generate ActionEvents when
	// they are clicked on.  You will need to add more JButtons and JMenuItems
	// to your program and the logic of handling them will also be more
	// complex.  See details in the Assignment 5 specifications.
	private class ButtonListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			if (e.getSource() == paintIt)
			{
				painting = true;
				paintIt.setForeground(Color.RED);
				erasing = false;
				eraseIt.setForeground(Color.BLACK);
			}
			else if (e.getSource() == eraseIt)
			{
				painting = false;
				paintIt.setForeground(Color.BLACK);
				erasing = true;
				eraseIt.setForeground(Color.RED);
			}
			else if (e.getSource() == saveAs)
			{
				String temp = JOptionPane.showInputDialog(theWindow,"Enter new file name");
					
				if (temp==null) 
				{
				} 
				else
				{
					currFile = temp + ".txt";
					saveImages();
					theWindow.setTitle(software + " - " + currFile);
					changed=false;
					picFile=false;
				}	
			}
			else if (e.getSource() == endProgram)
			{
				if (changed)
				{
					int i = JOptionPane.showConfirmDialog(null,"Do you want to save before quitting?", "Choose One", JOptionPane.YES_NO_OPTION);
				 
					if (i==0)
					{
						currFile = "output.txt";
						saveImages();
						theWindow.setTitle(software + " - " + currFile);
					}
				}
				System.exit(0);		
			}
        	else if (e.getSource() == saveItem)
			{
				if (changed)
				{
					currFile = "output.txt";
					saveImages();
					theWindow.setTitle(software + " - " + currFile);
				}
				changed=false;
			}
			else if (e.getSource() == newItem)
			{
				if (changed)
				{
					int i = JOptionPane.showConfirmDialog(null,"Do you want to save your mosaic?", "Choose One", JOptionPane.YES_NO_OPTION);
				 
					if (i==0)
					{
						if (currFile==null)
						{
							currFile = "output.txt";
							saveImages();
							theWindow.setTitle(software + " - " + currFile);
						}
						else 
						{
							saveImages();
							theWindow.setTitle(software + " - " + currFile);
						}
					}
				}
				
				chunks.clear();
				thePanel.repaint();
				changed=false;
				currFile=null;
				picFile=false;
			}
			
			else if (e.getSource() == Circle)
			{
				circleShape=true;
			}
			else if (e.getSource() == Square)
			{
				circleShape=false;
			}
		}
	}
	
	// Simple mouse event handling to allow a mousePressed to add or remove
	// a Mosaic from the display.  You will need to enhance this
	// MouseAdapter and you will also need to add a MouseMotionListener to
	// your program.  In this simple program all of the Mosaics drawn are
	// MCircles and they all have the same size and color.  You must add in
	// your program the ability to change all of these attributes.
	private class MListen extends MouseAdapter
	{
		public void mousePressed(MouseEvent e)
		{
			X = e.getX();  // Get the location where mouse was pressed
			Y = e.getY();
			
			if (painting)
			{
				if (circleShape)
				{
					// create new MCircle and add it to the ArrayList
					m = new MSquare(25, 12, X, Y, newColor);
					thePanel.add(m);
				}
				else 
				{
					m = new MSquare(12, 25, X, Y, newColor);
					thePanel.add(m);
				}
				
			}
			else if (erasing)
			{
				// see if the point is within a shape -- if so delete
				// that shape
				int loc = thePanel.select(X, Y);
				if (loc > -1)
				{
					thePanel.remove(loc);
				}
			}
				
		}			
	}     
     
	public static void main(String [] args)
	{
		new Blocker();
	}
}
