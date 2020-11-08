// These variables are used for your state machine
int time_start = 0;
int state = 0;
int GREEN_LED = 9;
int RED_LED = 4;
int Motor_PIN = 5;


void setup() {
  // TODO: Initialize pins for potentiometer, 2 LEDs (PWM is optional), 
  //       and transistor control (PWM). Please use D3 as button.
  Serial.begin(9600);
  pinMode(3,INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(Motor_PIN, OUTPUT);
  
}

void loop() { 
  // ================================================
  // DO NOT TOUCH THIS SECTION OF CODE
  // Implementation of state machine with software button debouncing
  int button_press = digitalRead(3); // Reads LOW if pressed, HIGH if not pressed
  int time_elapsed = millis() - time_start;
  int y_position = analogRead(A0);
  int motor_speed = 0;
  // Change states only if 1 second has passed (this prevents multiple state changes from one press)
  // Long presses can change states multiple times if held down for more than one second.
  if (button_press == LOW && time_elapsed >= 1000) {
    time_start = millis();
    if (state == 0) {
      state = 1;
      Serial.println("ON");
    }
    else {
      state = 0;
      Serial.println("OFF");
    }
  }
  // DO NOT TOUCH ABOVE SECTION OF CODE
  // ================================================


  // TODO: Using the state variable given, create a program that meets all project specifications
  //       The conditional statements are written for you.

  

  if (state == 0) {
    // TODO: Things that should happen if the state is "off"
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    motor_speed = 0;

    
    
  }

  else if (state == 1) {
    // TODO: Things that should happen if the state is "on"
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    motor_speed = map(y_position, 0, 1023, -255, 255);

    
  }

  else {
    // If this occurs, you touched code that should have not been touched
    Serial.println("The state code already written is to avoid using a debouncing circuit");
    Serial.println("The reason we didn't make one is because your kit does not have a capacitor");
  }

  if(motor_speed < 0){
    motor_speed = -motor_speed;
  }
  
  analogWrite(Motor_PIN, motor_speed);

}
