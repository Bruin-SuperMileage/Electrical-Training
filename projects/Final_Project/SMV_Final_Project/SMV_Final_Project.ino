// These variables are used for your state machine
int time_start = 0;
int state = 0;
int motor_pin = 5;
int motor_speed = 0;
int RED_LED_PIN = 6;
int BLUE_LED_PIN = 7;
int GREEN_LED_PIN = 8;

void setup() {

  Serial.begin(9600);
  pinMode(3,INPUT_PULLUP);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(3), State_Change, FALLING);
  //pinMode(motor_pin, OUTPUT);
  
}

void loop(){

  Serial.print("Speed = ");
  Serial.println(motor_speed);
  
   if(state == 0){
      motor_speed = 0;
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(BLUE_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, LOW);
   }
      
   if(state == 1){
      motor_speed = 128;
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, LOW);
   }
   
   if(state == 2){
      motor_speed = 256;
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
   }
   
   analogWrite(motor_pin, motor_speed);

       
  
}

void State_Change(){

  int time_elapsed = millis() - time_start;

  if(time_elapsed >= 500){
    state++;
    if(state > 2)
         state = 0;

    time_start = millis();
  }
    
}
