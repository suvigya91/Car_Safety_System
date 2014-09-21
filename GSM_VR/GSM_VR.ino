#include <string.h>
#include <ctype.h>
 
 /*gps init*/
 int gsml1=23;
 int gsml2=25;
 int gsml3=27;
 int gsml4=29;
 int gpsl1=31;
 int vrl1=33;
 int vrl2=35;
 int vrl3=37;
 int el=39;
 int flag1=0;
 int flag2=0;
// int flag3=0;
 
 int ledPin = 13;                  // LED test pin
// int rxPin = 0;  ;                  // RX PIN 
// int txPin = 1;                    // TX TX
 int byteGPS=-1;
 char linea[300] = "";
 char comandoGPR[7] = "$GPRMC";
 int cont=0;
 int bien=0;
 int conta=0;
 int indices[13];
 int x=0;
 int y=0;
 byte com=0;
 byte rec=0;
 
 char lat[10]={0,0,0,0,0,0,0,0,0,0};
 char lat1[10]={0,0,0,0,0,0,0,0,0,0};
 char lon[10]={0,0,0,0,0,0,0,0,0,0};
 char lon1[10]={0,0,0,0,0,0,0,0,0,0};
 char ab=0;
 char bc=0;
 int k=0;
 int z=0;
 int g=0;
 
 
 /*gsm initi*/
  char a[10];
  char b=0;
  char c=0;
  char d=0;
  char e=0;
  int timesToSend = 1;        // Numbers of SMS to send
  int count = 0;
  
  
  void setup()
  {
     Serial1.begin(9600);
     Serial2.begin(9600);
     Serial3.begin(9600);
     Serial.begin(9600);
     pinMode(ledPin, OUTPUT);       // Initialize LED pin
  //   pinMode(rxPin, INPUT);
  //   pinMode(txPin, OUTPUT);
     //pinMode(led, OUTPUT);
     
     pinMode(gsml1, OUTPUT);
     pinMode(gsml2, OUTPUT);
     pinMode(gsml3, OUTPUT);
     pinMode(gsml4, OUTPUT);
     pinMode(gpsl1, OUTPUT);
     pinMode(vrl1, OUTPUT);
     pinMode(vrl2, OUTPUT);
     pinMode(vrl3, OUTPUT);
     pinMode(el, OUTPUT);
     
    /* for (int i=0;i<300;i++)       // Initialize a buffer for received data
     {
       linea[i]=' ';
     }  
     */
     Serial3.write(0xAA);    //
     Serial3.write(0x37);    //changes to compact mode
     
     Serial3.write(0xAA);
     Serial3.write(0x21);      
  }
  
  
  void gsm1()
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
          
          Serial1.print("\n");     // the SMS body
         Serial1.print("2302.739");     // the SMS body
         // Serial.println(lat);     // the SMS body
          
          Serial1.print("N");     // the SMS body
        //  Serial.println(lat1);     // the SMS body
          
          Serial1.print("\n");     // the SMS body
          
          Serial1.print("73.13");     // the SMS body
        //  Serial.println(loN);     // the SMS body
          
          Serial1.print("E");     // the SMS body
         // Serial.println(lon1);    // the SMS body
          
          
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



 /* void gsm2()
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
}*/

void gps()
{
   //e++;
   digitalWrite(gpsl1, HIGH);
   byteGPS=Serial2.read();         // Read a byte of the serial port
   if (byteGPS == -1) 
   {           // See if the port is empty yet
     delay(100); 
   } 
   
   else 
   {
     linea[conta]=byteGPS;        // If there is serial port data, it is put in the buffer
     conta++;                      
     Serial.print((byte)byteGPS); 
     if (byteGPS==13)            // If the received byte is = to 13, end of transmission
       {
       digitalWrite(gpsl1, LOW); 
       cont=0;
       bien=0;
       for (int i=1;i<7;i++)     // Verifies if the received command starts with $GPR
         {
         if (linea[i]==comandoGPR[i-1])
         {
           bien++;
         }
       }
       if(bien==6)               // If yes, continue and process the data
         {
         for (int i=0;i<300;i++)
         {
           if (linea[i]==','){    // check for the position of the  "," separator
             indices[cont]=i;
             cont++;
             
           }
           if (linea[i]=='*'){    // ... and the "*"
             indices[12]=i;
             cont++;
           }
         }
         Serial.println("");      // ... and write to the serial port
         Serial.println("");
         Serial.println("---------------");
         for (int i=0;i<12;i++)
         {
           switch(i)
           {
             case 0 :Serial.print("Time in UTC (HhMmSs): ");break;
             case 1 :Serial.print("Status (A=OK,V=KO): ");break;
             case 2 :Serial.print("Latitude: ");
                     for(int g=indices[2],k=0;g<(indices[3]-1);g++,k++)
                     {
                     lat[k]=linea[g+1]; 
                     //Serial.println("value of lat is:");
                     //Serial.println(lat[k]);
                     }                     
                     break;
             case 3 :Serial.print("Direction (N/S): ");
                     for(int g=indices[3],k=0;g<(indices[4]-1);g++,k++)
                     {
                     lat1[k]=linea[g+1]; 
                     }   
                     break;
             case 4 :Serial.print("Longitude: ");
                     for(int g=indices[4],k=0;g<(indices[5]-1);g++,k++)
                     {
                     lon[k]=linea[g+1]; 
                     }   
                     break;
             case 5 :Serial.print("Direction (E/W): ");
                     for(int g=indices[5],k=0;g<(indices[6]-1);g++,k++)
                     {
                     lon1[k]=linea[g+1]; 
                     }   
                     break;
             case 6 :Serial.print("Velocity in knots: ");break;
             case 7 :Serial.print("Heading in degrees: ");break;
             case 8 :Serial.print("Date UTC (DdMmAa): ");break;
             case 9 :Serial.print("Magnetic degrees: ");break;
             case 10 :Serial.print("(E/W): ");break;
             case 11 :Serial.print("Mode: ");break;
             case 12 :Serial.print("Checksum: ");break;
           }
           for (int j=indices[i];j<(indices[i+1]-1);j++)
           {
             Serial.print(linea[j+1]);
             
            
           }
           Serial.println("");
         }
         Serial.println("---------------");
       }
      
 
       conta=0;                    // Reset the buffer
       for (int i=0;i<300;i++){    //  
         linea[i]=' ';             
       }                 
     }
   }
}


void loop()	// run over and over again
{ 
      //for(x=0;x<5;x++)
      //{
      gps();
      //}

      while(Serial3.available())
      {
      com = Serial3.read();    //read data on serial
      switch(com)
      {
        case 0x14:
              Serial.println("0");
              digitalWrite(vrl1, HIGH);	// correct pin
              delay(2000);
              digitalWrite(vrl1,LOW);
              flag1++;
              break;
        
        case 0x12:
              if(flag1==1 || flag1==2)
              {
              Serial.println("LOCK");
              digitalWrite(gsml2, HIGH);	// turn on led2
              delay(1000);
              //gsm2();
              digitalWrite(gsml2,LOW);
              flag2++;
              }
              
              if(flag1 > 2)
              {
              digitalWrite(gsml1, HIGH);
              delay(2000);
              digitalWrite(gsml1,LOW); 
              }
              break;
        
        case 0x13:
              //if(flag2==1)
              //{
              Serial.println("TRACK");
              digitalWrite(gsml3, HIGH);	// turn on led3
              delay(1000);
              Serial.println("Enter into gsm") ; 
              gsm1();
              flag1=0;
              flag2=0;
              digitalWrite(gsml3,LOW);
             // }
              
             /* if(flag2!=1)
              {
              digitalWrite(gsml1, HIGH);
              delay(2000);
              digitalWrite(gsml1,LOW); 
              }*/
              break;
        
        case 0x11:
              Serial.println("four");
              digitalWrite(gsml4, HIGH);	// turn on led4
              delay(1000);
              digitalWrite(gsml4,LOW);
              break;
        
        case 0x15:
              Serial.println("five");
              digitalWrite(gpsl1, HIGH);	// turn son led5
              delay(1000);
              digitalWrite(gpsl1,LOW);
              break;
        
        default:
              digitalWrite(gsml1, HIGH);	// turn son led5
              delay(1000);
              digitalWrite(gsml1,LOW);
              flag2++;
              break;
          }
        }
         
      /*if((flag2 == 0) && (flag1==1))
      {
       gsm1();
       flag1=0; 
      }
          
      if((flag2 > 0) && (flag1==1))
      {
       gsm1();
       flag1=0; 
       flag2=0;
      }*/
} 

