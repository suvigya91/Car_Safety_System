char a[10];
int b=0;
void setup()
{
 Serial.begin(9600);
 pinMode(9, OUTPUT); 
}

void loop()
{
  while(b<1)
  {
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
    
   Serial.println("ATD + +919426347767;");
   Serial.println();
 b++;
  }   
}
