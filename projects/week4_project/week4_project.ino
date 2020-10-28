// Gabriel Goch
//10/27/2020
//v1.0
// analog inputs should be the following: 0 - 341, 342 - 682, and 683 - 1023

const int LED1 = 3;
const int LED2 = 5;
const int LED3 = 6;

void setup() {
  
  Serial.begin(9600);
  
  //Pot read pin
  pinMode(A0, INPUT);
  
  //LED PWM Outputs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

}

void loop() {

  int val = analogRead(A0);
  int output = 0;

  Serial.println(val);

  //LED 1
  if (val < 342) {
    output = map(val, 0, 341, 0, 255);
    
    analogWrite(LED1, output);
    analogWrite(LED2, 0);
    analogWrite(LED3, 0);
    
  }

  //LED2
  if (val >= 342 && val <= 682) {
    output = map(val, 342, 682, 0, 255);

    analogWrite(LED1, 255);
    analogWrite(LED2, output);
    analogWrite(LED3, 0);

  }
  
  //LED 3
  if (val >= 683 && val <= 1023) {
    output = map(val, 683, 1023, 0, 255);

    analogWrite(LED1, 255);
    analogWrite(LED2, 255);
    analogWrite(LED3, output);

  }
}
