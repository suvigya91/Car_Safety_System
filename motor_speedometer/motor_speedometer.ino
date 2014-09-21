#include <avr/io.h>
#include <avr/interrupt.h>

int d8=22;
int d9=24;
int d10=26;
int d11=28;
int time=0;
int delay1=0;
int l1= 4;
int l2=5;
int r1=6;
int r2=7;
byte e=0;
byte g=0;
int o=0;
byte c[]={0,0,0,0};
byte f[]={0,0,0,0};

int sensor=8;
int val=0;

int seconds;
int cntr;
float spd;
int spd2;
float diff;
int speeed;


//gsm
 int gsml1=23;
 int gsml2=25;
 int gsml3=27;
 int gsml4=29;
 int gpsl1=31;
 int beam=41;
 int p=0;
 
  char a[10];
  char b=0;
  //char c=0;
  //char d=0;
  //char e=0;
  int timesToSend = 1;        // Numbers of SMS to send
  int count = 0;

void setup()
{
Serial.begin(9600);
Serial1.begin(9600);

pinMode(gsml1, OUTPUT);
pinMode(gsml2, OUTPUT);
pinMode(gsml3, OUTPUT);
pinMode(gsml4, OUTPUT);
pinMode(gpsl1, OUTPUT);

pinMode(d8, INPUT);
pinMode(d9, INPUT);
pinMode(d10,INPUT);
pinMode(d11,INPUT);
pinMode(beam,INPUT);

pinMode(l1, OUTPUT);
pinMode(l2, OUTPUT);
pinMode(r1, OUTPUT);
pinMode(r2, OUTPUT);
pinMode(13, OUTPUT);

pinMode(sensor, INPUT);
    //Serial.begin(9600);
    // initialize Timer1
    cli();          // disable global interrupts
    TCCR1A = 0;     // set entire TCCR1A register to 0
    TCCR1B = 0;     // same for TCCR1B
 
    // set compare match register to desired timer count:
    OCR1A = 15624;
    // turn on CTC mode:
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler:
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12);
    // enable timer compare interrupt:
    TIMSK1 |= (1 << OCIE1A);
    sei();          // enable global interrupts
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
          
          
          Serial1.print("OVER SPEED. CAR NO:GJ09BEC115");     // the SMS body
          Serial.println("OVER SPEED. CAR NO:GJ09BEC115");     // the SMS body
          
          Serial1.print(char(26));
          Serial1.print(char(13));     
          digitalWrite(gsml4,HIGH);
          delay(500);
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


void timer_init(void)
{
  cli();          // disable global interrupts
    TCCR1A = 0;     // set entire TCCR1A register to 0
    TCCR1B = 0;     // same for TCCR1B
 
    // set compare match register to desired timer count:
    OCR1A = 15624;
    // turn on CTC mode:
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler:
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12);
    // enable timer compare interrupt:
    TIMSK1 |= (1 << OCIE1A);
    sei();          // enable global interrupts
}

void display_speed(void)
{
   spd=(cntr*33)*0.036*10;

 // lcd.clear(); 
 // lcd.setCursor(0,0);
  Serial.println("speed : ");
  //lcd.setCursor(0,1);
  Serial.println(spd);
  Serial.print("  Km/h ");
/*
  if(spd > 25)
  {
    digitalWrite(beam, HIGH);
  
  }
  else
  {
    digitalWrite(beam, LOW);
  }
  */
  if(spd > 35)
  {
  Serial.println("speed : ");
delay(20);
  //lcd.setCursor(0,1);
  Serial.println(spd);
delay(20);
  Serial.print("  Km/h ");
delay(20);
delay1=1;
//digitalWrite(13,HIGH);
seconds=0;
while(seconds!=1)
 {
  Serial.println(seconds);
delay(20);
 }
seconds=0;
digitalWrite(13,LOW);
seconds=0;
while(seconds!=1)
 {
  Serial.println(seconds);
delay(20);
}
seconds=0;
delay1=0;
}
 
}

ISR(TIMER1_COMPA_vect)
{
    seconds++;
    display_speed();
    if (delay1==0)       
    {
        cntr=0;
        seconds = 0;
        spd=0;
        spd2=0;
        speeed=0;
    }
    
/*    if(delay1==1)
    {
       digitalWrite(beam, HIGH);
       time++;
    }
*/
}
 
void sense(void)
 {
   
    val=digitalRead(sensor);
    if(val==LOW)
    {
    while(val==LOW)
    {
    val=digitalRead(sensor);
    }
    cntr+=1;
    } 
 }
 
 
 void loop()
{
 sense(); 
 
 c[0]=digitalRead(d8);
 c[1]=digitalRead(d9);
 c[2]=digitalRead(d10);
 c[3]=digitalRead(d11);
 e= c[0]+c[1]*2+c[2]*4+c[3]*8;
//if(o==1)
//{
 // while(p<1)
 //{
 //noInterrupts();  
/* cli();
 gsm();
 Serial.println("message sent");
 p++; 
 //interrupts();
 sei();*/
//}
//}

switch(e)
{
  case B00001111:
       //Serial.println("1111");
       analogWrite(l1,0);
       analogWrite(l2,0);
       analogWrite(r1,0);
       analogWrite(r2,0);
       break;
       
  case B00001101:
       //Serial.println("r1");
       analogWrite(l1,200);
       analogWrite(l2,0);
       analogWrite(r1,0);
       analogWrite(r2,200);
       break;
       
  case B00000111:
       //Serial.println("l1");
       analogWrite(l1,0);
       analogWrite(l2,200);
       analogWrite(r1,200);
       analogWrite(r2,0);
       break;
       
  case B00000101:
       //Serial.println("forward");
       for(int l=50;l<256;l++)
       {
        for(int m=0;m<1000;m++)
        {
        sense();
        analogWrite(l1, l);
        analogWrite(l2, 0);
        analogWrite(r1, l);
        analogWrite(r2, 0);
       
        f[0]=digitalRead(d8);
        f[1]=digitalRead(d9);
        f[2]=digitalRead(d10);
        f[3]=digitalRead(d11);
        g= f[0]+f[1]*2+f[2]*4+f[3]*8;
        
          if(e!=g)
            {
             break; 
            }
        }
      }
             break;
       
  case B00001010:
       //Serial.println("reverse");
       for(int l=50;l<256;l++)
       {
         for(int m=0;m<1000;m++)
        {
        
        analogWrite(l1, 0);
        analogWrite(l2, l);
        analogWrite(r1, 0);
        analogWrite(r2, l);
        sense();
        f[0]=digitalRead(d8);
        f[1]=digitalRead(d9);
        f[2]=digitalRead(d10);
        f[3]=digitalRead(d11);
        g= f[0]+f[1]*2+f[2]*4+f[3]*8;
          if(e!=g)
          {
           break; 
          }
        }
       }
       break;
}
}


