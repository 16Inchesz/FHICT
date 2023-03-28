import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#-----------
# Constants
#-----------
DHTPIN  = 12 # digital pin for humidity sensor

#-----------
# functions
#-----------
def setup():
    global board
    board = CustomPymata4(com_port = "COM4")
    board.displayOn()
    board.set_pin_mode_dht(DHTPIN, sensor_type=11, differential=.05)

def loop():
    humidity, temperature, timestamp = board.dht_read(DHTPIN)
    print(humidity, temperature)
    board.displayShow(temperature)
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