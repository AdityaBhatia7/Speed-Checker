#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sen1=11;
int sen2=12;
unsigned long t1=0;
unsigned long t2=0;
float velocity;
void setup()
{
  lcd.begin(16, 2);
  pinMode(13,OUTPUT);
  pinMode(sen1,INPUT);
  pinMode(sen2,INPUT);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Speed=");
}
void loop()
{
  while(digitalRead(sen1)==0);
  while(digitalRead(sen2));
  t1=millis();
  t1=t1/1000;
  Serial.println(t1);
  while(digitalRead(sen1));
  while(digitalRead(sen2)==0);
  t2=millis();
  t2=t2/1000;
  Serial.println(t2);
  velocity=t2-t1;
  velocity=(100/velocity);//v=d/t
  lcd.setCursor(7,0);
  lcd.print(velocity);
  lcd.print("cm/s");
  velocity=velocity*3600;//multiply by seconds per hr
  velocity=velocity/100000;//division by meters per Km
  Serial.print(velocity);
  Serial.print("km/hr");
  lcd.setCursor(3,1);
  lcd.print(velocity);
  lcd.print(" Km/hr   ");
  
  if (velocity > 2){
    digitalWrite(13,HIGH);
    delay(5000);
    digitalWrite(13,LOW);
  }
  else{
    digitalWrite(13,LOW);
  }
}
