void setup()
{
Serial.begin(9600);
Serial.println("R");
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
}

void loop()
{
  
char inByte = ' ';

  if(Serial.available())
  { 
    inByte = Serial.read();
  }
  
  if( inByte != ' ')
  {   
      Serial.println(inByte);
  }

}
