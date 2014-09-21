#include <SoftwareSerial.h>
#include <String.h>
 int a=0;
SoftwareSerial mySerial(7,8);
 
void setup()
{
  mySerial.begin(9600);               // the GPRS baud rate   
  Serial.begin(9600);    // the GPRS baud rate 
  delay(500);
}
 
void loop()
{
  //after start up the program, you can using terminal to connect the serial of gprs shield,
  //if you input 't' in the terminal, the program will execute SendTextMessage(), it will show how to send a sms message,
  //if input 'd' in the terminal, it will execute DialVoiceCall(), etc.
 
  //if (Serial.available())
   // switch(Serial.read())
   //{
     //case 't':
     if(a<1)
     {
       SendTextMessage();
       //break;
     //case 'd':
       //DialVoiceCall();
       //break;
     
   //} 
  if (mySerial.available())
    Serial.write(mySerial.read());
    a++;
   }
}
 
///SendTextMessage()
///this function is to send a sms message
void SendTextMessage()
{
  mySerial.print("AT+CMGF=1\r");    //Because we want to send the SMS in text mode
  delay(100);
  mySerial.println("AT + CMGS = \"+919426347767\"");//send sms message, be careful need to add a country code before the cellphone number
  delay(100);
  mySerial.println("How are you ?");//the content of the message
  delay(100);
  mySerial.println((char)26);//the ASCII code of the ctrl+z is 26
  delay(100);
  mySerial.println();
}
 
///DialVoiceCall
///this function is to dial a voice call
//void DialVoiceCall()
{
  //mySerial.println("ATD + +919426347767;");//dial the number
  //delay(100);
  //mySerial.println();
//}
 
void ShowSerialData()
{
  while(mySerial.available()!=0)
    Serial.write(mySerial.read());
}

