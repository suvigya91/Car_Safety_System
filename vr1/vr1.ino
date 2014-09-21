int one = 23;	
int two = 25;	
int three = 27;	
int four = 29;	
int five = 31;	
byte com = 0; //reply from voice recognition

void setup() 
{ 
Serial3.begin(9600);
Serial.begin(9600);
pinMode(one, OUTPUT);	// sets the one to be an output
pinMode(two, OUTPUT);	// sets the two to be an output
pinMode(three, OUTPUT);	// sets the three to be an output
pinMode(four, OUTPUT);	// sets the four to be an output
pinMode(five, OUTPUT);	// sets the five to be an output

delay(2000);
Serial3.write(0xAA);    //
Serial3.write(0x37);    //changes to compact mode
delay(1000);
Serial3.write(0xAA);
Serial3.write(0x21);    //imports data from group one
} 

void loop()	// run over and over again
{ 

while(Serial3.available())
{
com = Serial3.read();    //read data on serial
switch(com)
{
case 0x11:
Serial.println("one");
digitalWrite(one, HIGH);	// turn on led1
delay(1000);
digitalWrite(one,LOW);
break;

case 0x12:
Serial.println("two");
digitalWrite(two, HIGH);	// turn on led2
delay(1000);
digitalWrite(two,LOW);
break;

case 0x13:
Serial.println("three");
digitalWrite(three, HIGH);	// turn on led3
delay(1000);
digitalWrite(three,LOW);
break;

case 0x14:
Serial.println("four");
digitalWrite(four, HIGH);	// turn on led4
delay(1000);
digitalWrite(four,LOW);
break;

case 0x15:
Serial.println("five");
digitalWrite(five, HIGH);	// turn son led5
delay(1000);
digitalWrite(five,LOW);
break;

}
}

} 

