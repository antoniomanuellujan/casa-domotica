
//pines-casa1---servo(servo1)=3, luz(luz1)=2, joystick=A1, DavidyJoséRamón
//pines-casa2---servo(servo2)=5, luz(luz2)=4, joystick=A1, JuanAntonioyRaul

#include <Servo.h>

Servo servo1;
Servo servo2;
int joystick;
int luz1=2;
int luz2=4;


void setup() {
  
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(5);
  pinMode(luz1,OUTPUT);
  pinMode(luz2,OUTPUT);
  pinMode(A1,INPUT);
  
  servo1.write(10); 
  digitalWrite(luz1,LOW);
  servo2.write(10);
  digitalWrite(luz2,LOW);
}

void loop() {
 joystick=analogRead(A1);
 if(joystick <= 300) {
    casa1();
 }
  else if(joystick > 1000) {
    casa2();
  }
  else{
    nada();
  }
  

Serial.println(joystick);

delay(100);

}

void casa1(){
  servo1.write(280); 
  digitalWrite(luz1,HIGH);
  delay(5000); 
  servo1.write(100);
  digitalWrite(luz1,LOW);
  
  
}

void casa2(){
  servo2.write(10); 
  digitalWrite(luz2,HIGH);
  delay(5000); 
  servo2.write(100);
  digitalWrite(luz2,LOW);
  
}
void nada(){
  servo1.write(130); 
  digitalWrite(luz1,LOW);
  servo2.write(130);
  digitalWrite(luz2,LOW);
}
