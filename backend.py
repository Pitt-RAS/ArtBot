

class Backend:

    togui = None
    toback = None

    #Calling methods in backend should be done by pusshing the method name and any arguments it needs into it's queue as a tuple
    #If the method returns anything, be sure to take it out of the queue
    def __init__ (self, toguiqueue, tobackendqueue):
        self.togui = toguiqueue
        self.toback = tobackendqueue
        while ( True ):
            method = tobackendqueue.get()
            if ( hasattr (self, method ) ):
                call = getattr(self, method)
                try:
                    call()
                except AttributeError:
                    print("Unable to find method \"" + method + "\" in backend.py")
                    raise AttributeError #Raise the error anyway so we get traceback
            else:
                print("Backend.py does not have method\"" + method + "\"")

    def dosomething(self):
        print("Doing something")

    def getsomething(self):
        print("Pushing \"1\" to queue")
        self.togui.put(1)

    def getsomethingwithargs(self):
        one = self.toback.get(block=True)
        two = self.toback.get(block=True)
        self.togui.put(one*two)

    def operationthattakesawhile(self):
        time.sleep(5)
        self.togui.put(1)


   #Instead of keeping a local database, interface with find.pitt.edu 

def startbackend(togui, toback):
    c = Backend(togui, toback)

#Code to test this class
if __name__ == '__main__':
    import queue
    import threading
    import time

    togui = queue.Queue()
    toback = queue.Queue()

    t = threading.Thread(target=startbackend,args=(togui,toback))
    t.start()
    
    toback.put("dosomething")

    toback.put("getsomething")
    num = togui.get(block=True)
    print("Got:" + str(num))

    toback.put("getsomethingwithargs")
    toback.put(4)
    toback.put(5)
    mul = togui.get(block=True)
    print("Got:" + str(mul))

    toback.put("operationthattakesawhile")
    val = None
    while(val == None):
        if togui.empty():
            print("Waiting...")
            time.sleep(0.25) #Be sure to include a sleep so we are not "busy waiting"
        else:
            val = togui.get()
    print("Got:" + str(val))


