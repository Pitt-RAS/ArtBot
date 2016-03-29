from bottle import route, run, static_file
from face_video import panther_video

#return variable??? parse file names into HTML?

@route('/hello')
def hello():
    return "Hello World!"
	
@route('/camera')
def camera():
	panther_video()
	return "Success"

@route('/static/<filename:path>')
def send_static(filename):
    return static_file(filename, root='./')	
	
run(host='localhost', port=8080, debug=True)