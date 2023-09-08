import time, sys
from fhict_cb_01.CustomPymata4 import CustomPymata4
from flask import Flask, render_template
from datetime import datetime 
from flask import Request,redirect
from requests import request
#--------------------------------------------------------------------------------------------------------------------------------------------
#                                                       Arduino Code
#--------------------------------------------------------------------------------------------------------------------------------------------

#-----------
# Constants
#-----------
DHTPIN  = 12 # digital pin
LDRPIN = 2 # analog pin A2

#------------------------------
# Initialized global variables
#------------------------------
humidity = 0
temperature = 0
light = 0
n = 1
average_hum = 0
average_temp = 0
average_light = 0
maximum_hum = 0
maximum_temp = 0
maximum_light = 0
minimum_hum = 1000000
minimum_temp = 1000000
minimum_light = 1000000

#-----------
# functions
#-----------
def average():
    global average_hum, average_temp, average_light, n
    average_hum = (n*average_hum + humidity)/(n+1)
    statistics["average_humidity"] = average_hum
    average_temp = (n*average_temp + temperature)/(n+1)
    statistics["average_temperature"] = average_temp
    average_light = (n*average_light + light)/(n+1)
    statistics["average_brightness"] = average_light
    n += 1

def maximum():
    global maximum_hum, maximum_temp, maximum_light
    if humidity > maximum_hum:
        maximum_hum = humidity
    statistics["maximum_humidity"] = maximum_hum
    if temperature > maximum_temp:
        maximum_temp = temperature
    statistics["maximum_temperature"] = maximum_temp
    if light > maximum_light:
        maximum_light = light
    statistics["maximum_brightness"] = maximum_light

def minimum():
    global minimum_hum, minimum_temp, minimum_light
    if humidity < minimum_hum:
        minimum_hum = humidity
    statistics["minimum_humidity"] = minimum_hum
    if temperature < minimum_temp:
        minimum_temp = temperature
    statistics["minimum_temperature"] = minimum_temp
    if light < minimum_light:
        minimum_light = light
    statistics["minimum_brightness"] = minimum_light
    
def Measure(data):
    global humidity, temperature
    if (data[3] == 0):
        humidity = data[4]
        temperature = data[5]
        LatestData["relative humidity"] = humidity
        LatestData["temperature"] = temperature

def LDRChanged(data):
    global light
    light = data[2]
    LatestData["brightness"] = light

def setup():
    global board
    board = CustomPymata4(com_port = "COM4")
    board.displayOn()
    board.set_pin_mode_dht(DHTPIN, sensor_type=11, differential=.05, callback=Measure)
    board.set_pin_mode_analog_input(LDRPIN, callback = LDRChanged, differential = 10)

def loop():
    global humidity, temperature, light
    time.sleep(0.01) 

setup()
loop()
#--------------------------------------------------------------------------------------------------------------------------------------------
#                                                   Dictionaries and Flask code
#--------------------------------------------------------------------------------------------------------------------------------------------
def current_time():
    rightNow = datetime.now()
    time = rightNow.strftime("%H:%M:%S")
    time = time.lstrip('0')
    time = time.lower()
    day = rightNow.strftime("%A")

    return time + ", " + day


app = Flask(__name__)

LatestData = {}
LatestData["sensor id"] = 319
LatestData["relative humidity"] = humidity
LatestData["temperature"] = temperature
LatestData["brightness"] = light 

statistics = {}
statistics["average_temperature"] = average_temp
statistics["average_humidity"] = average_hum
statistics["average_brightness"] = average_light

statistics["maximum_temperature"] = maximum_temp
statistics["maximum_humidity"] = maximum_hum
statistics["maximum_brightness"] = maximum_light

statistics["minimum_temperature"] = minimum_temp
statistics["minimum_humidity"] = minimum_hum
statistics["minimum_brightness"] = minimum_light


@app.route("/")     #repeated code 
def index():
        average(),maximum(),minimum()
        return render_template('index.html', statistics=statistics,
                                LatestData=LatestData,
                                time = current_time())


