#!/usr/bin/python3
import importlib
#######
##  The init script, after starting, this should start all other services
#######

#Check that all the libraires we need are here
#describe what will happen if a library is not loaded, and how to fix it
modules = {}

#Standard
modules['sys'] = ['Will not be able to run','Every python interpreter should have this']
modules['os'] = ['Will not be able to run','Every python interpreter should have this'] 
modules['queue'] = ['Will not be able to run', 'Every python interpreter should have his']
modules['threading'] = ['Will not be able to run','Every python interpreter should have this']
modules['time'] = ['Will not be able to run', 'Every python interpreter should have this']
modules['shlex'] = ['Will not be able to run','Every python interpreter should have this']

#Non-standard
modules['PyQt5.QtGui'] = ['Will not be able to display','Install PyQt5 for python3(pip install pyqt5)']
modules['PyQt5.QtCore'] = ['Will not be able to display','Install PyQt5 for python3(pip install pyqt5)']
modules['PyQt5.QtWidgets'] = ['Will not be able to display','Install PyQt5 for python3(pip install pyqt5)']

#Our code
modules['mainwindow.py'] = ['Will be unable to start','Make sure you have all the code, and it is in the correct directory']
modules['backend.py'] = ['Will be unable to start', 'Make sure you have all the code, and it is in the correct directory']

#Load all the modules we need
failed = False
for mod in modules:
    try:
        importlib.import_module(mod)
    except:
        failed = True
        print("Failed to load module:",mod)
        print(modules[mod][0])
        print(modules[mod][1])

#Don't continue if we failed to load something
if(failed):
    exit()

#Start the backend on a different thread than the display, in order to keep the display responsive even while we are doing processor intensive stuff
#Won't actually run faster, but makes it easy to decouple graphics and processing

#Create a pair of queues so that the graphics and gui threads can communicate
togui = queue.Queue()
tobackend = queue.Queue()

def startgui():
    pass


