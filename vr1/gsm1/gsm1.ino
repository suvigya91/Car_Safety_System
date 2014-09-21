
int a=0;
int b=1;
int c=0;
int d=0;
char ph_no[]="9426347767";
void setup()
{
   pinMode(13, OUTPUT);  
   Serial.begin(9600);
   Serial.println("start");
   Serial.print("\r");
   Serial.print("AT");
   //c=Serial.read();
   delay(5000);
   //if (c==((0x4F)&(0x4B)))
   //{
    //Serial.println("AT wala ok"); 
   //}
   
   Serial.print("AT+CMGF=1");
   delay(1000);
   //if (c==((0x4F)&(0x4B)))
   //{
   // Serial.println("AT+CMGF wala ok"); 
   //}
   //Serial.println("AT+CMGF=1\r");
   //delay(2000);
   
   
   //Serial.println("no. command sent\r");
   //delay(2000);
   
   //Serial.print("hey\r");
   //delay(2000);
   //Serial.print(1A, HEX);
   //Serial.println("msg sent");
}

void loop()
{
  while(a<b)
  {
   delay(2000);
   Serial.write("AT+CMGS=\"");
   Serial.write(ph_no);
   Serial.write("\"");
   //while(Serial.read()!='>');
   //d=Serial.read();
   delay(5000);
   //if(d=='>')
   //{
   Serial.println("> received");
   digitalWrite(13, HIGH);
   Serial.write("hey");
   delay(3000);
   Serial.write(0x1A);   
   Serial.write(0x0D);
   Serial.write(0x0A);
   delay(5000);
   //}
   a++;
  }
}
