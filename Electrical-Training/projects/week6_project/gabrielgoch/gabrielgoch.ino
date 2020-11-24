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

//initialize  state
volatile bool state = true;

int buttonPin = 3;

void state_change()
{  
    state = !state;
}

void setup() {

 
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), state_change, RISING);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, World!");
  delay(2000);
}

void loop() {

  
    lcd.setCursor(0,0);

    //Read sensor data
    DHT.read11(DHT11_PIN);
    long temp = DHT.temperature;
    long hum = DHT.humidity;
  
    //If button is pressed state is changed
    state_change();


    //Throw out bad values, reset display and read new data
    if( temp > -200 || hum > -200)
    {
      if (state == true)
      {
     
        lcd.clear();
        lcd.print(String("Temperature = ") + String(temp));
      }
      else if (state == false)
      {
        lcd.clear();
        lcd.print(String("Humidity = ") + String(hum));
      }
      else
      {
        lcd.clear();
        lcd.print("ERR!");
      }
    }

  delay(1000);
}
