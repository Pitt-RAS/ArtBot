import numpy as np
import cv2
import os
import time
import struct

#Desired window dimensions
WINDOW_X = 1300
WINDOW_Y = 800

#Pixel dimensions of image retrieved from camera
CAMERA_X = 720
CAMERA_Y = 405
def panther_video(arduino):
	if os.path.exists('./kill.txt'):
		os.remove("./kill.txt")

	cap = cv2.VideoCapture(0)
	
	#Kick-off Vision Arduino Code
	arduino.write('0') 	
	time.sleep(1)
	
	face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
	#smile_cascade = cv2.CascadeClassifier('haarcascade_smile.xml')
	#eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')

	while(1):		
		_, img = cap.read()
		gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

		faces = face_cascade.detectMultiScale(gray, 1.3, 5)

		maxArea = 0
		area = 0
		
		#Print out any debugging data sent from arduino
		while arduino.inWaiting():
			print("Data available: " + arduino.readline())
		
		#calculate areas of each rectangle
		for (x,y,w,h) in faces:
			area = w*h
			if area > maxArea:
				maxArea = area

		#draw colored rectangles
		for (x,y,w,h) in faces:
			area = w*h
			if area == maxArea:
				cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
				cx = x+w/2 - CAMERA_X/2 # x coordinate of rectangle center based off center of window
				cy = y+w/2 - CAMERA_Y/2 # y coordinate of rectangle center based off center of window
				
				#Pack x + y coordinates into 1 string
				values = (cx,cy)
				string = '~' #str(0xFF)
				for i in values:
					string += struct.pack('!h',i)
				
				arduino.write(string)
				#print('green: ' + str(area)+ ' w: ' + str(x)+ ' h: ' + str(h))
				print ('rx = ' + str(rx)+ ' cx = ' + str(cx) + ' ry = ' + str(ry)+ ' cy = ' + str(cy))
			else:
				cv2.rectangle(img,(x,y),(x+w,y+h),(0,0,255),2)
				#print('red: ' + str(area)+ ' w: ' + str(w)+ ' h: ' + str(h))
		resize_img = cv2.resize(img, (WINDOW_X, WINDOW_Y))	#Image size
		cv2.startWindowThread()
		window = cv2.namedWindow("window")
		cv2.resizeWindow("window", WINDOW_X, WINDOW_Y)		#Window size
		cv2.moveWindow("window", -10, -25)		#x,y start position
		cv2.imshow('window',resize_img)
		if cv2.waitKey(1) & 0xFF == ord('q'):
			break
		if os.path.exists('./kill.txt'):
			os.remove("./kill.txt")
			break
	cv2.destroyAllWindows()
	return 1
	
def kill_video():
	print("In kill video")
	file = open('./kill.txt', 'w+')
	return 1