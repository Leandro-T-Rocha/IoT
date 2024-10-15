const int potX = A0;
const int potY = A1;
const int ledX = 5;
const int ledY = 6;

void setup() {
    Serial.begin(9600);
    pinMode(ledX, OUTPUT);
    pinMode(ledY, OUTPUT);
}

void loop() {
    int X = analogRead(potX);
    int Y = analogRead(potY);
  
    int ledValueX = map(X, 0, 1023, 0, 255);
    int ledValueY = map(Y, 0, 1023, 0, 255);
  
    analogWrite(ledX, ledValueX);
    analogWrite(ledY, ledValueY);
  
    Serial.print("Posicao X = ");
    Serial.print(X);
    Serial.print(" / Posicao Y = ");
    Serial.println(Y);
  
    delay(100);
}
