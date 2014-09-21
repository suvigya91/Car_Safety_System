#include <string.h>
#include <ctype.h>
 /*gps init*/
 
 int ledPin = 13;                  // LED test pin
 int rxPin = 0;                    // RX PIN 
 int txPin = 1;                    // TX TX
 int byteGPS=-1;
 char linea[300] = "";
 char comandoGPR[7] = "$GPRMC";
 int cont=0;
 int bien=0;
 int conta=0;
 int indices[13];
 int x=0;
 int y=0;
 //char gps_data1[10]={0,0,0,0,0,0,0,0,0,0};
 //char gps_data2[10];
 //char gps_data3[10];
 //char gps_data4[10];
 char lat[10]={0,0,0,0,0,0,0,0,0,0};
 char lat1[10]={0,0,0,0,0,0,0,0,0,0};
 char lon[10]={0,0,0,0,0,0,0,0,0,0};
 char lon1[10]={0,0,0,0,0,0,0,0,0,0};
 //char lat1=0;
 //char lon=0;
 //char lon1=0;
 char ab=0;
 char bc=0;
 int k=0;
 int z=0;
 //char gps_data=0;
 
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
   Serial.begin(9600);
   pinMode(ledPin, OUTPUT);       // Initialize LED pin
   pinMode(rxPin, INPUT);
   pinMode(txPin, OUTPUT);
   //pinMode(led, OUTPUT);
   
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(12, OUTPUT);
   
   for (int i=0;i<300;i++)       // Initialize a buffer for received data
   {
     linea[i]=' ';
   }  
 
     
}




void gsm()
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
        digitalWrite(9, HIGH);
        delay(2000);
        digitalWrite(9, LOW);
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
      digitalWrite(10, HIGH);
      delay(2000);
      digitalWrite(10, LOW);
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
          digitalWrite(11,HIGH);
          delay(3000);
          digitalWrite(11,LOW);
          
          
          Serial1.print(lat);     // the SMS body
          Serial.println(lat);     // the SMS body
          
          Serial1.print(lat1);     // the SMS body
          Serial.println(lat1);     // the SMS body
          
          Serial1.print(lon);     // the SMS body
          Serial.println(lon);     // the SMS body
          
          Serial1.print(lon1);     // the SMS body
          Serial.println(lon1);     // the SMS body
          
          
          Serial1.print(char(26));
          Serial1.print(char(13));     
          digitalWrite(13,HIGH);
          //delay(500);
          delay(15000);
          digitalWrite(13,LOW);
          a[0]=Serial1.read();
          a[1]=Serial1.read();
          if(Serial1.available()>0)
          {
           Serial.println(a);
           digitalWrite(9,HIGH);
           delay(2000);
           digitalWrite(9,LOW); 
          }
        }
        count++;
    //} 
}


void gps()
{
   //e++;
   digitalWrite(ledPin, HIGH);
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
       digitalWrite(ledPin, LOW); 
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
                     Serial.println("value of lat is:");
                     Serial.println(lat[k]);
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
             
            /* if(i==2)
             {
               lat=Serial.print(linea[j+1]);
             }
             if(i==3)
             {
               lat1=Serial.print(linea[j+1]);
             }
             if(i==4)
             {
              lon=Serial.print(linea[j+1]); 
             }
             if(i==5)
             {
              lon1=Serial.print(linea[j+1]); 
             }*/
               
           }
           Serial.println("");
         }
         Serial.println("---------------");
       }
      /* for(i=0;i<300;i++)
       {
         if(linea[i]==',')
         {
          conta++; 
         }
         if(conta==3)
         {
          gps_data[i-3]=linea[i+1]; 
         }
       }*/
       //gps_data1[0]=lat;
       //gps_data2[0]=lat1;
       //gps_data3[0]=lon;
       //gps_data4[0]=lon1;
                                                                        
       
       conta=0;                    // Reset the buffer
       for (int i=0;i<300;i++){    //  
         linea[i]=' ';             
       }                 
     }
   }
 //  Serial.println(e);
}

void loop()
{
    for(z=0;z<5;z++)
    {//while(z<5)
      gps();
    }

    if(lat[0]>0)
    {
     while(y<1)
    {
      Serial.print("enter into gsm");
      gsm();
      y++;
    }
    }
}

