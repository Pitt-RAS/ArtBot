#!/usr/bin/python3

#Something to verify that everything needed is present
#  1. Connect to MariaDB server
#  2. Check display is present
#  3. Check IO pins are connected
#  4. Check Internet connection is avaliable
#  5. Check touchscreen is giveing inputs
#Other stuff we need to verify, but is not critical to operation
#  1. We can actually connect/scrape information about professors in benedum
class verifyer(object):

    #Stuff to check as soon as this object is created
    def __init__(self):
        pass

    #Checks we can connect to the mariaDB server
    def checkdb(self,host,username,password):
        pass

    #Checks that a display is present
    def checkdisplay(self,displaynum):
        pass

    #Checks that the IO pins are connected
    def checkio(self):
        pass

    #Checks that we can connect to the internet
    def checkinternet(self):
        pass

    #Checks we can retrive data about professors to put into our database (just because we can connect to the internet does not nessessarily mean we can populate our database)
    def checkscrape(self):
        pass

    #Check that the touchscreen is working
    def checktouchscreen(self):
        pass
