<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width,initial-scale=1.0">
  <title>RAS Panther Robot</title>
  <meta name="description" content="Some slide and push menu demos using CSS3 transitions.">
  <link rel="stylesheet" href="App_Switcher/css/font-awesome.min.css">
  <link rel="stylesheet" href="App_Switcher/css/style.css">
</head>

<body style="margin:0; padding:0">
<img src="Main_Menu/Gear_Menu.gif" style="width:100%; height: 101%;">
<!-- Gears to hold button links to all other webpages -->
<a href="Panther_Kiosk_Room_Lookup.html"><img src="Main_Menu/Circle_Room_Lookup.png" style="position: absolute; top: 13%; left: 5%; height: 35%; width:19%;"></a>
<a href="Panther_Kiosk_Extras_Menu.html"><img src="Main_Menu/Circle_Extras.png" style="position: absolute; top: 34%; left: 27.7%; height: 35%; width:19%;"></a>
<a href="Panther_Kiosk_Panther_Vision_Menu.html"><img src="Main_Menu/Circle_Panther_Vision.png" style="position: absolute; top: 7%; left: 48.7%; height: 35%; width:19%;"></a>
<a href="Panther_Kiosk_Panther_Controls_Menu.html"><img src="Main_Menu/Circle_Panther_Controls.png" style="position: absolute; top: 35%; left: 68.7%; height: 35%; width:19%;"></a>

<div id="o-wrapper" class="o-wrapper">
    <div class="c-buttons">
        <button id="c-button--slide-bottom" class="c-button">&equiv; Panther Kiosk Options </button>
    </div>
</div><!-- /o-wrapper -->

<nav id="c-menu--slide-bottom" class="c-menu c-menu--slide-bottom">
  <button class="c-menu__close" style="left:0%; position:absolute;"><font size="7"><strong>x</strong></font></button>
  <br>
  <ul class="c-menu__items">
    <li class="c-menu__item" style="font-size:350%;"><a href="Panther_Kiosk_Room_Lookup.html" class="c-menu__link"><button style="background: #FFF no-repeat center; height:150px; width: 200px;"> <font size="8" face="serif">Room Lookup</font></button></a></li>
	<li class="c-menu__item" style="font-size:350%;"><a href="Panther_Kiosk_Extras_Menu.html" class="c-menu__link"><button style="background: #FFF no-repeat center; height:150px; width: 200px;"> <font size="8" face="serif">Extras Menu</font></button></a></li>
	<li class="c-menu__item" style="font-size:350%;"><a href="Panther_Kiosk_Main.html" class="c-menu__link"><button style="background: #FFF no-repeat center; height:150px; width: 200px;"> <font size="8" face="serif">Main Menu</font></button></a></li>
	<li class="c-menu__item" style="font-size:350%;"><a href="Panther_Kiosk_Panther_Vision_Menu.html" class="c-menu__link"><button style="background: #FFF no-repeat center; height:150px; width: 200px;"> <font size="8" face="serif">Panther Vision</font></button></a></li>
	<li class="c-menu__item" style="font-size:350%;"><a href="Panther_Kiosk_Panther_Controls_Menu.php" class="c-menu__link"><button style="background: #FFF no-repeat center; height:150px; width: 200px;"> <font size="8" face="serif">Panther Controls</font></button></a></li>	
	
  </ul>
</nav><!-- /c-menu slide-bottom -->


<div id="c-mask" class="c-mask"></div><!-- /c-mask -->

<!-- menus script -->
<script src="App_Switcher/js/dist/menu.js"></script>
<script>
  /**
   * Slide bottom instantiation and action.
   */
  var slideBottom = new Menu({
    wrapper: '#o-wrapper',
    type: 'slide-bottom',
    menuOpenerClass: '.c-button',
    maskId: '#c-mask'
  });

  var slideBottomBtn = document.querySelector('#c-button--slide-bottom');
  
  slideBottomBtn.addEventListener('click', function(e) {
    e.preventDefault;
    slideBottom.open();
  });

</script>

<style>

.c-button {
    color: white;
    text-shadow: 0 0 4px black, 0 0 4px black, 0 0 4px black, 0 0 4px black, 0 0 4px black, 
	0 0 4px black, 0 0 4px black, 0 0 4px black, 0 0 4px black, 0 0 4px black, 
	0 0 4px black, 0 0 4px black, 0 0 4px black, 0 0 4px black, 0 0 4px black, 
	0 0 4px black, 0 0 4px black, 0 0 4px black, 0 0 4px black, 0 0 4px black;
	padding: 0;
	border: none;
	background: none;
	font-size: 350%;
	position:absolute;
	left:1%;
	bottom:1%;
	font-family: "Times New Roman", Times, serif;
}

body {
    position: fixed; 
    overflow:hidden;
    width: 100%;
}

</style>

</body>
</html>
