#define kDelay 500

#define SER 2
#define RCLK 3
#define SRCLK 4
#define SRCLR 5

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);  
  pinMode(5, OUTPUT);
  
  clearRegister();  

}

void sendValue(uint8_t value)
{
  for (int i=0; i<8; i++)
  {
    if (value & (1 << (7 - i)))
    {
      addItem(HIGH);
    }
    else
    {
      addItem(LOW);
    }
  }
  latchOutput();
}
void clearRegister()
{
  digitalWrite(SRCLR, HIGH);  
  digitalWrite(SRCLR, LOW);
  digitalWrite(SRCLR, HIGH);
}

void latchOutput()
{
  digitalWrite(RCLK,LOW);
  digitalWrite(RCLK, HIGH);
  digitalWrite(RCLK, LOW);
}

void addItem(bool item)
{
  if (item)
  {
    Serial.println("high");
  }
  else
  {
     Serial.println("low");
  }
  digitalWrite(SER,item);
  digitalWrite(SRCLK, LOW);
  digitalWrite(SRCLK, HIGH);
  digitalWrite(SRCLK, LOW);
}

void loop() 
{
  sendValue(0x09);
  delay(kDelay);
  sendValue(0x0A);
  delay(kDelay);
  sendValue(0x11);
  delay(kDelay);
  sendValue(0x12);
  delay(kDelay);
}
