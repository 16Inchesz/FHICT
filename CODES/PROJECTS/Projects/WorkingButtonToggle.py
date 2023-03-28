import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4

#Variables
prevlevel1 = 0
prevlevel2 = 0
led_state = 0
led_state = 0

LEDS = [4,5,6,7]
BUTTONS = [8,9]

#functions 
def ButtonChanged(data):
    global level
    level = data[2]

def setup():
    global board
    board = CustomPymata4(com_port="COM4")
    for button in BUTTONS:
        board.set_pin_mode_digital_input_pullup(button, callback=ButtonChanged)
    for pin in LEDS:
        board.set_pin_mode_digital_output(pin)


def loop():
    global prevlevel1, prevlevel2, led_state
    for button in BUTTONS:
        button1 = BUTTONS[0]
        button2 = BUTTONS[1]
    level1 = board.digital_read(button1)[0]
    level2 = board.digital_read(button2)[0]
    if (level1 != prevlevel1):
        prevlevel1 = level1
        if (prevlevel1 == 0):
            if led_state != 1:
                led_state += 1
            else:
                led_state -= 1
            for pin in LEDS:
                board.digital_pin_write(pin,led_state)
    
    if (level2 != prevlevel2):
        prevlevel2 = level2
        if (prevlevel2 ==0):
            if led_state != 1:
                led_state += 1
            else:
                led_state -= 1
            for pin in LEDS:
                board.digital_pin_write(pin,led_state)
    
    time.sleep(0.02)


setup()
while True:
    try:
        loop()
    except KeyboardInterrupt: #ctrol+C
        print ('shutdown')
        board.shutdown()
        sys.exit(0)