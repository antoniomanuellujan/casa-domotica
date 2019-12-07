
#include <Servo.h>

Servo myservo1;


void setup() {
  
  myservo1.attach(10);

}

void loop() {
ser1();

}

void ser1(){
  myservo1.write(10);                  // sets the servo position according to the scaled value
  delay(5000); 
 
  myservo1.write(90);                  // sets the servo position according to the scaled value
  delay(5000);
}
