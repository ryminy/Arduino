#define MAXSIZE 10
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);

}


void loop() {
  
  char input[MAXSIZE+1];
  int i;
  i = 0;
  input[0] = '\0';
  
  while (Serial.available() > 0)
  {
    if(i < 10)
    {
      delay(2);
      input[i++] = Serial.read();
      input[i] = '\0';
    }
    else
      break;
  }
  
  if( input[0] != '\0')
  {
    Serial.print("Am primit stringul:");
    Serial.println(input);
  }
} 
