from tkinter import *

LARGE_FONT=("Arial",64, "bold")

def changeText():
	myLabel.config(text="Button Clicked!")

root = Tk()

# Make the application cover the entire screen, no matter what screen we are using
w, h = root.winfo_screenwidth(), root.winfo_screenheight()
root.overrideredirect(1)
root.geometry("%dx%d+0+0" % (w, h))

root.bind("<Escape>", lambda e: e.widget.quit()) # <-- The escape key will exit the program, can be removed when implemented in pi

root.title("Test File")
myLabel = Label(root, fg = "yellow", bg = "Blue", text="Hi Mom!", font=LARGE_FONT)
myLabel.grid(row=0, column=0, rowspan=1, sticky="NEWS")

myButton = Button(root, text="Click me!", bg="Black", fg="White", bd = 10, command=changeText, font=LARGE_FONT)
myButton.grid(row=1, column=0, sticky='NEWS')


root.grid_columnconfigure(0,weight=1)
root.grid_rowconfigure(0,weight=1)
root.grid_rowconfigure(1,weight=1)


root.mainloop()