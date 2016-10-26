<html><head><title>Panther Controls Menu</title></head>

<body>

<?php

echo "<p>Control Page</p><p>";

$port = fopen("/dev/ttyACM0", "w") or die("Unable to open file!"); //You have to check which port your Arduino is connected to 
sleep(2);

?>

<br>

<?php

// Turn Led ON ?>

<form action="Panther_Kiosk_Panther_Controls_Menu.php" method="POST">

<input type="hidden" name="turn" value="on" />

<input type="Submit" value="on">

</form>

<?php

// Turn Led OFF ?>

<form action="Panther_Kiosk_Panther_Controls_Menu.php" method="POST">

<input type="hidden" name="turn" value="off" />

<input type="Submit" value="off">

</form></p>

<?php
//php Command to turn led on

if ($_POST['turn']=="on"){

echo "Turned on";

fwrite($port, "n");

}

//php Command to turn led off
if ($_POST['turn']=="off"){

echo "Turned off";

fwrite($port, "f");

}

fclose($port);

?>

</body></html>
