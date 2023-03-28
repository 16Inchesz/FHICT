import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#-----------
# Constants
#-----------
BUTTON1 = 8

#------------------------------
# Initialized global variables
#------------------------------
level = 0
prevLevel = 0

#-----------
# functions
#-----------
def ButtonChanged(data):
    global level
    level = data[2] # get the level
    # Keep the callback function short and fast.
    # Let loop() do the 'expensive' tasks.

def setup():
    global board
    board = CustomPymata4(com_port = "COM4")
    board.set_pin_mode_digital_input_pullup(BUTTON1, callback = ButtonChanged)
    # Note: Getting button level via callback ButtonChanged() is more 
    #       accurate for Firmata. When button is pressed or release,
    #       the ButtonChanged() function is called and this sets the 
    #       level variable.

def loop():
    global prevLevel
    # Only print button level when level changed.
    if (prevLevel != level):
        # Lets respond on button level change.
        print(level)
        prevLevel = level

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