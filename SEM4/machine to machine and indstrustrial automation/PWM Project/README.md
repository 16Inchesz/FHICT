Monarco HAT reading Ultrasonic Sensor 
=====================================
 
This folder contains the source files for the demonstration project on using
REXYGEN on the Raspberry Pi minicomputer with the Monarco HAT add-on board. 

In this example the Monarco HAT is reading Ultrasonic Sensor via analog input.

The measured temperature and status of the output is recorded in the TRND blocks   
which allow displaying of the trends (graphs). 

## Timing of the project ##

The algorithm runs each 2 milliseconds (0.002 s). See the EXEC function block,  
tick x ntick0 = 0.002 x 1 = 0.002 s.

## Prerequisites ##

- *REXYGEN Runtime Core* and *MonarcoDrv* modules must be installed and running 
on the Raspberry Pi.

## Running the example ##

- The **exec.mdl* file is the project main file, open it with *REXYGEN Studio*.
- Compile and download the project to the target device.
- Switch to *Watch mode* and observe the algorithm (use Target->Watch Selection 
to display real-time data).
   
## Documentation ##

- **Press F1 for help** on the selected function block in the *REXYGEN Studio*.
- [Getting started with REXYGEN and Monarco HAT (Raspberry Pi)](https://www.rexygen.com/doc/PDF/ENGLISH/RexygenGettingStarted_MonarcoHAT_RPi_ENG.pdf)
- [MonarcoDrv - Monarco HAT driver](https://www.rexygen.com/doc/PDF/ENGLISH/MonarcoDrv_ENG.pdf)
- [REXYGEN Studio User Guide](https://www.rexygen.com/doc/PDF/ENGLISH/RexygenStudio_ENG.pdf)
- [Function blocks of REXYGEN](https://www.rexygen.com/doc/PDF/ENGLISH/BRef_ENG.pdf)

## Additional information ##

- YouTube [demonstration video](https://youtu.be/PM-YciPq2FA).
- Visit the [Monarco HAT website](http://www.monarco.io).
- Raspberry Pi is a trademark of the [Raspberry Pi Foundation](http://www.raspberrypi.org).
- Visit the [REXYGEN webpage](http://www.rexygen.com) 
for more information about the example projects and developing advanced 
automation and control solutions using REXYGEN.