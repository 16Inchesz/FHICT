import time, sys, requests
from fhict_cb_01.CustomPymata4 import CustomPymata4

BUTTON1 = 8

level = 0
prevLevel = 0

url_deliver = "http://145.93.120.150:5000/deliver"

def ButtonChanged(data):
    global level
    level = data[2]

board = CustomPymata4(com_port="COM3")
board.set_pin_mode_digital_input_pullup(8, callback=ButtonChanged)

def loop():
    global prevLevel
    if (prevLevel != level):
        if (level == 0):
            requests.post(url_deliver)
        prevLevel = level

while True:
    try:
        loop()
    except KeyboardInterrupt:
        print ('shutdown')
        board.shutdown()
        sys.exit(0)