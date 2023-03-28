import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#-----------
# Constants
#-----------

#------------------------------
# Initialized global variables
#------------------------------

#-----------
# functions
#-----------
def setup():
    global board
    board = CustomPymata4(com_port = "COM3")
    # Put your code here.

def loop():
    # Put your code here.
    time.sleep(0.01) # Give Firmata some time to handle the protocol.

# Put your functions here.

#--------------
# main program
#--------------
setup()
while True:
    try:
        loop()
    except KeyboardInterrupt: # Shutdown Firmata on Crtl+C.
        print ('shutdown')
        board.shutdown()
        sys.exit(0)  