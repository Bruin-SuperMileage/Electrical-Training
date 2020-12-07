#define lowPin 2
#define medPin 3
#define highPin 4

int setting = 0;

void changeSetting()
{
  setting = setting + 1;
  if (setting == 3)
  {
    setting = 0;
  }
  
}

void setup() {
    // put your setup code here, to run once:
    // initialize pins
    
    pinMode(11, OUTPUT);
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    pinMode(8, INPUT_PULLUP);
}


void loop() {
  // put your main code here, to run repeatedly:
  
  // read button pin
  if (digitalRead(8) == 0)
  {
    // call setting change function 
    changeSetting();
  
    // light up correct LEDs
    // output motor current

    if (setting == 0)
    {
        digitalWrite(lowPin, HIGH);
        digitalWrite(medPin, LOW);
        digitalWrite(highPin, LOW);

        analogWrite(11, 0);
    }
    else if (setting == 1)
    {
        digitalWrite(lowPin, LOW);
        digitalWrite(medPin, HIGH);
        digitalWrite(highPin, LOW);

        analogWrite(11, 128);
    }

    else
    {
        digitalWrite(lowPin, LOW);
        digitalWrite(medPin, LOW);
        digitalWrite(highPin, HIGH);

        analogWrite(11, 255);
    }

    delay(1000);

  }


}