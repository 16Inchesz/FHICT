import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#Variables
prevlevel1 = 0
prevlevel2 = 0
counter = 0

#-----------
# Constants
#-----------
DHTPIN  = 12 # digital pin
LDRPIN = 2 # analog pin A2
BUTTONS = [8,9]

#------------------------------
# Initialized global variables
#------------------------------
humidity = 0
temperature = 0
light = 0

#functions 
def ButtonChanged(data):
    global level
    level = data[2]

def Measure(data):
    global humidity, temperature
    if (data[3] == 0): 
        humidity = data[4]
        temperature = data[5]

def LDRChanged(data):
    global light
    light = data[2]

def setup():
    global board
    board = CustomPymata4(com_port="COM4")
    for button in BUTTONS:
        board.set_pin_mode_digital_input_pullup(button, callback=ButtonChanged)
    #board.displayOn()
    board.set_pin_mode_dht(DHTPIN, sensor_type=11, differential=.05, callback=Measure)
    board.set_pin_mode_analog_input(LDRPIN, callback = LDRChanged, differential = 10)

def loop():
    global prevlevel1, prevlevel2, humidity, temperature, light, counter
    print(temperature, humidity, light)
    button1 = BUTTONS[0]
    button2 = BUTTONS[1]
    level1 = board.digital_read(button1)[0]
    level2 = board.digital_read(button2)[0]  
    if (level1 != prevlevel1):
        prevlevel1 = level1
        if (prevlevel1 == 0):
            if (counter == 0):
                board.displayShow(temperature)
                counter += 1
            elif (counter == 1):
                board.displayShow(humidity)
                counter += 1
            elif (counter == 2):
                board.displayShow(light)
                counter -= 2

    if (level2 != prevlevel2):
        prevlevel2 = level2
        if (prevlevel2 == 0):
            if (counter == 0):
                board.displayShow(temperature)
                counter += 1
            elif (counter == 1):
                board.displayShow(humidity)
                counter += 1
            elif (counter == 2):
                board.displayShow(light)
                counter -= 2

    
    time.sleep(0.1)


setup()
while True:
    try:
        loop()
    except KeyboardInterrupt: #ctrol+C
        print ('shutdown')
        board.shutdown()
        sys.exit(0)