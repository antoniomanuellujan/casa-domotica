#include <Servo.h>
#include <SPI.h>
#include <RFID.h>

RFID rfid(10, 9);

byte kart1[5] = {53,84,175,165,107};
byte kart2[5] = {59,18,210,13,246};
Servo myservo;
boolean card1;
boolean card2;

void setup()
{

  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  myservo.attach(3);
  myservo.write(100);

}

void loop()
{

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
    for (int i = 1; i < 5; i++)
    {
      if (rfid.serNum[0] == kart1[0] && rfid.serNum[1] == kart1[1] && rfid.serNum[2] == kart1[2] && rfid.serNum[3] == kart1[3] && rfid.serNum[4] == kart1[4])
      {
        card1 = true;
      }
      else if (rfid.serNum[0] == kart2[0] && rfid.serNum[1] == kart2[1] && rfid.serNum[2] == kart2[2] && rfid.serNum[3] == kart2[3] && rfid.serNum[4] == kart2[4])
      {
        card2 = true;
      }
      else {
        card1 = false;
        card2 = false;
        
      }
    }
    if (card1 == true)
    {
      Serial.println("Correct Card1");
      myservo.write(20);
      delay(1000);
      myservo.write(100);
    }
    else if (card2 == true)
    {
      Serial.println("Correct Card2");
      myservo.write(20);
      delay(1000);
      myservo.write(100);
    }
    else
    {
      Serial.println("Wrong Card");

    }
    rfid.halt();
    
  }
  card1 = false;
  card2 = false;
}
