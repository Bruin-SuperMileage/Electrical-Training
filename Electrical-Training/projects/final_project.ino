int BUTTON_PIN = 3;
int LED1_PIN = 4;
int LED2_PIN = 5;
int LED3_PIN = 9;
int TRANSISTOR_PIN = 11;
int state = 0;
int time_start = 0;


void state_change()
{
  state = (state + 1) % 3;
}

void setup() 
{
  Serial.begin(9600);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(TRANSISTOR_PIN, OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), state_change, RISING);
}

void loop() 
{
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
    }
    else if(state == 1){
      state = 2;
    }
    else{
      state = 0;
    }
  }
  // DO NOT TOUCH ABOVE SECTION OF CODE
  // ================================================
  
  if(state == 0)
  {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    analogWrite(TRANSISTOR_PIN, 0);
    Serial.println("OFF");   
  }
  else if(state == 1)
  {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, LOW);
    analogWrite(TRANSISTOR_PIN, 180);
    Serial.println("MEDIUM");
  }
  else if(state == 2)
  {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, HIGH);
    analogWrite(TRANSISTOR_PIN, 255);
    Serial.println("HIGH");
  }
  //delay(1000);
}