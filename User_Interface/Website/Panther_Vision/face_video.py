import numpy as np
import cv2
import os
import time
# import matplotlib.pyplot

def panther_video():
	cap = cv2.VideoCapture(0)

	face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
	#smile_cascade = cv2.CascadeClassifier('haarcascade_smile.xml')
	#eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')

	while(1):
		_, img = cap.read()
		gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

		faces = face_cascade.detectMultiScale(gray, 1.3, 5)

		maxArea = 0
		area = 0

		#calculate areas
		for (x,y,w,h) in faces:
			area = w*h
			if area > maxArea:
				maxArea = area

		#draw colored rectangles
		for (x,y,w,h) in faces:
			area = w*h
			if area == maxArea:
				cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
				#print('green: ' + str(area)+ ' w: ' + str(x)+ ' h: ' + str(h))
				print ('x = ' + str(x+w/2)+ ' y = ' + str(y+h/2))
			else:
				cv2.rectangle(img,(x,y),(x+w,y+h),(0,0,255),2)
				#print('red: ' + str(area)+ ' w: ' + str(w)+ ' h: ' + str(h))
		#size (width, height) (640, 480) = default
		#resize_img = cv2.resize(img, (1290, 747))
		cv2.startWindowThread()
		window = cv2.namedWindow("window")
		#cv2.resizeWindow("window", 1290, 747)
		#cv2.moveWindow("window", 0, -25)
		#cv2.imshow('window',resize_img)
		cv2.imshow("window", img)
		if cv2.waitKey(1) & 0xFF == ord('q'):
			break
		if os.path.exists('./kill.txt'):
			os.remove("./kill.txt")
			break
	cv2.destroyAllWindows()
	return 1
	
def kill_video():
	print("In kill video")
	file = open('kill.txt', 'w+')
	return 1

#def reload_page():
	

