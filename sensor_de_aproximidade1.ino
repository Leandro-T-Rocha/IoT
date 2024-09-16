/* 
	=======================================
	Pratica 25 - Sensor Ultrassom HC-SR04 e Buzzer
	
	Autor: Alberto Tolentino
	Criado em: 17/06/2020
	
	Demonstra o uso de sensor ultrassom
	simplificado HC-SR04 no Arduino. Ativa o
	Buzzer toda vez que sensor captar objeto
	a certa distância.
	
	Base do código utilizado
	https://www.tinkercad.com/things/5x4FbZMB0Wm
	=======================================    
*/

const int pinoBuzzer = 2;

const int ledVermelho = 13;
const int ledAmarelo = 12;
const int ledVerde = 11;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  cm = 0.01723 * readUltrasonicDistance(5, 7);
  Serial.print("Distância: ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(100);

  if (cm <= 10) {
    tone(pinoBuzzer, 2000);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
  } else if (cm <= 20) {
    tone(pinoBuzzer, 1000);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
  } else {
    noTone(pinoBuzzer);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
  }
}
