const int motor = 9;
const int button = 6;
const int redLED = 4;
const int yellowLED = 3;
const int greenLED = 2;

int mode = 0;
// 0: OFF
// 1: Medium
// 2: High

int motorSpd = 0;
bool redState = HIGH;
bool yellowState = LOW;
bool greenState = LOW;

void setup() {
  // put your setup code here, to run once:

  pinMode(motor, OUTPUT);
  pinMode(button, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  digitalWrite(redLED, redState);
  digitalWrite(yellowLED, yellowState);
  digitalWrite(greenLED, greenState);
  analogWrite(motor, motorSpd);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonRead = digitalRead(button);
  // HIGH: not pressed
  // LOW: pressed

  if(buttonRead == LOW){
    delay(1000);
    if(mode == 0)
      mode = 1;
    else if(mode == 1)
      mode = 2;
    else
      mode = 0;
  }

  if(mode == 0){
    redState = HIGH;
    yellowState = LOW;
    greenState = LOW;
    motorSpd = 0;
  }
  else if(mode == 1){
    redState = LOW;
    yellowState = HIGH;
    greenState = LOW;
    motorSpd = 120;
  }
  else{
    redState = LOW;
    yellowState = LOW;
    greenState = HIGH;
    motorSpd = 255;
  }

  digitalWrite(redLED, redState);
  digitalWrite(yellowLED, yellowState);
  digitalWrite(greenLED, greenState);
  analogWrite(motor, motorSpd);
}
