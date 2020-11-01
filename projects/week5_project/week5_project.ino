int time_start = 0;
int state = 0;
void setup() {
  // TODO: Initialize pins for potentiometer, 2 LEDs (PWM is optional), 
  //       and transistor control (PWM). Please use D3 as button.
  Serial.begin(9600);
  pinMode(3,INPUT);
}

void loop() { 
  // Implementation of state machine with software button debouncing
   // 0 for off, 1 for on
  int button_press = digitalRead(3); // Reads HIGH if pressed, LOW if not pressed
  int time_elapsed = millis() - time_start;
  if (button_press == HIGH && time_elapsed >= 1000) {
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
  
  // TODO: Using the state variable given, create a program that meets all project specifications
  //       The conditional statements are written for you.

  if (state == 0) {
    // TODO: Things that should happen if the state is "off"

    
  }

  else if (state == 1) {
    // TODO: Things that should happen if the state is "on"

    
  }

  else {
    // If this occurs, you touched code that should have not been touched
    Serial.println("The state code already written is to avoid using a debouncing circuit");
    Serial.println("The reason we didn't make one is because your kit does not have a capacitor");
  }
}
