# This will blink the builtin LED of the Arduino UNO
# for as long as the Python program runs

# Run the program without the Rich Shield so that you can see the LED
# hit <CTRL> + C to interrupt
# you may need to change the port
import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#-----------
# Constants
#-----------
BUILTIN_LED = 13
DELAY = 1 # seconds

#-----------
# functions
#-----------
def setup():
    global board
    #create a PyMata instance, change to your port as needed
    board = CustomPymata4(com_port = "COM4")
    #setup the builtin LED pin to output
    board.set_pin_mode_digital_output(BUILTIN_LED)

def loop():
    board.digital_write(BUILTIN_LED, 1)
    time.sleep(DELAY)
    board.digital_write(BUILTIN_LED, 0)
    time.sleep(DELAY)

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

  
#use ctrl+C to come out of the program
