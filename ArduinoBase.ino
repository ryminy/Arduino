#define MAXSIZE 10
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);

}


void loop() {

  char ch;
  char input[MAXSIZE+1];
  int i;
  i = 0;
  input[0] = '\0';
  
  while (Serial.available() > 0)
  {
    if(i < 10)
    {
      ch = Serial.read();
      delay(2);
      input[i] = ch;
      i++;
      input[i] = '\0';
    }
    else
      break;
  }
  
  if( input[0] != '\0')
  {
    Serial.print("Am primit stringulaa:");
    Serial.println(input);
    
    digitalWrite(13,HIGH);
    //delay(2000);
    digitalWrite(13,LOW);
  }
} 
