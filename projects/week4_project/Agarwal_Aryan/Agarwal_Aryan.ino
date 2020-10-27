void setup() 
{
  Serial.begin(9600);  
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);

}

void loop()
{
  int val = analogRead(A0);
  int output = 0;

  if (val < 342) 
  { 
    output = map(val, 0, 341, 0, 255);
    analogWrite(6, output);
  }

  if (val >= 342 && val <= 682) 
  { 
    output = map(val, 342, 682, 0, 255);
    analogWrite(5, output);
  }
  
  
  if (val >= 683 && val <= 1023) 
  { 
    output = map(val, 683, 1023, 0, 255);
    analogWrite(3, output);
  }
}
