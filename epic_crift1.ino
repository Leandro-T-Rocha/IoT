#define R 6
#define G 5
#define B 3
int buzzer =8;
void setup()
{ 
  Serial.begin(9600);
  pinMode(R, OUTPUT); 
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  int LDR = analogRead(A0); 
  Serial.println(LDR);  
  
  tone(buzzer, 100, 1000);
  delay(1000);
    analogWrite(R, 255);
    analogWrite(G, 255);
    analogWrite(B, 0);
    Serial.println("Cor Amarela");
  noTone(buzzer);
  delay(500); 
  tone(buzzer, 500, 1000);
  delay(1000); 
    analogWrite(R, 255);
    analogWrite(G, 0);
    analogWrite(B, 255);
    Serial.println("Cor Rosa");
  noTone(buzzer);
  delay(500);
  tone(buzzer, 1000, 1000);
  delay(1000); 
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 0);
    Serial.println("Cor Verde");
  noTone(buzzer);
  delay(500);
  tone(buzzer, 1500, 1000);
  delay(1000);
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 255);
    Serial.println("Cor Azul");
  noTone(buzzer);
  delay(500);
  tone(buzzer, 2000, 1000);
  delay(1000); 
    analogWrite(R, 255);
    analogWrite(G, 0); 
    analogWrite(B, 0);
    Serial.println("Cor vermelha");
  noTone(buzzer);
  delay(500);
}