import time, sys, requests
from fhict_cb_01.CustomPymata4 import CustomPymata4

BUZZER = 3
REDLED = 4
GREENLED = 5
BUTTON1 = 8
BUTTON2 = 9

level = 0
prevLevel = 0
level2 = 0
prevLevel2 = 0

readyL = []
readyNum = 0

countdown = 5
id = 1

timers = []

url_status = "http://145.93.102.94:5000/status"
url_oven =   "http://145.93.102.94:5000/oven"

def ButtonChanged(data):
    global level
    level = data[2]

def ButtonChanged2(data):
    global level2
    level2 = data[2]

board = CustomPymata4(com_port="COM3")
board.set_pin_mode_digital_output(REDLED)
board.set_pin_mode_pwm_output(BUZZER)
board.set_pin_mode_digital_input_pullup(8, callback=ButtonChanged)
board.set_pin_mode_digital_input_pullup(9, callback=ButtonChanged2)
board.set_pin_mode_pwm_output(BUZZER)

def loop():
    global prevLevel, countdown, readyL, timers, id, readyNum
    countdown = 10
    
    id2 = id
    data = {'pizza_id': id2}

    if (len(timers) > 0 and len(timers) < 3):
        while (timers[0] > 0):
            if (prevLevel != level):
                timers.append(10 - timers[0])
                id2 += 1
                data = {'pizza_id': id2}
                time.sleep(0.5)
                requests.post(url_oven, json = data)
                prevLevel = level
            board.displayShow(timers[0])
            board.digital_pin_write(REDLED, 1)
            board.digital_pin_write(GREENLED, 0)
            print("Time:",timers)
            timers[0] -= 1
            time.sleep(1)  
        readyL.append(1) 
        # print(ready)   
        timers.pop(0)
        board.digital_pin_write(REDLED, 0)
        board.digital_pin_write(GREENLED, 1)
        board.pwm_write(BUZZER,1)
        time.sleep(0.5)
        board.pwm_write(BUZZER,0) 
    
    if (prevLevel != level ): 
        if (level == 0):
            timers.append(10)
            requests.post(url_oven, json = data)
        prevLevel = level

    if (prevLevel2 == level2):
        id = id2
        data = {'pizza_id': id}
        if (len(readyL) > 0):
            print("Pizza is ready")
            requests.post(url_status, json = data)
            time.sleep(1)
            id += 1
            readyL.pop(0)
        else:
            print("Pizza not ready")
            time.sleep(1)
        ready = False
    if (len(readyL) == 0):
        id = 1
        id2 = 1
        
while True:
    try:
        loop()
    except KeyboardInterrupt:
        print ('shutdown')
        board.shutdown()
        sys.exit(0)