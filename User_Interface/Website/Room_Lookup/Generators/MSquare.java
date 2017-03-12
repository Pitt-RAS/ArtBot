// CS 0401 Fall 2016
// MSquare subclass of Mosaic.

// The only difference between this class and MCircle is the underlying
// RectangularShape and the text shown in the saveFile() method.  See
// MCircle for more comments.

import java.awt.geom.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.lang.Math;

public class MSquare extends Mosaic
{
	protected double Width, Height, X, Y;
	
	public MSquare()
	{
		sh = new Rectangle2D.Double(0,0,0,0);
	}
	
	public MSquare(double width, double height, double x, double y, Color c)
	{
		super();
		
		Width = width;
		Height = height;
		X = x;
		Y = y;
		
		sh = new Rectangle2D.Double(x-width/2, y-height/2, width, height);
		col = c;
		highlighted = false;
	}
	
	public String saveFile(int x)
	{
		int i = x + 100;
		
		
		double top = 98.3-(619-Y)/619*100;
		double right = (1100-X)/1100*100-1;
		
		
		StringBuilder b = new StringBuilder();
		
		b.append("<div id="); 
		b.append('"');
		b.append("block"+ i + '"' + "style=" + '"' + "position:absolute; top: ");
		b.append(String.format("%.1f",top));
		b.append("%; right: ");
		b.append(String.format("%.1f",right));
		b.append("%;  width: " + Width + "px; height: " + Height + "px;" +'"' + "></div>");
		
		return b.toString();	
		
	}
}