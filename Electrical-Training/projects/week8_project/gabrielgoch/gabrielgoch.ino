//Week 8 Project
//Portable fan code

//Define digital pins
int buttonPin = 2;
int fanPin = 5;
int redLED = 10;
int greenLED = 9;
int blueLED = 8;

volatile int fanSpeed = 0;

void speedChange()
{
  fanSpeed++;
}


void setup()
{
    pinMode(buttonPin, INPUT);
    pinMode(fanPin, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(blueLED, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
  int input = digitalRead(buttonPin);


  //Code used instead of interrupt that works
  if(input == LOW)
  {
    speedChange();
  }
  
  fanSpeed = fanSpeed % 3;

  
  if(fanSpeed == 0)
  {
    //OFF
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);

    analogWrite(fanPin, 0);

  }
  else if(fanSpeed == 1)
  {
    //Half speed
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);

    analogWrite(fanPin, 140);

  }
  else if(fanSpeed == 2)
  {
    //Full speed
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);

    analogWrite(fanPin, 200);

  }
  else
  {
    //ERROR
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, HIGH);

    delay(500);

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);

    }

    Serial.println(fanSpeed);
    
    delay(1500);
}
