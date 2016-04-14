#define MAXSIZE 7
typedef struct _packet
{
  char src;
  char dest;
  char type;
  char data[2];
  char crc;
} packet;

void stringToPacket(packet * pkt, char *str)
{
   pkt->src = str[0];
   pkt->dest = str[1];
   pkt->type = str[2];
   pkt->data[0] = str[3];
   pkt->data[2] = str[4];
   pkt->crc= str[5];
}

void packetToString(char *str, packet *pkt)
{
   str[0] = pkt->src;
   str[1] = pkt->dest;
   str[2] = pkt->type;
   str[3] = pkt->data[0];
   str[4] = pkt->data[2];
   str[5] = pkt->crc;
   str[6] = '\0';
}

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);

}


void loop() {
  
  char input[MAXSIZE];
  int i;
  packet pkt;

  while(1)
  {
    i = 0;
    input[0] = '\0';
    
    while (Serial.available() > 0)
    {
        if(i < MAXSIZE-1)
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
 
} 
