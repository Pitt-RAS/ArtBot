#start.py should have already included all the libraries we need
#Parses a files, lines should be constructed
#  setting_name=setting_value
#  Lines starting with a '#' should be ignored
#  There will one and only one  '=' per line
class settings(object):
    set = {}

    #Should create a default settings file if it does not exist, and load it
    def __init__(self):
        pass

    #Should open a file, and load all settings into set
    def openfile(self,filename):
        pass

    #Should save the file, with the appropriate changes, without modifying any lines start with '#'
    def savefile(self,filename):
        pass
