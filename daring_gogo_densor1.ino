#define R 6
#define G 5
#define B 3

void setup()
{
  pinMode(A0, INPUT); 
  Serial.begin(9600);
  pinMode(R, OUTPUT); 
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT); 
}

void loop()
{
  int LDR = analogRead(A0); 
  Serial.println(LDR);   

  if (LDR < 100) {
    analogWrite(R, 255);
    analogWrite(G, 255);
    analogWrite(B, 0);
    Serial.println("Cor Amarela");
  } else if (LDR < 200) {
    analogWrite(R, 255);
    analogWrite(G, 0);
    analogWrite(B, 255);
    Serial.println("Cor Rosa");
  } else if (LDR < 300) {
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 0);
    Serial.println("Cor Verde");
  } else if (LDR < 400) {
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 255);
    Serial.println("Cor Azul");
  } else if (LDR < 500) {
    analogWrite(R, 255);
    analogWrite(G, 0); 
    analogWrite(B, 0);
    Serial.println("Cor vermelha");
  } else {
    analogWrite(R, 80);
    analogWrite(G, 80);
    analogWrite(B, 80);
    Serial.println("Cor ciza");
  }
  
  delay(1000);
}

