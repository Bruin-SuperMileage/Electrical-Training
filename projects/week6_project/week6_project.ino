//week6 changes 


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

//initialize  state voltatile
volatile bool state = true;

int buttonState;
int buttonPin = 3;

void state_change()
{
  
  //TODO: switch the state of which reading to display
  //state can be set to true or false
  if (state)
  { //display temp
    state = false;
     
  }
  else
  { //display hum
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
  lcd.print("hi");
  
}

void loop() {

  
  lcd.setCursor(0,0);

  //Read temperature and humidity
  //TODO: Read in the temperature and humidity from the sensor
    DHT.read11(DHT11_PIN);
  float temp =  DHT.temperature;
  float hum = DHT.humidity;
 
  //TODO: Depending on the state variable, 
  //print Temperature = value of temperature or print Humidity = value of humidity reading to LCD screen
  if (state)
  {
    
    if (hum > -999)
    {
      lcd.print("Hum = ");
    lcd.print(hum);
    }
  }
 else
 {
 
  if (temp >-999)
  {
    lcd.print("temp = ");
  lcd.print(temp);
  }
 }
    
  
  delay(1000);
}
