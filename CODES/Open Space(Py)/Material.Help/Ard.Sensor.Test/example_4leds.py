import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#-----------
# Constants
#-----------
LED_PINS = [4,5,6,7]

#-----------
# functions
#-----------
def setup():
    global board
    board = CustomPymata4(com_port = "COM4")
    for pin in LED_PINS:
        board.set_pin_mode_digital_output(pin)

def loop():
    for pin in LED_PINS:
        board.digital_pin_write(pin, 1)
        time.sleep(0.5)
        board.digital_pin_write(pin, 0)
        time.sleep(0.5)

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