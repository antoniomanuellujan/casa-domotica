
//pines-casa5---servo(servo5)=3, luz(luz5)=2, RFID: (SDA=10, SCK=13, MOSI=11, MISO=12, RST=9)
//pines-casa6---servo(servo6)=5, luz(luz6)=4, RFID: (SDA=10, SCK=13, MOSI=11, MISO=12, RST=9)


#include <Servo.h>
#include <SPI.h>
#include <RFID.h>
RFID rfid(10, 9);

/*Variables de las casas controladas con tarjetas*/
byte kart1[5] = {53,84,175,165,107};
byte kart2[5] = {59,18,210,13,246};
Servo servo5;
int luz5=2;
Servo servo6;
int luz6=4;


void setup(){

  Serial.begin(9600);
  /*COnfiguración de la casas controladas con tarjetas*/
  SPI.begin();
  rfid.init();
  servo5.attach(3);
  servo5.write(10);
  pinMode(luz5,OUTPUT);
  digitalWrite(luz5,LOW);
  servo6.attach(5);
  servo6.write(10);
  pinMode(luz6,OUTPUT);
  digitalWrite(luz6,LOW);

}

void loop(){
  if (rfid.isCard())
  {
      if (rfid.readCardSerial())
    {
      Serial.print("Found ID: ");
      Serial.print(rfid.serNum[0]);
      Serial.print(",");
      Serial.print(rfid.serNum[1]);
      Serial.print(",");
      Serial.print(rfid.serNum[2]);
      Serial.print(",");
      Serial.print(rfid.serNum[3]);
      Serial.print(",");
      Serial.println(rfid.serNum[4]);

    }
      if (rfid.serNum[0] == kart1[0] && rfid.serNum[1] == kart1[1] && rfid.serNum[2] == kart1[2] && rfid.serNum[3] == kart1[3] && rfid.serNum[4] == kart1[4])
      {
       casa5();
     
      }
      else if (rfid.serNum[0] == kart2[0] && rfid.serNum[1] == kart2[1] && rfid.serNum[2] == kart2[2] && rfid.serNum[3] == kart2[3] && rfid.serNum[4] == kart2[4])
      {
       casa6();
      }
      else {
       nada();
      }
  }
}

void casa5(){ //se ejecuta si detecta kart1, empieza 53
  servo5.write(10); 
  digitalWrite(luz5,HIGH);
  delay(5000); 
  servo5.write(100);
  digitalWrite(luz5,LOW);
}

void casa6(){ //se ejecuta si detecta kart2, empieza 59
  servo6.write(10); 
  digitalWrite(luz6,HIGH);
  delay(5000); 
  servo6.write(100);
  digitalWrite(luz6,LOW);
  
}

void nada(){
  servo5.write(130); 
  digitalWrite(luz5,LOW);
  servo6.write(130);
  digitalWrite(luz6,LOW);
}
   
