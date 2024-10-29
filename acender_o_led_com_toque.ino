// Definições de pinos
const int ledPin = 9;         // Pino onde o LED está conectado
const int touchPin = 2;       // Pino onde o sensor touch está conectado

void setup() {
  pinMode(ledPin, OUTPUT);    // Define o pino do LED como saída
  pinMode(touchPin, INPUT);   // Define o pino do sensor touch como entrada
  digitalWrite(ledPin, HIGH); // Liga o LED no início
}

void loop() {
  // Lê o estado do sensor touch
  int sensorValue = digitalRead(touchPin);

  // Se o sensor touch for acionado
  if (sensorValue == HIGH) {
    digitalWrite(ledPin, 1);  // Desliga o LED
  } else {
    digitalWrite(ledPin, 0);  // Liga o LED
  }

  delay(50); // Pequeno atraso para evitar leituras instáveis
}
