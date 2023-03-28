import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#-----------
# Constants
#-----------
BUZZER = 3

#------------------------------
# Initialized global variables
#------------------------------

#-----------
# functions
#-----------
def setup():
    global board
    board = CustomPymata4(com_port = "COM4")
    board.set_pin_mode_pwm_output(BUZZER)

    # Put your code here.

def loop():
    board.pwm_write(BUZZER,1)
    time.sleep(0.5)
    board.pwm_write(BUZZER,0)
    time.sleep(0.5)
    
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