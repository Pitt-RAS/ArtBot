/*Program created by Andrew Saba 

Designed to aid the html generation
for Artbot Room Look-up UI

THIS PROGRAM IS NOT PERFECT AND 
ALL HTML WILL NEED FINE TUNING 
FOR YOUR SPECIFIC NEEDS	*/


import java.util.*; 

public class generator
{
	public static void main (String [] args)
	{
		int num_blocks, block_width, block_height, screen_height, screen_width, start_block;
		double start_right, start_top, increment_top, increment_right, end_top, end_right;
		double height_total_pixels, width_total_pixels, right, top;
		
		Scanner inScan = new Scanner(System.in);//initializes scanner object
		
		
		
		
		System.out.println("Start block #?");
		start_block = inScan.nextInt();
		inScan.nextLine();
		
		/*System.out.println("Screen width (pixels)?");
		screen_width = inScan.nextInt();
		inScan.nextLine();*/
		
		System.out.println("How many blocks do you need?");
		num_blocks = inScan.nextInt();
		inScan.nextLine();
		
		System.out.println("Block height?");
		block_height = inScan.nextInt();
		inScan.nextLine();
		
		System.out.println("Block width?");
		block_width = inScan.nextInt();
		inScan.nextLine();
		
		System.out.println("Start top position?");
		start_top = inScan.nextDouble();
		inScan.nextLine();
			
		System.out.println("Start right position?");
		start_right = inScan.nextDouble();
		inScan.nextLine();
		
		System.out.println("Increment for right position?");
		increment_right = inScan.nextDouble();
		inScan.nextLine();
		
		System.out.println("Increment for top position?");
		increment_top = inScan.nextDouble();
		inScan.nextLine();
		
		/*
		System.out.println("End top position?");
		start_top = inScan.nextDouble();
		inScan.nextLine();
			
		System.out.println("End right position?");
		start_right = inScan.nextDouble();
		inScan.nextLine();
		
		height_total_pixels = block_height + increment_top * screen_height;
		width_total_pixels = block_width + increment_right * screen_width;
		*/
		
		right = start_right;
		top = start_top;
		
		String printout;
		
		
		for (int i = start_block; i<= (start_block +num_blocks); i++)
		{
			System.out.print("<div id="); 
			System.out.print('"');
			System.out.print("block"+ i + '"' + "style=" + '"' + "position:absolute; top: ");
			System.out.printf("%.2f",top);
			System.out.print("%; right: ");
			System.out.printf("%.2f",right);
			System.out.print("%;  width: " + block_width + "px; height: " + block_height + "px;" +'"' + "></div>");
			System.out.println();
			
			right = increment_right + right;
			top = increment_top + top;
			
		}
		
		
		
	}
}