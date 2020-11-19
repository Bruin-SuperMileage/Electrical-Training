//dan m test commit 10/28/20

// Complete the following TODOs for this program, then upload to your board.
// Correction in the lecture video: we provided a table for 
// analog inputs -> expected output, but provided the wrong values
// analog inputs should be the following: 0 - 341, 342 - 682, and 683 - 1023
int LED1 = 3;
int LED2 = 5;
int LED3 = 10;

void setup() {
  // Anything written after "//" on the same line is a comment in C++ //
  
  // Any code you put here (in this function) will only be ran once
  // Typically you want to intialize your variables/IO pins
  
  Serial.begin(9600);
  pinMode(A0, INPUT);
  
  // ==========================================================================================
  // TODO: Intialize three PWM output pins and one analog input pin. Makesure the pins selected 
  //       have PWM capabilities.
<<<<<<< HEAD
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
=======
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

>>>>>>> c06b4963236dc4a61edb905cc6b03c1fe6552f08
  // ==========================================================================================
}

void loop() {
  // Any code you put here (in this function) will be looped (ran over and over again)
  int val = analogRead(A0);
  int output = 0;
  Serial.println(val);


  // If you are unfamiliar with C++, this statement checks if the condition inside the parenthesis
  // is satisfied
  if (val < 342) { // LED 1
    output = map(val, 0, 341, 0, 255);
<<<<<<< HEAD
    // TODO: Output the mapped PWM onto the LED. LED 2 and LED 3 should be OFF
    //       LED 1 will vary depending on analog input
    analogWrite(9, output);
    analogWrite(10, LOW);
    analogWrite(11, LOW);
=======
    analogWrite(LED1, output);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    
>>>>>>> c06b4963236dc4a61edb905cc6b03c1fe6552f08
  }

  // If you are unfamiliar with C++, && means that both conditions need to be satisfied.
  if (val >= 342 && val <= 682) { // LED 2
    // TODO: Map out the val of the potentiometer and output the mapped PWM onto the LED.
    output = map(val, 341, 682, 0, 255);
    //       LED 1 should be fully lit. LED 3 should be off. LED 2 will vary depending on analog input
<<<<<<< HEAD
    analogWrite(9, 255);
    analogWrite(10, output);
   analogWrite(11, LOW);
  }
  
  
  if (val >= 683  && val <= 1023 ) { // LED 2
=======
    output = map(val, 342, 682, 0, 255);
    
    digitalWrite(LED1, HIGH);
    analogWrite(LED2, output);
    digitalWrite(LED3, LOW);
    
  }
  
  
  if (val >=  683 && val <= 1023) { // LED 2
>>>>>>> c06b4963236dc4a61edb905cc6b03c1fe6552f08
    // TODO: Insert missing values of if statement above.
    //       Map out the val of the potentiometer and output the mapped PWM onto the LED.
    output = map(val, 683, 1023, 0, 255);
    //       LED 1 and 2 should be fully lit. LED 3 will vary depending on analog output
<<<<<<< HEAD
    analogWrite(9, 255);
    analogWrite(10, 255);
    analogWrite(11, output);
=======

    output = map(val, 682, 1023, 0, 255);
    
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    analogWrite(LED3, output);
>>>>>>> c06b4963236dc4a61edb905cc6b03c1fe6552f08
  }
}
