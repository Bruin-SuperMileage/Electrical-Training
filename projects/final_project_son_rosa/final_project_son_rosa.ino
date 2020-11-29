// Final Project SMV Electrical Training
// Create a fan with three settings: Off, Low, High
// Utilize an interrupt and three LEDS to indicate which setting you are on

// Variables
int LED_OFF = 8;
int LED_LOW = 10;
int LED_HIGH = 12;

int ButtonPin = 3; 
int state = 0;

void state_change() {
if (state == 0) {
  state = 1;
}
else if (state == 1) {
  state = 2;
}
else if (state == 2) {
  state = 0;
}
}
  


void setup() {
Serial.begin(9600);
pinMode(LED_OFF, OUTPUT);
pinMode(LED_LOW, OUTPUT);
pinMode(LED_HIGH, OUTPUT);
pinMode(5, OUTPUT); //motor pin

attachInterrupt(digitalPinToInterrupt(ButtonPin),state_change, RISING);
 
}


void loop() { 


// delay(3000);

if (state == 0) {
  digitalWrite(LED_OFF, HIGH);
  digitalWrite(LED_LOW, LOW);
  digitalWrite(LED_HIGH, LOW);
 analogWrite(5, 0);
  
}

else if (state == 1) {
  digitalWrite(LED_OFF, LOW);
  digitalWrite(LED_LOW, HIGH);
  digitalWrite(LED_HIGH, LOW);
  analogWrite(5, 192);
}
else if (state == 2) {
  digitalWrite(LED_OFF, LOW);
  digitalWrite(LED_LOW, LOW);
  digitalWrite(LED_HIGH, HIGH);
  analogWrite(5, 255);
}
Serial.println(state);
}
