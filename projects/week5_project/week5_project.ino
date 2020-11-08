#include <Servo.h>

Servo myservo;  
int pos = 0;  
int time_start = 0;
int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(A0, INPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  myservo.attach(9);  //from the sample code 

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
  if (state == 0) {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }

  else if (state == 1) {
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    int val = analogRead(A0);
    val = map(val, 0, 1023, 0, 180);
    myservo.write(val);
    delay(15);
  }

  else {
    // If this occurs, you touched code that should have not been touched
    Serial.println("The state code already written is to avoid using a debouncing circuit");
    Serial.println("The reason we didn't make one is because your kit does not have a capacitor");
  }
}
