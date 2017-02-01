from bottle import route, run, static_file
from face_video import panther_video, kill_video
from selenium import webdriver
from threading import Thread
import thread

@route('/hello')
def hello():
    return "Hello World!"
	
@route('/static/<filename:path>')
def send_static(filename):
	print("Getting file" + filename)
	if (filename == "Panther_Kiosk_Panther_Vision_Menu.html"):
		t = thread.start_new_thread ( panther_video, ())
	elif(filename == "Panther_Kiosk_Main.html"):
		t2 = thread.start_new_thread(kill_video, ())
	response = static_file(filename, root='../')	
	response.set_header("Cache-Control", "public, max-age=0")
	return response
	
run(host='localhost', port=8081, debug=True)
