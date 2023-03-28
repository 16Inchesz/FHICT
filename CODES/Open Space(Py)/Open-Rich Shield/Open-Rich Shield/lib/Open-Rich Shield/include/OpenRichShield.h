#ifndef _OPENRICHSHIELD_H
#define _OPENRICHSHIELD_H

#include "TM1637Display.h"
#include "DHT.h"

TM1637Display display;
DHT dht(12, DHT11);

#endif // _OPENRICHSHIELD_H