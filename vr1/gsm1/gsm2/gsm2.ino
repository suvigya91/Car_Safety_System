int led = 13;
char a[10];
char b=0;
char c=0;
char d=0;
char e=0;
int timesToSend = 1;        // Numbers of SMS to send
int count = 0;


void setup()
{

    Serial.begin(9600);                // UART baud rate
    delay(2000);
    pinMode(led, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
   
    Serial.print("AT");     // sets the SMS mode to text
    Serial.print(0x0D);
    Serial.print(0x0A);
    //Serial.println("\n");
    delay(500);
    a[0]=Serial.read();
    a[1]=Serial.read();
    a[2]=Serial.read();
   
    if(Serial.available()>0)
    {
        Serial.println(a);
        //Serial.println("\t");
        Serial.println(a[1]);
        //Serial.println("\t");
        Serial.println(a[2]);
        digitalWrite(9, HIGH);
        delay(2000);
        digitalWrite(9, LOW);
        Serial.flush();
    }
    
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

    Serial.print("AT+CMGF=1");    // sets the SMS mode to text
    Serial.print(0x0D);
    Serial.print(0x0A);
    //Serial.println("\n");
    delay(100);
    
    a[0]=Serial.read();
    a[1]=Serial.read();
    
    if(Serial.available()>0)
   {
      Serial.println(a);
      //Serial.println("\n");
      Serial.println(a[1]);
      //Serial.println("\n");
      Serial.println(a[2]);
      digitalWrite(10, HIGH);
      delay(2000);
      digitalWrite(10, LOW);
      Serial.flush();
   }
}

void loop()
{

    while (count < timesToSend)
    {
        delay(1500);
        Serial.print("AT+CMGS=\"");     // send the SMS number
        Serial.print("+919426347767");
        Serial.print("\"");
      //  Serial.print("\r\n");
        Serial.print(0x0D);
        Serial.print(0x0A);
        delay(2000);
        a[0]=Serial.read();
        a[1]=Serial.read();
        
        if(Serial.available()>0)
        {
          Serial.println(a);
          Serial.println(a[1]);
          digitalWrite(11,HIGH);
          delay(3000);
          //if(d=='> ');      
          //{
          digitalWrite(11,LOW);
          Serial.print("Guten Morgan");     // the SMS body
          Serial.print(0x0D);
          Serial.print(0x0A);
          
          digitalWrite(13,HIGH);
          delay(500);
          //Serial.print((char)26);
          Serial.print(0x1A);       //sends ++
          Serial.print(0x0D);
          Serial.print(0x0A);
          delay(15000);
          digitalWrite(13,LOW);
          //}
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
