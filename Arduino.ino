#define MAXSIZE 6
typedef struct _pkt
{
  unsigned char src;
  unsigned char dest;
  unsigned char type;
  unsigned char data[2];
  unsigned char crc;
} pkt;

#define STRINGTOPACKET(str,pkt) \
  ()

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);

}


void loop() {
  
  char input[MAXSIZE+1];
  int i;

  while(1)
  {
    i = 0;
    input[0] = '\0';
    
    while (Serial.available() > 0)
    {
        if(i < MAXSIZE)
        {
          delay(3);
          input[i++] = Serial.read();
          input[i] = '\0';
        }
        else
          break;
     }
    
    if( input[0] != '\0')
    {
      Serial.print("Am primit stringul:");
      Serial.print(input);
    }  
  }
 
} 
