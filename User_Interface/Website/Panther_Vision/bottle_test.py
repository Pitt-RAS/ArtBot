from bottle import route, run, static_file
from face_video import panther_video, kill_video
from selenium import webdriver
from threading import Thread
import thread
import subprocess
import serial
import time

arduino = serial.Serial("/dev/ttyACM0", 9600)

time.sleep(1) #wait for board to reset
print "Sending serial data"

@route('/hello')
def hello():
    return "Hello World!"
	
@route('/static/arm')
def arm():
	print("IN THE ARMMMMMMM")
	arduino.write('0')
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response

@route('/static/leg')
def leg():
	print("IN THE LEGGGGGGG")
	arduino.write('3')
	response = static_file("Panther_Kiosk_Panther_Controls_Menu.html", root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response
	
@route('/static/<filename:path>')
def send_static(filename):
	print("Getting file: " + filename)
#	if("arm" in filename):
#		print("IN THE ARM SECTION")
#		response = static_file("Panther_Kiosk_Main.html", root='../')	
#		response.set_header("Cache-Control", "public, max-age=0")
#		return response
	
	
	if (filename == "Panther_Kiosk_Panther_Vision_Menu.html"):
		t = thread.start_new_thread ( panther_video, ())
	elif(filename == "Panther_Kiosk_Main.html"):
		t2 = thread.start_new_thread(kill_video, ())
	response = static_file(filename, root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response

	
#print subprocess.Popen(['google-chrome', '--incognito', '--start-maximized', '-kiosk', 'http://localhost:8080/static/Panther_Kiosk_Main.html'], shell=False)
run(host='localhost', port=8081, debug=True)

