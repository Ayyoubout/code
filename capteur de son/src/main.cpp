
//https://arduino-france.site/capteur-son/


#include <Arduino.h>
#include <SPI.h>
#include <Arduino.h>
#include "WIFIConnector_MKR1000.h"
#include "MQTTConnector.h"

boolean statuslamp;

void setup() {
   Serial.begin(9600);
   pinMode(4, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(2, OUTPUT);
   pinMode(A1, INPUT);
   wifiConnect();    
   MQTTConnect();
}

void loop() {

   int val1 ;
   val1 = analogRead(A1);
   Serial.println(val1, DEC);

   Serial.println(analogRead(A1));
   if(analogRead(A1) < 25) {
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
   }

   if(25 < analogRead(A1) < 50) {
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
   }

   if(analogRead(A1) > 50) {
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
   }
   



   appendPayload("son",val1);  
   sendPayload();                               

      delay(1000);

}