import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#-----------
# Constants
#-----------
BUTTON1PIN = 8
REDLEDPIN = 4


#-----------
# functions
#-----------
def setup():
    global board
    board = CustomPymata4(com_port = "COM4")
    board.set_pin_mode_digital_input_pullup(BUTTON1PIN) # set pin to input pullup
    board.set_pin_mode_digital_output(REDLEDPIN)

def loop():
    level, time_stamp = board.digital_read(BUTTON1PIN)
    print (level)

    if (level == 0):
        board.digital_pin_write(REDLEDPIN, 1)
    else:
        board.digital_pin_write(REDLEDPIN, 0)
        
    time.sleep(0.01) # Give Firmata some time to handle protocol.

    # value = board.digital_read(8)
    # print(value) # returns a list of level and
    # option 1: 
    # level = board.digital_read(8)[0]
    # option 2:
    # level, time_stamp = board.digital_read(8)

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