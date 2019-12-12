
//todas-casas-trig(sr04)=8, echo(sr04)=7,
//pines-casa1---servo(servo1)=3, luz(luz1)=2 conectada en relé a 2 casas más
//pines-casa2---servo(servo2)=5, luz(luz2)=4 conectada en relé a 2 casas más
//pines-casa3---servo(servo3)=6, luz conectada a relé luz 1
//pines-casa4---servo(servo4)=9  luz conectada a rele luz 1
//pines-casa5---servo(servo5)=10  luz conectada a rele luz 2
//pines-casa6---servo(servo4)=11  luz conectada a rele luz 2

#include <Servo.h>

/*Variables de la casa controlada por sr04*/
Servo servo1;
int luz1=2;
Servo servo2;
int luz2=4;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;


int echo=7;
int trig=8;
long distance;
long duration;





void setup() {
  
  Serial.begin(9600);
  /*COnfiguración de la casas controladas por sr04*/
  servo1.attach(3);
  servo1.write(10); 
  pinMode(luz1,OUTPUT);
  digitalWrite(luz1,LOW);
  servo2.attach(5);
  servo2.write(10);
  pinMode(luz2,OUTPUT);
  digitalWrite(luz2,LOW);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo3.attach(6);
  servo3.write(10); 
  servo4.attach(9);
  servo4.write(9); 
  servo5.attach(10);
  servo5.write(9);
  servo6.attach(11);
  servo6.write(9);  

  
 
}

void loop() {

 ultra();

  if(distance<=20){
    casa1();
  }
  else if(distance>20&&distance<=40){
    casa2();
  }
  else{
    nada();
  }
  

Serial.println(distance);

delay(100);

}

void ultra(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;
  }

void casa1(){
  servo1.write(10); 
  servo3.write(10);
  servo4.write(10);  
  digitalWrite(luz1,HIGH);
  delay(5000); 
  servo1.write(130);
  servo3.write(130);
  servo4.write(130);
  digitalWrite(luz1,LOW);
  
  
}

void casa2(){
  servo2.write(10);
  servo5.write(10);
  servo6.write(10);
  digitalWrite(luz2,HIGH);
  delay(5000); 
  servo2.write(130);
  servo5.write(130);
  servo6.write(130);
  digitalWrite(luz2,LOW);
  
}


void nada(){
  servo1.write(130); 
  digitalWrite(luz1,LOW);
  servo2.write(130);
  digitalWrite(luz2,LOW);
  servo3.write(130);
  servo4.write(130);
  servo5.write(130);
  servo6.write(130);
}
