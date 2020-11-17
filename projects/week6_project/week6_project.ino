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

int buttonState;
int buttonPin = 3;

float temp = 0;
float humidity = 0;



void state_change()
{
  state = !state;
}

void setup() {

  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  //TODO: attach an interrupt to change state when button changes from low to high
  // Use state_change for ISR
  attachInterrupt(digitalPinToInterrupt(buttonPin), state_change, RISING);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, World!");
  
}

void loop() {


  
 
  //lcd.print("Hello, World!");
 
 

DHT.read11(DHT11_PIN);


  if(DHT.temperature > -900){
    temp = DHT.temperature;
  }

    if(DHT.humidity > -900){
    humidity = DHT.humidity;
  }
  
  //Serial.print(digitalRead(DHT.temperature));
  //Serial.print(" ");
  //Serial.println(DHT.humidity);
  //Read temperature and humidity
  //TODO: Read in the temperature and humidity from the sensor
   lcd.setCursor(0,0);
   if(state == true){
        lcd.print("Current Temp:          ");
        lcd.setCursor(0,1);
        lcd.print(temp);
        lcd.print(" Degrees                ");
   }
   if(state == false) {
        lcd.print("Current Humidity:      ");
        lcd.setCursor(0,1);
        lcd.print(humidity);
        lcd.print(" %                     ");
   }
     
        

  //TODO: Depending on the state variable, 
  //print Temperature = value of temperature or print Humidity = value of humidity reading to LCD screen
  
  delay(1000);
}
