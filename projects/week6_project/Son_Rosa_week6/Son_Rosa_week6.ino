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
 */

// include the library code:
#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 2

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// trash variables
int temp_bad = 0;
int humidity_bad = 0;
int temp_good = 0;
int humidity_good = 0;

//initialize  state
volatile bool state = true;

int buttonState;
int buttonPin = 3;


void state_change()
{
  //TODO: switch the state of which reading to display
  //state can be set to true or false

  if (state == true) {
    state = false;
  }
  else if (state == false) {
    state = true;
  }
 
}

void setup() {

  
  //TODO: attach an interrupt to change state when button changes from low to high
  // Use state_change for ISR
  attachInterrupt(digitalPinToInterrupt(buttonPin), state_change, RISING);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, World!");
  Serial.begin(9600);
}

void loop() {
int button = digitalRead(buttonPin);
  Serial.println(button);
  Serial.println(state);
  lcd.setCursor(0,0);

  //Read temperature and humidity
  DHT.read11(DHT11_PIN);

  //TODO: Read in the temperature and humidity from the sensor
  long temp = DHT.temperature;
  long humidity = DHT.humidity;

  //TODO: Depending on the state variable, 
  //print Temperature = value of temperature or print Humidity = value of humidity reading to LCD screen
  if (state == 0) {
    if (temp != -999) {
      temp_good = temp;
  }
  else if (temp = -999) {
    temp_bad= temp;
  }
   lcd.print("Temperature = ");
    lcd.print(temp_good);
  }
  else if (state == 1) {
    if (humidity != -999) {
    humidity_good = humidity;
  }
  else if (humidity = -999) {
    humidity_bad = humidity;
  }
  lcd.print("Humidity = ");
    lcd.print(humidity_good);
  }
  delay(1000);
  lcd.clear();
}
