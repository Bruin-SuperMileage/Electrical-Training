
int time_start = 0;
int red_led = 10;
int yellow_led = 11;
int green_led = 6;
int motor = 9;
int buttonState;
int buttonPin = 2;
volatile bool state = true;
volatile int n = 2;




void setup() {
  // put your setup code here, to run once:
// TODO: Initialize pins for potentiometer, 2 LEDs (PWM is optional), 
  //       and transistor control (PWM). Please use D3 as button.
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(motor, OUTPUT);
  
  
}

void loop() {
    int button_press = digitalRead(2); // Reads LOW if pressed, HIGH if not pressed
  int time_elapsed = millis() - time_start;
  if (button_press == LOW && time_elapsed >= 1000) {
    time_start = millis();
  
if (state && n == 1)
{ 
  state = false;
 
 
    n = 2;
}
else if (!state && n == 2)
{
  state = true;
  
   n = 0;
}
else 
{
  state = true;
   n = 1;
}
  }





  if (state && n == 1)
{ 
  
 
 analogWrite(yellow_led, 0);
  analogWrite(red_led, 100);
    analogWrite(green_led, 0);
   analogWrite(motor, 0);
    
}
else if (!state && n == 2)
{
  analogWrite(yellow_led, 100);
  analogWrite(red_led, 0);
   analogWrite(green_led, 0);
  analogWrite(motor, 60);
  
}
else 
{
 
  analogWrite(yellow_led, 0);
  analogWrite(red_led, 0);
   analogWrite(green_led, 100);
  analogWrite(motor, 128);
  
}
  

} 
