// Complete the following TODOs for this program, then upload to your board.
// Correction in the lecture video: we provided a table for 
// analog inputs -> expected output, but provided the wrong values
// analog inputs should be the following: 0 - 341, 342 - 682, and 683 - 1023

#define led1 3
#define led2 6
#define led3 9
#define input A0

void setup() {
  // Anything written after "//" on the same line is a comment in C++
  
  // Any code you put here (in this function) will only be ran once
  // Typically you want to intialize your variables/IO pins
  
  Serial.begin(9600);
  pinMode(A0, INPUT);
  
  // ==========================================================================================
  // TODO: Intialize three PWM output pins and one analog input pin. Makesure the pins selected 
  //       have PWM capabilities.
  
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(12, INPUT);
  
  // ==========================================================================================
}

void loop() {
  // Any code you put here (in this function) will be looped (ran over and over again)
  int val = analogRead(input);
  int output = 0;
  Serial.println(val);
  
  
  // If you are unfamiliar with C++, this statement checks if the condition inside the parenthesis
  // is satisfied
  if (val < 342) { // LED 1
    output = map(val, 0, 341, 0, 255);
    // TODO: Output the mapped PWM onto the LED. LED 2 and LED 3 should be OFF
    //       LED 1 will vary depending on analog input
    analogWrite(led1, output);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  // If you are unfamiliar with C++, && means that both conditions need to be satisfied.
  if (val >= 342 && val <= 682) { // LED 2
    // TODO: Map out the val of the potentiometer and output the mapped PWM onto the LED.
    //       LED 1 should be fully lit. LED 3 should be off. LED 2 will vary depending on analog input
    output = map(val, 342, 682, 0, 255);
    
    analogWrite(led2, output);
    digitalWrite(led1, HIGH);
    digitalWrite(led3, LOW);
  }
  
  
  if (val  >= 683  && val <= 1024 ) { // LED 2
    // TODO: Insert missing values of if statement above.
    //       Map out the val of the potentiometer and output the mapped PWM onto the LED.
    //       LED 1 and 2 should be fully lit. LED 3 will vary depending on analog output
    output = map(val, 683, 1024, 0, 255); 
     analogWrite(led3, output);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
}
