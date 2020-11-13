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
 * LCD RS pin to digital pin 7 (good)
 * LCD Enable pin to digital pin 8 (good)
 * LCD D4 pin to digital pin 9 (good)
 * LCD D5 pin to digital pin 10 (good)
 * LCD D6 pin to digital pin 11 (good)
 * LCD D7 pin to digital pin 12 (good)
 * LCD R/W pin to ground (good)
 * LCD VSS pin to ground (good)
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



int buttonState;
int buttonPin = 3;
//initialize  state
volatile bool state = true;

void state_change()
{
  //TODO: switch the state of which reading to display
  //state can be set to true or false
  if(state){
    state = false;
  } else {
    state = true;
  }
  
}

void setup() {

  pinMode(3,INPUT); //takes in button input add back
  //TODO: attach an interrupt to change state when button changes from low to high
  // Use state_change for ISR
  attachInterrupt(digitalPinToInterrupt(buttonPin), state_change, RISING); //add back
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(3, 0);
  // Print the string 'Hello World!':
  lcd.print("Sophia  is");
  // Set the cursor on the third column and the second row:
  lcd.setCursor(4, 1);
  // Print the string 'LCD tutorial':
  lcd.print("Awesome!");
  
}

void loop() {

  
  lcd.setCursor(0,0);

  //Read temperature and humidity
  //TODO: Read in the temperature and humidity from the sensor
  if(state){
    DHT.read11(DHT11_PIN);
    long temp = DHT.temperature;
    if(temp > -273.15 && temp < 57 ){ //in Celcius
      lcd.clear();
      lcd.print("  Temperature");
      lcd.setCursor(0,1);
      lcd.print(temp);
      lcd.print(char(223));
      lcd.print("C     ");
      lcd.print((temp * 1.8) + 32);
      lcd.print(char(223));
      lcd.print("F");
    }
    
  }

  //TODO: Depending on the state variable, 
  //print Temperature = value of temperature or print Humidity = value of humidity reading to LCD screen
  if(!state){
    DHT.read11(DHT11_PIN);
    long humidity = DHT.humidity;
    
    if(humidity > 0){
      lcd.clear();
      lcd.print("    Humidity");
      lcd.setCursor(0,1);
      lcd.print("      ");
      lcd.print(humidity);
      lcd.print("%");
    }
    
  }
  delay(1000);
}
