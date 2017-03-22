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

