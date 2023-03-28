import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#-----------
# Constants
#-----------
LDRPIN = 2 # analog pin A2

#-----------
# functions
#-----------
def setup():
    global board
    board = CustomPymata4(com_port = "COM4")
    board.set_pin_mode_analog_input(LDRPIN)

def loop():
    value, timestamp = board.analog_read(LDRPIN)
    print(value)

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