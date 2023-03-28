import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#-----------
# Constants
#-----------
POTPIN = 0 # analog pin A0

#------------------------------
# Initialized global variables
#------------------------------
value = 0

#-----------
# functions
#-----------
def PotChanged(data):
    global value
    value = data[2]
    #print(data)

def setup():
    global board
    board = CustomPymata4(com_port = "COM4")
    board.set_pin_mode_analog_input(POTPIN, callback = PotChanged, differential = 10)
    # Note: The differential defines the distance between the previous 
    #       and current value. If the difference is greater dan differential 
    #       then PotChange() is called. This solution reduces noise.

def loop():
    global value
    print (value)

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