#include<string.h>
#include <WiFi.h>
#include <SPI.h>
#include <Wire.h>
#define TXD1 17
#define RXD1 16


String mob;
String loct;

int x =2;
int y =2;
void setup() {
  Wire.begin();
  Serial.begin(115200); 
  Serial2.begin(115200, SERIAL_8N1, RXD1, TXD1);
  Serial2.println("AT+GPS=1");
  Serial2.println("AT+GPSMD=2");

  int i = 1;
  String str;
  
  while (i) {
    Serial2.println("AT+LOCATION=2");
    delay(100);
    while (Serial2.available() <= 0);
    if (Serial2.find("AT+LOCATION=2")) {
      str = Serial2.readString();
      //SerialUSB.println(str);
      i = 0;
    }
    delay(500);
  }
  loct = str.substring(4, 23);
  Serial2.print("Location: ");
  Serial2.println(loct);
  
}

void loop()
{

 
  
  if (x==2) {
   Serial2.println(loct);
   delay(100);

  //Serial2.println("AT+CGPSRST=1");
 // delay(1000);
  //Serial2.println("AT+GPSRD=0");
  //delay(1000);
  //Serial2.println("AT+LOCATION=2");
  //delay(1000);



}

while (Serial2.available()) {
    Serial.print(char(Serial2.read()));
  }
  
}
