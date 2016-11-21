from bottle import route, run, static_file
from face_video import panther_video, kill_video
from selenium import webdriver
from threading import Thread
import thread

#return variable??? parse file names into HTML?

@route('/hello')
def hello():
    return "Hello World!"
	
@route('/NO/camera')
def camera():
	#panther_video()
	try:
		thread.start_new_thread ( panther_video, ())
	except:
		print ("Error: Did not start thread")
	try:	
		thread.start_new_thread ( kill_video, ())
	except:
		print("Error: kill thread did not start")
		
	return static_file("Panther_Kiosk_Panther_Vision_Menu.html", root='../')	

@route('/static/<filename:path>')
def send_static(filename):
	if (filename == "Panther_Kiosk_Panther_Vision_Menu.html"):
		#print("if")
		t = thread.start_new_thread ( panther_video, ())
		#t = Thread(target=panther_video, args=())
		#t.start()
		#t.exit()
		#t2 = Thread(target=panther_video, args=())
		#t2.start()
		#driver = webdriver.Firefox()
		#driver.get("http://localhost:8080/NO/camera")
		#driver.refresh()
		
		#t.exit()
		#t2 = thread.start_new_thread ( panther_video, ())
		return static_file("Panther_Kiosk_Panther_Vision_Menu.html", root='../')
	else:
		print("else")
		return static_file(filename, root='../')	
	
run(host='localhost', port=8080, debug=True)