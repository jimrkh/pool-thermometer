/*
Digital pool thermometer

*/
#include <OneWire.h>
#include <DallasTemperature.h>

#include <TM1637Display.h>

// Data wire is plugged into pin 4 on the Arduino
#define ONE_WIRE_BUS 2

// Module connection pins (Digital Pins)
#define CLK 9  //Set the CLK pin connection to the display
#define DIO 8  //Set the DIO pin connection to the display
#define DISPLAY_BRIGHTNESS 3
#define MEASUREMENT_DELAY 1000


// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire); //referenced in the future as "sensors"

// Init sensors temperature
float temperature = 0.0;

// Display object
TM1637Display display(CLK, DIO);  //set up the 4-Digit Display.


void setup()
{
  sensors.begin(); // start the DS18B20(s)
  display.setBrightness(DISPLAY_BRIGHTNESS);  //set the diplay brightness
}

void loop()
{
  sensors.requestTemperatures(); // Send the command to get temperatures
  temperature = sensors.getTempCByIndex(0); //print the temp itself

  //display.showNumberDecEx(temperature * 100, 0b11101111, false, 4, 0); //Display the Variable value;
  display.showNumberDecEx(temperature * 100, (0x80 >> 1), false); //Display the Variable value;
  delay(MEASUREMENT_DELAY);  //A delay between measurements.
}

