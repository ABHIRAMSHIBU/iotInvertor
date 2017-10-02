/* Author Abhiram Shibu and Abhijith N Raj
 * Copyright Year 2017
 * Copyright (c) TeamDestroyer Projects 2017
 */
#include<string.h>
#include<SoftwareSerial.h>
SoftwareSerial serial1(12,11);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serial1.begin(115200);
  pinMode(13,1);
  pinMode(10,1);
  pinMode(9,1);
  pinMode(8,1);
  pinMode(7,1);
  pinMode(6,1);
  pinMode(5,1);
  pinMode(4,1);
  pinMode(3,1);
  pinMode(2,1);
  pinMode(14,1);
  pinMode(151);
  pinMode(16,1);
  pinMode(17,1);
  pinMode(18,1);
  pinMode(19,1);
}
void loop() {
  // put your main code here, to run repeatedly:
  char buff[100];
  int buffNow=0;
  while(!serial1.available()){
  }
  while(serial1.available()){
    buff[buffNow]=serial1.read();
    buffNow+=1;
    delay(3);
  }
  buff[buffNow]='\0';
  //Serial.print(buff);

  String s=String(buff);
  Serial.println(s);
  if(s.length()>=5 && s.length()<=6 ){
    int space=s.indexOf(" ")+1;
    char pin[space];
    s.toCharArray(pin,space);
    String zero="0\r\n";
    if(s.endsWith(zero)){
      //Serial.print(pin);
      //Serial.println(" off");
      if(strcmp(pin,"12") && strcmp(pin,"11")){
        Serial.print(pin);
        Serial.println(" off");
        digitalWrite(atoi(pin),0);
        serial1.print(atoi(pin));
        serial1.println(" off");
      }
      
      
    }
    else{

      if(strcmp(pin,"12") && strcmp(pin,"11")){
        Serial.print(pin);
        Serial.println(" on");
        digitalWrite(atoi(pin),1);
        serial1.print(atoi(pin));
        serial1.println(" on");
      }
    }
  }
  else{
    Serial.println("Unknown Command");
  }
}
