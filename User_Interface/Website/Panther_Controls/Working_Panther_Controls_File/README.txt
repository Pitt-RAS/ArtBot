Author: Vinayak Nesarikar
Date Created: 6/13/16
Install Apache:
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install apache2

Useful Commands
sudo /etc/init.d/apache2 start   #start apache
sudo /etc/init.d/apache2 stop   #stop apache
sudo /etc/init.d/apache2 restart   #restart apache
To prevent Apache from autostart when booting up:
sudo update-rc.d -f apache2 remove
To restore Apache back to the autostart list:
sudo update-rc.d apache2 defaults

Install PHP:
sudo apt-get install php5 libapache2-mod-php5

Verify it worked:

sudo gedit /var/www/html/index.php

type:
<?php

print_r (phpinfo());

?>

restart apache:
sudo /etc/init.d/apache2 restart

open browser to:
http://localhost/

You should see you php information if not something went wrong.

For the Artbot:
  
  Save the home page of the kiosk as index.php is /var/www/html
with all of the other html files and dependencies

Use the Panther_Kiosk_Panther_Controls_Menu.php as the guide for making the webpage to talk to arduino. 

The arduino's code is also in this file that.

This php file only handles one arduino. If we need more than one I feel that we can you the same script, but we will have to make the serial ports that each arduino is attached to static so they will not change after reboot.

To allow serial communiction with the arduino at all times through php put this command in /etc/rc.local.

sudo chmod 777 ttyACM0

For Kiosk mode:

Have google chrome installed

Follow the instructions on this website: https://www.maketecheasier.com/turn-computer-into-internet-kiosk/ 
Change http://google.com to http://localhost/ 

run 
sudo gedit ~/.config/google-chrome/Default/Preferences
Add to "browser": {
"window_placement": {
         "bottom": 900,
         "left": 1,
         "maximized": false,
         "right": 1440,
         "top": 0,
         "work_area_bottom": 900,
         "work_area_left": 0,
         "work_area_right": 1440,
         "work_area_top": 0
      }
So it looks like this
 "browser": {
      "check_default_browser": false,
      "clear_lso_data_enabled": true,
      "custom_chrome_frame": true,
      "pepper_flash_settings_enabled": true,
      "window_placement": {
         "bottom": 900,
         "left": 1,
         "maximized": false,
         "right": 1440,
         "top": 0,
         "work_area_bottom": 900,
         "work_area_left": 0,
         "work_area_right": 1440,
         "work_area_top": 0
      }
My screen resolution was 1440x900 so change those values to fit your resolution.
