volatile int state = 0;
void state_change()
{
  state ++;
  state %= 3;
}

void setup(){
    pinMode(9, OUTPUT); // Green LED
    pinMode(10, OUTPUT); // Yellow LED
    pinMode(11, OUTPUT); // Red LED
    pinMode (3, INPUT); // Button
    pinMode(5, OUTPUT); // Motor


    attachInterrupt(digitalPinToInterrupt(3), state_change, RISING);

}

void loop(){
    int speed;

    if(state == 0){
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        speed = 0;
        analogWrite(5, speed);
    } else if (state == 1){
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        speed = 128;
        analogWrite(5, speed);
    } else if (state == 2){
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        speed = 255;
        analogWrite(5, speed);
    }
    delay(1000);
}
