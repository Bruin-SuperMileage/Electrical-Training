// These variables are used for your state machine
int time_start = 0;
int state = 0;

void setup() {
  // TODO: Initialize pins for potentiometer, 2 LEDs (PWM is optional), 
  //       and transistor control (PWM). Please use D3 as button.
  Serial.begin(9600);
  pinMode(3,INPUT); //button (D)
  pinMode(4,OUTPUT); //led 1 (RED/OFF)
  pinMode(2,OUTPUT); //led 2 (GREEN/ON)
  pinMode(A0,INPUT); //potentiometer (A)
  pinMode(9,OUTPUT); //motor(A)
  

  
}

void loop() { 
  // ================================================
  // DO NOT TOUCH THIS SECTION OF CODE
  // Implementation of state machine with software button debouncing
  int button_press = digitalRead(3); // Reads LOW if pressed, HIGH if not pressed
  int time_elapsed = millis() - time_start;
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
    digitalWrite(4,HIGH);
    digitalWrite(2,LOW);//red on green off
    analogWrite(9,0);
  }

  else if (state == 1) {
    // TODO: Things that should happen if the state is "on"
    digitalWrite(4 ,LOW);
    digitalWrite(2,HIGH);
    int spd = map(analogRead(A0),0,1023,0,255);
    analogWrite(9,spd);
    
  }

  else {
    // If this occurs, you touched code that should have not been touched
    Serial.println("The state code already written is to avoid using a debouncing circuit");
    Serial.println("The reason we didn't make one is because your kit does not have a capacitor");
  }
}
