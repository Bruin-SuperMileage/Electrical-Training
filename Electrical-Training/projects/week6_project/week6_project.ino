
#include <dht.h>

dht DHT;

#define DHT11_PIN 7

volatile bool state = true;
int buttonPin = 3;
int loops = 0;

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
  if(state == true && loops % 2 == 0)
  {
    Serial.print("Temperature = ");
    Serial.print(DHT.temperature);
    Serial.println("C ");
  }
  else if(state == false && loops % 2 == 0)
  {
    Serial.print("Humidity = ");
    Serial.print(DHT.humidity);
    Serial.println("% ");
  }
  loops++;
  delay(1000);
}
