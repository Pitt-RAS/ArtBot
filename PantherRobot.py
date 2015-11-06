import tkinter as tk
import sys

LARGE_FONT=("Arial",64, "bold")

#Main class
class PantherRobot(tk.Tk):	
	#args are arguments, kwargs are dictionaries
	def __init__(self, *args, **kwargs):
		
		tk.Tk.__init__(self, *args, **kwargs)
		container = tk.Frame(self)
		
		#container.pack(side="top", fill="both", expand = True)
		container.grid()
		
		#container.grid_rowconfigure(0, weight=1)
		#container.grid_rowconfigure(1, weight=1)
		#container.grid_columnconfigure(0, weight=1)		
		
		self.frames = {}	#<-- Dictionary to hold all our frames
		
		#We have to add all our frames to the dictionary
		for F in (MainMenu, PageOne):
			frame = F(container, self)
			self.frames[F] = frame
			frame.grid(row=0, column=0, sticky='NSEW')
		
		#Call the Main Menu when the program first starts running
		self.show_frame(MainMenu)
		
	#Raise the passed in frame to the front
	def show_frame(self, controller):
	
		frame = self.frames[controller]
		frame.tkraise()
		
#Main menu 
class MainMenu(tk.Frame):	#<-- inherits everything from frame
	
	def __init__(self, parent, controller):
		tk.Frame.__init__(self, parent)
		#self.grid_columnconfigure(0,weight=1)
		#self.grid_rowconfigure(0,weight=1)
		#self.grid_rowconfigure(1,weight=1)
		
		label = tk.Label(self, text="Hello World", font=LARGE_FONT)
		label.grid(row = 0, column = 0, rowspan = 1)
		
		#lambda basically works as a link between Tkinter and the callback function
		button1= tk.Button(self, text="Click me!", font=LARGE_FONT, command=lambda: controller.show_frame(PageOne))
		button1.grid(row=1, column = 0, sticky = "NSEW")
		

#Page One, just a test here
class PageOne(tk.Frame):
	
	def __init__(self, parent, controller):
		tk.Frame.__init__(self, parent)
		self.grid_columnconfigure(0,weight=1)
		self.grid_rowconfigure(0,weight=1)
		self.grid_rowconfigure(1,weight=1)
		
		label = tk.Label(self, text="PageOne!!", font=LARGE_FONT)
		label.grid(row = 0, column = 0, rowspan = 1)
		
		#Return to Main Menu
		button1= tk.Button(self, text="Back to Main!", font=LARGE_FONT, command=lambda: controller.show_frame(MainMenu))	
		button1.grid(row=1, column = 0)
		

#For exiting the program
def close(event):
    sys.exit()
	

#Create our application and start running it
Roc = PantherRobot()

# Make the application cover the entire screen, no matter what screen we are using
w, h = Roc.winfo_screenwidth(), Roc.winfo_screenheight()
Roc.overrideredirect(1)
Roc.geometry("%dx%d+0+0" % (w, h))

Roc.grid_columnconfigure(0,weight=1)
Roc.grid_rowconfigure(0,weight=1)
Roc.grid_rowconfigure(1,weight=1)

print (Roc.grid_size())
Roc.bind('<Escape>', close)		#<-- Escape key is now bound to exiting the program
Roc.mainloop()

