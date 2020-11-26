
#define RED_LED 5
#define YELLOW_LED 6
#define GREEN_LED 7

 #define MOTOR 10

 #define YELLOW_BUTTON 12
 #define GREEN_BUTTON 13

 int motor_speed = 0;

void setup() {
  Serial.begin(9600);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  pinMode(MOTOR, OUTPUT);

  pinMode(YELLOW_BUTTON, INPUT);
  pinMode(GREEN_BUTTON, INPUT);

}

void loop() {

  bool yellow_button_press = !digitalRead(YELLOW_BUTTON); //reversed since it's a pull-up
  bool green_button_press = !digitalRead(GREEN_BUTTON);

  if (yellow_button_press && !green_button_press) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);    
    analogWrite(MOTOR, 500);
  } else if (green_button_press && !yellow_button_press) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);  
    analogWrite(MOTOR, 1000);  
  } else { //if you're pressing both (don't do that!) or neither, it will be stopped
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    analogWrite(MOTOR, 0);
  }
  delay(1000);
}
