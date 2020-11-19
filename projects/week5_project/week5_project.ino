// These variables are used for your state machine
int time_start = 0;
int state = 0;
int val = 0;  //values from analog read... 0 to 1024
int output = 0; //values to PWM pin ... 0 to 255

void setup() {
  // TODO: Initialize pins for potentiometer, 2 LEDs (PWM is optional), 
  //       and transistor control (PWM). Please use D3 as button.
  Serial.begin(9600);
  pinMode(3,INPUT);
  
  pinMode(9, OUTPUT); //DC motor... NPN base
  pinMode(10, OUTPUT);  //Red LED
  pinMode(11, OUTPUT);  //Green LED
  
  pinMode(A0, INPUT);

  
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
    
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    analogWrite(9, LOW);

    
  }

  else if (state == 1) {
    // TODO: Things that should happen if the state is "on"
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    
    val = analogRead(A0);
    output = map(val, 0, 1023, 0, 255);
    analogWrite(9, output);

    
  }

  else {
    // If this occurs, you touched code that should have not been touched
    Serial.println("The state code already written is to avoid using a debouncing circuit");
    Serial.println("The reason we didn't make one is because your kit does not have a capacitor");
  }
}
