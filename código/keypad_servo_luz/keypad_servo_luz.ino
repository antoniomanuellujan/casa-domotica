
///home/antonio/Escritorio/github/casa-domotica/código/rfid_servo_luz
//pines-casa7---servo(servo7)=3, luz(luz7)=2, keypad: filas(1=pin13, 2=pin12, 3=pin11) columnas(5=pin10, 6=pin9, 7=pin8)
//pines-casa8---servo(servo8)=5, luz(luz8)=4, keypad: filas(1=pin13, 2=pin12, 3=pin11) columnas(5=pin10, 6=pin9, 7=pin8)


#include <Servo.h>
#include <Keypad.h>

/*Variables de las casas controladas por keypad*/
const byte rowsCount = 3;
const byte columsCount = 3;
 
char keys[rowsCount][columsCount] = {
   { '1','2','3' },
   { '4','5','6' },
   { '7','8','9' }
};
const byte rowPins[rowsCount] = { 13, 12, 11 };
const byte columnPins[columsCount] = { 10, 9, 8 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);

Servo servo7;
int luz7=2;
Servo servo8;
int luz8=4;



void setup() {
  
  Serial.begin(9600);
  /*COnfiguración de la casas controladas por keypad*/
  servo7.attach(3);
  servo7.write(10); 
  pinMode(luz7,OUTPUT);
  digitalWrite(luz7,LOW);
  servo8.attach(5);
  servo8.write(10);
  pinMode(luz8,OUTPUT);
  digitalWrite(luz8,LOW);
 
}

void loop() {
  char key = keypad.getKey();
  Serial.println(key);
   if (key=='7') {
    casa7();
   }
   else if(key=='8'){
    casa8();
   }
   else{
    nada();
   }
}


void casa7(){
  servo7.write(280); 
  digitalWrite(luz7,HIGH);
  delay(5000); 
  servo7.write(100);
  digitalWrite(luz7,LOW);  
}

void casa8(){
  servo8.write(10); 
  digitalWrite(luz8,HIGH);
  delay(5000); 
  servo8.write(100);
  digitalWrite(luz8,LOW); 
}


void nada(){
  servo7.write(130); 
  digitalWrite(luz7,LOW);
  servo8.write(130);
  digitalWrite(luz8,LOW);
}
