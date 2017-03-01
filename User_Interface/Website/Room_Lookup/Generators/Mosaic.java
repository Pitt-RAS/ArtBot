// CS 0401 Fall 2016
// Mosaic class
// This is the parent class of the shapes that you will use for your picture
// maker.  Note that it is abstract so you cannot make a Mosaic object.  It
// also has one abstract method, saveFile(), which must be implemented by the
// subclasses.  See more comments below.

import java.awt.geom.*;
import javax.swing.*;
import java.awt.*;

public abstract class Mosaic
{
	// Note the data.  See RectangularShape in the Java API.  This is an
	// abstract class but it has subclasses that are used in the subclasses of 
	// Mosaic.
	protected RectangularShape sh;
	protected Color col;
	protected boolean highlighted;
	
	public Mosaic()
	{}
	
	// Note how this method works -- a point is contained in a Mosaic if it is
	// contained in the RectangularShape that the Mosaic contains.  This is an
	// example of composition -- we build our Mosaic using a RectangularShape
	// and utilize the functionality of the RectangularShape for our Mosaic.
	public boolean contains(double x, double y)
	{
		return sh.contains(new Point2D.Double(x, y));
	}
	
	// This method is called to render the Mosaic in a graphical context.
	// Note the parameter.  This method will be called from a JFrame or a
	// JPanel to render the Mosaic within the window.  Note the use of the
	// draw() and fill() methods.  These are predefined to render a
	// RectangularShape.  The draw() method will draw the outline of the
	// shape and the fill() method will draw it filled in.
	public void draw(Graphics2D g)
	{
		g.setColor(col);
		if (highlighted)
			g.draw(sh);
		else
			g.fill(sh);
	}
	
	// Set and get the color of this Mosaic
	public void setColor(Color newColor)
	{
		col = newColor;
	}
	
	public Color getColor()
	{
		return col;
	}
	
	// Set and get the size of this Mosaic
	public void setSize(double sz)
	{
		sh.setFrameFromCenter(sh.getCenterX(), sh.getCenterY(), 
					sh.getCenterX()+sz/2, sh.getCenterY()+sz/2);
	}
	
	public double getSize()
	{
		return sh.getWidth();
	}
	
	// Boolean to indicate whether it is rendered by fill() or draw()
	public void highlight(boolean b)
	{
		highlighted = b;
	}
	
	// Move this Mosaic x pixels down and y pixels over.  Note how this method
	// moves the Mosaic.  It gets the center, adds x and y to it and then
	// sets the shape to be centered at the new location.  See RectangularShape
	// for details on the specific methods.
	public void move(double x, double y)
	{
		double oldX = sh.getCenterX();
		double oldY = sh.getCenterY();
		double newX = oldX + x;
		double newY = oldY + y;
		sh.setFrameFromCenter(newX, newY, newX + sh.getWidth()/2,
										  newY + sh.getWidth()/2);
	}
	
	// This method is abstract and must be overridden in the subclasses.
	public abstract String saveFile(int i);
}