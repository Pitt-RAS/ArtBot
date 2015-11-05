#!/usr/bin/python3
import tkinter as tk

class MainWindow(tk.Frame):
    def callablefunction(self):
        print("You called me!")

    def createWidgets(self):
        self.quitbutton = tk.Button(self,text="X",command=self.quit,height=20,width = 10)
        self.functionbutton = tk.Button(self, text="Press me!",command=self.callablefunction,height=1,width=10)
        self.quitbutton.grid(column=1, row=5)
        self.functionbutton.grid(column=2,row=5)

    def __init__(self, master=None):
        tk.Frame.__init__(self,master)
        self.grid()
        self.createWidgets()

if __name__ == '__main__':
    win = MainWindow()
    win.mainloop()

