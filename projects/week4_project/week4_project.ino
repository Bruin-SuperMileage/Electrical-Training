
void setup() {

  Serial.begin(9600);
  pinMode(A0, INPUT); //set A0 as input
  
  pinMode(3, OUTPUT); //controls RED LED
  pinMode(10, OUTPUT); //controls BLUE LED
  pinMode(11, OUTPUT); //controls WHITE LED
  
}

void loop() {

  int val = analogRead(A0); //Feeds input from pot to A0
  int output = 0; //intialize scaled output value to 0


  if (val < 342) { // LED 1 (red)
    
    output = map(val, 0, 341, 0, 255); //Scale input value
    analogWrite(3, output); //send scaled value to corresponding port
    
  }

  if (val >= 342 && val <= 682) { // LED 2 (blue)
    
    output = map(val, 342, 682, 0, 255);
    analogWrite(10, output);

  }
  
  
  if (val >= 683 && val <= 1023) { // LED 2 (white)
    
    output = map(val, 683, 1023, 0, 255);
    analogWrite(11, output);

  }
}
