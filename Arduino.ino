void setup()
{
Serial.begin(9600);
Serial.println("Ready");
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
}

void loop()
{
  
char inByte = ' ';

while(1)
{
  inByte = ' ';
  if(Serial.available())
  { 
    inByte = Serial.read();
  }
  if( inByte != ' ')
  {   
      Serial.print("am primit comanda: ");
      Serial.println(inByte);
  }
  delay(100); 
}

}
