from bottle import route, run, static_file
from face_video import panther_video, kill_video
from selenium import webdriver
from threading import Thread
import thread
import subprocess
import serial
import time

elbowExtended = False
shoulderExtended = False
eyeOpen = True

arduino = serial.Serial("COM5", 9600)

time.sleep(1) #wait for board to reset
print "Sending serial data"

@route('/hello')
def hello():
    return "Hello World!"

#Body part:	# retract	# extend
#Elbow:		4		5
#Shoulder:	6		7
#eye		8 (close)	9 (open)
#Tail:		A (wag)
#Ear:		B (wiggle)
#Jaw:		C (close)	D (open)
#Spine:		E (lie down)	F (stand up)
#Neck x-y:	G (turn left)	H (turn right)
#Neck z: 	I (down)	J (up)
#Wrist:		K (down)	L (up)


	
@route('/static/elbow')
def elbow():
	global elbowExtended
	if(elbowExtended):
		arduino.write('4')
		elbowExtended = False
	else:
		arduino.write('5')
		elbowExtended = True
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response


@route('/static/shoulder')
def shoulder():
	global shoulderExtended
	if(shoulderExtended):
		arduino.write('6')
		shoulderExtended = False
	else:
		arduino.write('7')
		shoulderExtended = True	
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response

	
@route('/static/eye')
def eye():
	global eyeOpen
	if(eyeOpen):
		arduino.write('8')
		eyeOpen = False
	else:
		arduino.write('9')
		eyeOpen = True	
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response

@route('/static/tail')
def tail():
	arduino.write('A')
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response
	

@route('/static/ear')
def ear():
	arduino.write('B')
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response
	

@route('/static/jaw')
def jaw():
	global jawOpen
	if(jawOpen):
		arduino.write('C')
		jawOpen = False
	else:
		arduino.write('D')
		jawOpen = True	
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response
	

@route('/static/spine')
def spine():
	global spineUp
	if(spineUp):
		arduino.write('E')
		spineUp = False
	else:
		arduino.write('F')
		spineUp = True	
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response
	

@route('/static/xyNeck')
def xyNeck():
	#xyNeckDir: 0 - Left 1 - right
	#xyNeckPos: 0 - left 1 - center 2 - right 
	global xyNeckDir, xyNeckPos
	if(xyNeckDir == 0) #Turn left
		arduino.write('G')
		xyNeckPos = xyNeckPos + 1
		if(xyNeckPos >= 2)
			xyNeckPos = 2
			xyNeckDir = 1
	else: #Turn right
		arduino.write('H')
		xyNeckPos = xyNeckPos - 1
		if(xyNeckPos <= 0)
			xyNeckPos = 0
			xyNeckDir = 0
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response
	

@route('/static/zNeck')
def zNeck():
	#zNeckDir: 0 - down 1 - up
	#zNeckPos: 0 - down 1 - center 2 - up 
	global zNeckDir, zNeckPos
	if(zNeckDir == 1) #Turn up
		arduino.write('I')
		zNeckPos = zNeckPos + 1
		if(zNeckPos >= 2)
			zNeckPos = 2
			zNeckDir = 0
	else: #Turn down
		arduino.write('J')
		zNeckPos = zNeckPos - 1
		if(zNeckPos <= 0)
			zNeckPos = 0
			zNeckDir = 1
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response
	

@route('/static/wrist')
def wrist():
	#wristDir: 0 - down 1 - up
	#wristPos: 0 - down 1 - center 2 - up 
	global wristDir, wristPos
	if(zNeckDir == 1) #Turn up
		arduino.write('K')
		wristPos = wristPos + 1
		if(wristPos >= 2)
			wristPos = 2
			wristDir = 0
	else: #Turn down
		arduino.write('L')
		zNeckPos = zNeckPos - 1
		if(zNeckPos <= 0)
			zNeckPos = 0
			zNeckDir = 1
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response

	
@route('/static/<filename:path>')
def send_static(filename):
	print("Getting file: " + filename)	
	
	if (filename == "Panther_Kiosk_Panther_Vision_Menu.html"):
		t = thread.start_new_thread ( panther_video, (arduino,))
	elif(filename == "Panther_Kiosk_Main.html"):
		t2 = thread.start_new_thread(kill_video, ())
	response = static_file(filename, root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response

	
#print subprocess.Popen(['google-chrome', '--incognito', '--start-maximized', '-kiosk', 'http://localhost:8080/static/Panther_Kiosk_Main.html'], shell=False)
run(host='localhost', port=8081, debug=True)

