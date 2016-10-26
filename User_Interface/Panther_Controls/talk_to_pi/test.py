import serial
import time
import sys
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
while True:
	print ser.portstr
	ser.write("1")
	time.sleep(2)
