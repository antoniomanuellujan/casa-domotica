
#include <Servo.h>

Servo myservo1;


void setup() {
  
  myservo1.attach(10);
  pinMode(9,OUTPUT);

}

void loop() {
ser1();


}

void ser1(){
  myservo1.write(10); 
  digitalWrite(9,HIGH);
  delay(5000); 
  myservo1.write(130);
  digitalWrite(9,LOW);
  delay(5000);
}
