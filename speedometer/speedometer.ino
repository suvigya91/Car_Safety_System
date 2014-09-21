

// avr-libc library includes
#include <avr/io.h>
#include <avr/interrupt.h>
//#include <LiquidCrystal.h>
//LiquidCrystal lcd(51,49,47,45,43,41);
int sensor=8;
int val=0;

int seconds;
int cntr;
float spd;
int spd2;
float diff;
int speeed;
void setup()
{
    Serial.begin(9600);
    //lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
    //lcd.clear();
    //lcd.setCursor(0,0); 
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

void display_speed(void)
{
spd=(cntr*33)*0.036;
spd2=spd;
diff=spd-spd2;
/*if(diff>=0.5)
{
  speeed=spd2+1;
}
else
{
  speeed= spd;
}*/

 // lcd.clear(); 
 // lcd.setCursor(0,0);
  Serial.println("speed : ");
  //lcd.setCursor(0,1);
  Serial.println(spd);
  Serial.print("  Km/h ");
  
  //delay(50);
  //Serial.println(cntr);
}

ISR(TIMER1_COMPA_vect)
{
    
        display_speed();
        cntr=0;
        seconds = 0;
        spd=0;
        spd2=0;
        speeed=0;
    
}
 
 
void loop()
{
val=digitalRead(sensor);
if(val==LOW)
{
while(val==LOW)
{
val=digitalRead(sensor);
}
cntr+=1;
//Serial.println(cntr);
//delay(500);
}
}

