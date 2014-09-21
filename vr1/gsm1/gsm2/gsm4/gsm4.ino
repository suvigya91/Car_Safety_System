int led = 13;
char a[10];
char b=0;
char c=0;
char d=0;
char e=0;
int timesToSend = 1;        // Numbers of SMS to send
int count = 0;
int gsml1=23;
 int gsml2=25;
 int gsml3=27;
 int gsml4=29;
 int gpsl1=31;
 int vrl1=33;
 int vrl2=35;
 int vrl3=37;
 int el=39;

void setup()
{

    Serial1.begin(9600);                // UART baud rate
    Serial.begin(9600);
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


 //while (count < timesToSend)
    //{  
    Serial1.print("AT");     // sets the SMS mode to text
    Serial1.print(0x0D);
    Serial1.print(0x0A);
    delay(500);
    a[0]=Serial1.read();
    a[1]=Serial1.read();
    a[2]=Serial1.read();
   
    if(Serial1.available()>0)
    {
        Serial.println(a);
        Serial.println(a[1]);
        Serial.println(a[2]);
        digitalWrite(gsml1, HIGH);
        delay(2000);
        digitalWrite(gsml1, LOW);
        Serial1.flush();
    }
    
    Serial1.println("AT+CMGF=1");    // sets the SMS mode to text
    Serial1.print(0x0D);
    Serial1.print(0x0A);
    delay(100);
    
    a[0]=Serial1.read();
    a[1]=Serial1.read();
    
    if(Serial1.available()>0)
   {
      Serial.println(a);
      Serial.println(a[1]);
      Serial.println(a[2]);
      digitalWrite(gsml2, HIGH);
      delay(2000);
      digitalWrite(gsml2, LOW);
      Serial1.flush();
   }
    
        delay(1500);
        Serial1.println("AT+CMGS=\"+919426347767\"");     // send the SMS number
        delay(2000);
        a[0]=Serial1.read();
        a[1]=Serial1.read();
        
        if(Serial1.available()>0)
        {
          //Serial.println(a);
          //Serial.println(a[1]);
          digitalWrite(gsml3,HIGH);
          delay(3000);
          digitalWrite(gsml3,LOW);
          
          
          Serial1.print("CAR LOCKED");     // the SMS body
          Serial.println("CAR LOCKED");     // the SMS body
          
          Serial1.print(char(26));
          Serial1.print(char(13));     
          digitalWrite(gsml4,HIGH);
          //delay(500);
          delay(15000);
          digitalWrite(gsml4,LOW);
          a[0]=Serial1.read();
          a[1]=Serial1.read();
          if(Serial1.available()>0)
          {
           Serial.println(a);
           digitalWrite(13,HIGH);
           delay(2000);
           digitalWrite(13,LOW); 
          }
        }
        count++;
    //} 


}
