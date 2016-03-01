/**
 * 
 */
/**
 * @author 
 *
 */
package photo_gallery;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;
import java.util.Arrays;

import javax.imageio.ImageIO;

public class Test {

	        
	String[] PICS = new String [100];
	
    // File representing the folder that you select using a FileChooser
    static final File dir = new File("C:\\Users\\Public\\Pictures\\Sample Pictures");

    // array of supported extensions (use a List if you prefer)
    static final String[] EXTENSIONS = new String[]{
        "gif", "png", "bmp", "jpg"// and other formats you need
      
    };
    // filter to identify images based on their extensions
    static final FilenameFilter IMAGE_FILTER = new FilenameFilter() {

        @Override
        public boolean accept(final File dir, final String name) {
            for (final String ext : EXTENSIONS) {
                if (name.endsWith("." + ext)) {
                    return (true);
                }
            }
            return (false);
        }
    };

    public static void main(String[] args) {

        if (dir.isDirectory()) { // make sure it's a directory
            for (final File f : dir.listFiles(IMAGE_FILTER)) {
                BufferedImage img = null;
                
                	
                String[] Photos= new String [1];
                int j=0;
                
                try {
                	                		
                	
                    img = ImageIO.read(f);

                    // you probably want something more involved here
                    // to display in your UI
                    
                    //System.out.println("image: " + f.getName());
                    //System.out.println(" width : " + img.getWidth());
                    //System.out.println(" height: " + img.getHeight());
                    //System.out.println(" size  : " + f.length());
                    
                    String PICS  = f.getName();
                    
                    String one = f.getName();
                    
                    
                    
                    
					Photos[j]=one;
					j++;
                    
                    
                	}
                    
                 
                 catch (final IOException e) {
                    // handle errors here
                }
                int m;
                for ( m=0; m < Photos.length; m++ ) {
                System.out.println( Photos[m] );
                }
            }
        }
    }
}
//}