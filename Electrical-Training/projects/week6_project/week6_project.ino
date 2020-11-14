
#include <dht.h>

dht DHT;

#define DHT11_PIN 7

volatile bool state = true;
int buttonPin = 3;

void state_change()
{
  if(state == false)
  {
    state = true;
  }
  else
  {
    state=false;
  }
}

void setup() 
{
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(3), state_change, RISING);
  //Serial.println("Hello, World!");
}

void loop() 
{
  DHT.read11(DHT11_PIN);
  if(state == true)
  {
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("C ");
  }
  else
  {
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    Serial.print("% ");
  }
  delay(1000);
}
