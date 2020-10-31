
//jeff

// Complete the following TODOs for this program, then upload to your board.
// Correction in the lecture video: we provided a table for 
// analog inputs -> expected output, but provided the wrong values
// analog inputs should be the following: 0 - 341, 342 - 682, and 683 - 1023
int led_pin1 = 5;
int led_pin2 = 3;
int led_pin3 = 10;


void setup() {
  // Anything written after "//" on the same line is a comment in C++
  
  // Any code you put here (in this function) will only be ran once
  // Typically you want to intialize your variables/IO pins
  
  Serial.begin(9600);
  pinMode(A0, INPUT);
  
  // ==========================================================================================
  // TODO: Intialize three PWM output pins and one analog input pin. Makesure the pins selected 
  //       have PWM capabilities.
  pinMode(led_pin1,OUTPUT);
  pinMode(led_pin2,OUTPUT);
  pinMode(led_pin3,OUTPUT);
  
  
  // ==========================================================================================
}

void loop() {
  // Any code you put here (in this function) will be looped (ran over and over again)
  int val = analogRead(A0);
  int output = 0;
  int o1 = 342;
  int o2 = 683;


  // If you are unfamiliar with C++, this statement checks if the condition inside the parenthesis
  // is satisfied
  if (val < 342) { // LED 1
    output = map(val, 0, 341, 0, 255);
    // TODO: Output the mapped PWM onto the LED. LED 2 and LED 3 should be OFF
   
    analogWrite(led_pin3, output);
  
    //       LED 1 will vary depending on analog input
    
  }

  // If you are unfamiliar with C++, && means that both conditions need to be satisfied.
  if (val >= 342 && val <= 682) { // LED 2
    // TODO: Map out the val of the potentiometer and output the mapped PWM onto the LED.
    o1 = map(val, 342, 682, 0, 255);
    analogWrite(led_pin1, o1);
    
    //       LED 1 should be fully lit. LED 3 should be off. LED 2 will vary depending on analog input
    
  }
  
  
  if (val >= 683 && val <= 1023) { // LED 2
    // TODO: Insert missing values of if statement above.
    //       Map out the val of the potentiometer and output the mapped PWM onto the LED.
    o2 = map(val, 683, 1023, 0, 255);
    analogWrite(led_pin2, o2);
    
    //       LED 1 and 2 should be fully lit. LED 3 will vary depending on analog output
  }
  
} 
