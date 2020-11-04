//Gabriel Goch
//11/4/2020
//v1.0

int time_start = 0;
int state = 0;

//Initialize Pins
const int LEDON = 4;
const int LEDOFF = 5;
const int motorPin = 9;


void setup() {
  // TODO: Initialize pins for potentiometer, 2 LEDs (PWM is optional), 
  //       and transistor control (PWM). Please use D3 as button.
    Serial.begin(9600);
    pinMode(3,INPUT);
    pinMode(LEDON, OUTPUT);
    pinMode(LEDOFF, OUTPUT);
    pinMode(A0, INPUT);
    pinMode(motorPin, OUTPUT);
    
}

void loop() { 
  
  
  int button_press = digitalRead(3);
  int time_elapsed = millis() - time_start;
  
  
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
  


  // TODO: Using the state variable given, create a program that meets all project specifications
  //       The conditional statements are written for you.
  if (state == 0) {
    // TODO: Things that should happen if the state is "off"
    //Light command
    digitalWrite(LEDOFF, HIGH);
    digitalWrite(LEDON, LOW);

    //Motor Control Off
    analogWrite(motorPin, 0);

  }

else if (state == 1) {

    //Light command
    digitalWrite(LEDOFF, LOW);
    digitalWrite(LEDON, HIGH);

    //Motor control
    int motorIn = analogRead(A0);
    int motorInMapped = map(motorIn, 0, 1023, 0, 255);
    Serial.println(motorIn);
    analogWrite(motorPin, motorInMapped);

}

else {
    Serial.println("The state code already written is to avoid using a debouncing circuit");
    Serial.println("The reason we didn't make one is because your kit does not have a capacitor");
}
}
