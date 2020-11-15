#include <dht.h>

//www.elegoo.com
//2016.12.9

/*
  LiquidCrystal Library - Hello World
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 This sketch prints "Hello World!" to the LCD
 and shows the time.
  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
Tip #1: How to get data from the DHT
Use the library on the main project trello card.
You can gather information from the DHT by utilizing DHT.read11(DHT11_PIN).
Access temperature or humidity by assigning DHT.temperature or DHT.humidity to a variable.
Ex: 
DHT.read11(DHT11_PIN)
long temp = DHT.temperature;

Tip #2: How to wire the DHT is on this trello card. NOTE: Please use pin 2 for your DHT input wire (instead of pin 7).

Tip #3: If the data from the DHT is garbage sometimes (-999 degrees Celsius), throw it out and wait for the next iteration of reading before updating the current value.
 */

// include the library code:
#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 5

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//initialize  state
volatile bool state = true;

int buttonState;
int buttonPin = 3;

void state_change()
{
  if (state == true) {
    state = false;
  }
  if (state == false) {
    state = true;
  }
  //TODO: switch the state of which reading to display
  //state can be set to true or false
}

void setup() {
  //TODO: attach an interrupt to change state when button changes from low to high
  // Use state_change for ISR
  /*
  attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)
  ISR = your function/interrupt service routine
   */
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(3), state_change, RISING);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, World!");
}

void loop() {

  
  lcd.setCursor(0,0);

  //Read temperature and humidity
  //TODO: Read in the temperature and humidity from the sensor
  DHT.read11(DHT11_PIN);
  long temp = DHT.temperature;
  long hum = DHT.humidity;
  //TODO: Depending on the state variable, 
  //print Temperature = value of temperature or print Humidity = value of humidity reading to LCD screen
  if (state == false) {
   // string stemp = "Temperature = " + temp;
    lcd.print("Temperature = " + temp);
    Serial.println("Temperature: "+temp);
  }
  else {
    lcd.print("Humidity = " + hum);
    Serial.println("Humidity: " +hum);
  }
  delay(2000);
}
