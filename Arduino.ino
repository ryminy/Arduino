/*
*Message format:
* # # #  A P P P P 
* A = action 
* P =pin
*/

void setup()
{
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void decodeMessage(int *pin, int*action, char data)
{
  if(data & 0x10)
  {
    *action = 1;
  }
  *pin = data & 0xf;
}

void setAction(int pin, int action)
{
  int i;
  if (action == 1)
  {
    for( i = 0; i<10; i++)
    {
      digitalWrite(pin,HIGH);
      delay(300);
      digitalWrite(pin,LOW);
      delay(300);
    } 
  }      
}

void loop()
{
  char inByte = ' ';
  Serial.println("R");
  
  while(1)
  {
    if(Serial.available())
    { 
      inByte = Serial.read();
    }
    
    if( inByte != ' ')
    {
        int pin =0;
        int action = 0;
        decodeMessage(&pin,&action,inByte);   
        Serial.println(inByte);

        setAction(pin, action);
    }
  
    inByte = ' ';
  }
}
