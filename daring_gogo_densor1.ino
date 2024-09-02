// C++ code
//
int LDR = 0;
int LED = 9;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int LDR = analogRead(A0);
  Serial.println(LDR);
  
  if (LDR<650){
    digitalWrite(LED, 1);
  	Serial.println("LED ligado");
  }
  else {
    digitalWrite(LED, 0);
    Serial.println("LED desligado");
}
  delay(1000);
}