// Complete the following TODOs for this program, then upload to your board.
// Correction in the lecture video: we provided a table for 
// analog inputs -> expected output, but provided the wrong values
// analog inputs should be the following: 0 - 341, 342 - 682, and 683 - 1023
int RED_LED = 3;
int BLUE_LED = 6;
int GREEN_LED = 9;
void setup() {
  // Anything written after "//" on the same line is a comment in C++
  
  // Any code you put here (in this function) will only be ran once
  // Typically you want to intialize your variables/IO pins
  
  Serial.begin(9600);
  
  
  // ==========================================================================================
  // TODO: Intialize three PWM output pins and one analog input pin. Makesure the pins selected 
  //       have PWM capabilities.
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  // ==========================================================================================
}

void loop() {
  // Any code you put here (in this function) will be looped (ran over and over again)
  int x_pos = analogRead(A1);
  int y_pos = analogRead(A0);
  int x_output = 0;
  int y_output = 0;

   x_output = map(x_pos, 0, 1023, -128, 128);
   y_output = map(y_pos, 0, 1023, -128, 128);

 Serial.print("X =");
 Serial.print(x_output);
 Serial.print(" Y =");
 Serial.println(y_output);
 
   if(x_output <= 0){
    digitalWrite(BLUE_LED, 0);
    analogWrite(GREEN_LED, -x_output);
   }

   if(x_output > 0){
    digitalWrite(GREEN_LED, 0);
    analogWrite(BLUE_LED, x_output);
   }

   analogWrite(RED_LED, y_output);

  

}
  /*
  // If you are unfamiliar with C++, this statement checks if the condition inside the parenthesis
  // is satisfied
  if (val < 342) { // LED 1
    x_output = map(val, -128, 128, 0, 255);
    digitalWrite(RED_LED, output);
    // TODO: Output the mapped PWM onto the LED. LED 2 and LED 3 should be OFF
    //       LED 1 will vary depending on analog input
    
  }

  // If you are unfamiliar with C++, && means that both conditions need to be satisfied.
  if (val >= 342 && val <= 682) { // LED 2
    output = map(val, 342, 681, 0, 255);
    digitalWrite(BLUE_LED, output);
    digitalWrite(RED_LED, 255);
    // TODO: Map out the val of the potentiometer and output the mapped PWM onto the LED.
    //       LED 1 should be fully lit. LED 3 should be off. LED 2 will vary depending on analog input
    
  }
  
  
  if (val >= 682 && val <= 1027 ) { // LED 2
    // TODO: Insert missing values of if statement above.
    output = map(val, 682, 1027, 0, 255);//       Map out the val of the potentiometer and output the mapped PWM onto the LED.
    digital_Write(GREEN_LED, 255);
    digitalWrite(BLUE_LED, 255);
    digitalWrite(RED_LED, 255);//       LED 1 and 2 should be fully lit. LED 3 will vary depending on analog output
  }
}

}
*/
