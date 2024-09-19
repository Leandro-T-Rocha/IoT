#define BUZZER_PIN 2      // Pino do buzzer
#define LED_PIN 13        // Pino do LED
#define TRIG_PIN 5        // Pino do trigger do ultrassônico
#define ECHO_PIN 7        // Pino do echo do ultrassônico
#define BUTTON_PIN 9      // Pino do botão
#define TEMP_PIN A0       // Pino do LM35

bool alarmActive = false; // Estado do alarme

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Ativa pull-up interno

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
}

long readUltrasonicDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  return pulseIn(ECHO_PIN, HIGH) * 0.01723 / 2; // em cm
}

float readTemperature() {
  int sensorValue = analogRead(TEMP_PIN);
  float voltage = sensorValue * (5.0 / 1023.0);
  return voltage * 100; // Conversão para °C
}

void loop() {
  long distance = readUltrasonicDistance();
  float temperature = readTemperature(); // Temperatura em °C

  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.print(" cm, Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Ativa o alarme quando a distância é menor ou igual a 20 cm
  if (distance <= 20) {
    digitalWrite(BUZZER_PIN, HIGH); // Ativa buzzer
    digitalWrite(LED_PIN, HIGH); // Acende LED
    Serial.print("Alerta! Temperatura no momento: ");
    Serial.print(temperature);
    Serial.println(" °C");
  } else {
    digitalWrite(BUZZER_PIN, LOW); // Desativa buzzer
    digitalWrite(LED_PIN, LOW); // Desliga LED
  }

  // Se o botão for pressionado, desativa o alarme
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(BUZZER_PIN, LOW); // Desativa buzzer
    digitalWrite(LED_PIN, LOW); // Desliga LED
    Serial.println("Alarme silenciado!");
    delay(500); // Debounce delay
  }

  delay(100); // Delay para evitar leituras rápidas demais
}
