import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#------------------------------
# Initialized global variables
#------------------------------
number = 0

#-----------
# functions
#-----------
def setup():
    global board
    board = CustomPymata4(com_port = "COM4")
    board.displayOn()

def loop():
    global number
    board.displayShow(number) 
    number += 1
    if number > 9999:
        number = 0
    time.sleep(0.01) # Give Firmata some time to handle protocol.

#--------------
# main program
#--------------
setup()
while True:
    try:
        loop()
    except KeyboardInterrupt: # crtl+C
        print ('shutdown')
        board.shutdown()
        sys.exit(0)  