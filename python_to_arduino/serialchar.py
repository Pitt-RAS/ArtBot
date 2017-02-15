#sends single char to arduino
import serial
import time

arduino = serial.Serial("/dev/cu.usbmodem1411", 9600)

time.sleep(5) #wait for board to reset
print "Sending serial data"

while True :
    arduino.write("r")
    arduino.write("y")
    arduino.write("g")

#arduino.close(); #use to end connection

