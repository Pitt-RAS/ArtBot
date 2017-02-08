If the video is not showing, or the localhost shuts down...

1) Ctrl+Alt+F2 to open the terminal
2) User: kioskuser
3) Pass: t3hSy$tem
4) Type the following commands
	DISPLAY=:0.0
	export DISPLAY
	xhost +localhost
5) Kick off the bottle.py script as sudo