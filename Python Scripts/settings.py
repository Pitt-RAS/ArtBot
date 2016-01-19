#start.py should have already included all the libraries we need
#Parses a files, lines should be constructed
#  setting_name=setting_value
#  Lines starting with a '#' should be ignored
#  There will one and only one  '=' per line
#  Lines may have a # after the setting
#  Lines may start with whitespace before #
#  Lines may be empyty
class settings(object):
    set = {}

    #Should create a default settings file if it does not exist, and load it
    def __init__(self):
        pass

    #Should open a file, and load all settings into set
    def openfile(self,filename):
        lexer = shlex.shlex(open('settingsrc','rt').read())

        #Each setting needs: a type, a name, and a string that gets parsed according to the type
        #The string can also be nested
        for token in lexer:


    #Should save the file, with the appropriate changes, without modifying any lines start with '#'
    def savefile(self,filename):
        pass

def parsetype(type, value):
    if(type == 'string'):
        return value
    else if(type == 'number'):
        return float(value)

#datatypes
if __name__ == '__main__':
    import shlex
    import sys


    body = open("settingsrc",'rt').read()

    lexer = shlex.shlex(body)
    dtype = None
    name = None
    value = None
    for token in lexer:
        if(dtype == None):
            dtype = token
        else if(name == None):
            name = token
        else if(value == None):
            value = token
        else:
            set
