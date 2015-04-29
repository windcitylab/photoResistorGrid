#define kDelay 500

#define SER 2
#define RCLK 3
#define SRCLK 4
#define SRCLR 5

#define coord1_1 0x09
#define coord1_2 0x11

#define coord2_1 0x0A
#define coord2_2 0x12

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);  
  pinMode(5, OUTPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);  
  pinMode(11, OUTPUT);
  
  clearRegister();  
  
  pinMode(A0, INPUT);

}
void setAddress(uint8_t address)
{
  switch (address)
  {
    case 15 :
    {
      digitalWrite(8,HIGH);  
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
    }
    break;
    case 14 :
    {
      digitalWrite(8,LOW);  
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
    }
    break;
    case 13 :
    {
      digitalWrite(8,HIGH);  
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
    }
    break;
    case 12 :
    {
      digitalWrite(8,LOW);  
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
    }
    break;
  }

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
  digitalWrite(SER,item);
  digitalWrite(SRCLK, LOW);
  digitalWrite(SRCLK, HIGH);
  digitalWrite(SRCLK, LOW);
}

void loop() 
{
  sendValue(coord2_1);
  setAddress(13);

  Serial.println("---");
  delay(kDelay);
  Serial.println(analogRead(A0));
//  Serial.println(analogRead(A0));
//  setAddress(13);
//  Serial.println(analogRead(A0));
//  setAddress(12);
//  Serial.println(analogRead(A0));
//  setAddress(14);
//  sendValue(0x0A);
//  delay(kDelay);
//  Serial.println(analogRead(A0));
//  setAddress(13);
//  sendValue(0x11);
//  delay(kDelay);
//  Serial.println(analogRead(A0));
//  setAddress(12);
//  sendValue(0x12);
//  delay(kDelay);
//  Serial.println(analogRead(A0));  
  
}
