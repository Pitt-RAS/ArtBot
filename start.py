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
modules['sqlite3'] = ['Will not be able to run','Install the sqlite3 package for python3']

#Non-standard
modules['PyQt5.QtGui'] = ['Will not be able to display','Install PyQt5 for python3(pip install pyqt5)']
modules['PyQt5.QtCore'] = ['Will not be able to display','Install PyQt5 for python3(pip install pyqt5)']
modules['PyQt5.QtWidgets'] = ['Will not be able to display','Install PyQt5 for python3(pip install pyqt5)']

#Our code
modules['mainwindow.py'] = ['Will be unable to start','Make sure you have all the code, and it is in the correct directory']

#Load all the modules we need
for mod in modules:
    try:
        importlib.import_module(mod)
    except:
        print("Failed to load module:",mod)
        print(modules[mod][0])
        print(modules[mod][1])

#Start the backend on a different thread than the display.
#Won't actually run faster due to GIL, but makes it easy to decouple graphics and processing

