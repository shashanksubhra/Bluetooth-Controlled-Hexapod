#include<Servo.h>
#include<SoftwareSerial.h>
SoftwareSerial BT(12,13);

Servo lift;
Servo rear;
Servo front;

char currstatus;



void setup() {
    Serial.begin(9600);
    BT.begin(9600);
    lift.attach(10);
    rear.attach(11);
    front.attach(9);

    lift.write(90);
    rear.write(90);
    front.write(90);

    delay(1000);
    currstatus='s';  
}

void foreward(){
  lift.write(120);
  delay(200);
  front.write(60);
  rear.write(60);
  delay(100);
  lift.write(90);
  delay(100);
  lift.write(60);
  delay(100);
  front.write(90);
  rear.write(90);
  delay(100);
  lift.write(90);
  delay(100);
}

void backward(){
  lift.write(120);
  delay(100);
  front.write(120);
  rear.write(120);
  delay(100);
  lift.write(90);
  delay(100);
  lift.write(60);
  delay(100);
  front.write(90);
  rear.write(90);
  delay(100);
  lift.write(90);
  delay(100);
}

void Stop(){
  lift.write(90);
  delay(100);
  front.write(90);
  delay(100);
  rear.write(90);
  delay(100);
}
void loop() {
  
  while(BT.available())
  {
    currstatus=BT.read();
    
  }

  if(currstatus=='w'){
    foreward();
  }
  if(currstatus=='b'){
    backward();
  }
  if(currstatus=='s'){
    Stop();
  }
}
