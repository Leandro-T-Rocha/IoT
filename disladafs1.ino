#include<LiquidCrystal.h>
int cm = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

long readUltrasonicDistance(int trigger, int echo){
 
    pinMode(trigger, OUTPUT);    digitalWrite(trigger, LOW);
    delayMicroseconds(2);

    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    pinMode(echo, INPUT);

    return pulseIn(echo, HIGH) * 0.01723;}

float leitortemperatura(){
    int sensor = analogRead(A0);
    float voltage = sensor * (5.0 / 1023.0);
    float temperatura = voltage * 100;
     
    return temperatura;}

void setup()
{
 lcd.begin(16, 2);
}

void loop()
{
  cm = readUltrasonicDistance(5, 7);
  float temperatura = leitortemperatura();
 
  lcd.setCursor(0,0);          
  lcd.print(temperatura);
           
     
  }
