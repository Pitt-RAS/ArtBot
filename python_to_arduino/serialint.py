#sends int to arduino
import serial
import time

arduino = serial.Serial("/dev/cu.usbmodem1411", 9600)

time.sleep(5) #wait for board to reset
print "Sending serial data"

while True :
    arduino.write("1")
    time.sleep(1)
    arduino.write("2")
    time.sleep(1)
    arduino.write("3")
    time.sleep(1)

#arduino.close(); #use to end connection

