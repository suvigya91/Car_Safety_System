int led = 13;
char a[10];
char b=0;
char c=0;
char d=0;
char e=0;
int timesToSend = 1;        // Numbers of SMS to send
int count = 0;
char gps_data1[10]="2307.669";
char gps_data2[6]="N";
char gps_data3[10]="07232.595";
char gps_data4[5]="E";
void setup()
{

    Serial.begin(9600);                // UART baud rate
    delay(2000);
    pinMode(led, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
   
    
    
   /* Serial.print("AT");         // sets the SMS mode to text
    Serial.print(0x0D);
    Serial.print(0x0A);
    Serial.println("\n");
    delay(500);
    a[0]=Serial.read();
    a[1]=Serial.read();
    
    if(Serial.available()>0)
    {
      Serial.println(a);
      Serial.println(a[1]);
      Serial.println(a[2]);
      digitalWrite(10, HIGH);
      delay(2000);
      digitalWrite(10, LOW);
      Serial.flush();
    }*/
    //Serial.print("AT");         // sets the SMS mode to text
    //delay(500);

    //for (int i=0;i < 5;i++)
   // {
    //    delay(1000);
    //} 

    
}

void loop()
{

    while (count < timesToSend)
    {  
    Serial.print("AT");     // sets the SMS mode to text
    Serial.print(0x0D);
    Serial.print(0x0A);
    delay(500);
    a[0]=Serial.read();
    a[1]=Serial.read();
    a[2]=Serial.read();
   
    if(Serial.available()>0)
    {
        Serial.println(a);
        Serial.println(a[1]);
        Serial.println(a[2]);
        digitalWrite(9, HIGH);
        delay(2000);
        digitalWrite(9, LOW);
        Serial.flush();
    }
    
    Serial.println("AT+CMGF=1");    // sets the SMS mode to text
    Serial.print(0x0D);
    Serial.print(0x0A);
    delay(100);
    
    a[0]=Serial.read();
    a[1]=Serial.read();
    
    if(Serial.available()>0)
   {
      Serial.println(a);
      Serial.println(a[1]);
      Serial.println(a[2]);
      digitalWrite(10, HIGH);
      delay(2000);
      digitalWrite(10, LOW);
      Serial.flush();
   }
    
        delay(1500);
        Serial.println("AT+CMGS=\"+919426347767\"");     // send the SMS number
        delay(2000);
        a[0]=Serial.read();
        a[1]=Serial.read();
        
        if(Serial.available()>0)
        {
          //Serial.println(a);
          //Serial.println(a[1]);
          digitalWrite(11,HIGH);
          delay(3000);
          digitalWrite(11,LOW);
         // Serial.print("Guten Morgan");     // the SMS body
          Serial.print("Latitude=");
          Serial.print(gps_data1);     // the SMS body       
          delay(200);
          Serial.print(gps_data2);     // the SMS body
          Serial.print("\n");
          delay(200);
          Serial.print("Longitude=");
          Serial.print(gps_data3);     // the SMS body
          delay(200);
          Serial.print(gps_data4);     // the SMS body
          delay(200);
          
          Serial.print(char(26));
          Serial.print(char(13));     
          digitalWrite(13,HIGH);
          //delay(500);
          delay(15000);
          digitalWrite(13,LOW);
          a[0]=Serial.read();
          a[1]=Serial.read();
          if(Serial.available()>0)
          {
            Serial.println(a);
           digitalWrite(9,HIGH);
           delay(2000);
           digitalWrite(9,LOW); 
          }
        }
        count++;
    }

}
