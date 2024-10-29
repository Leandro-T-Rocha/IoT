#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Fonts/FreeMono9pt7b.h>

#define OLED_RESET -1
#define PIN_SENSOR_MAGNETICO 7

Adafruit_SH1106 display(OLED_RESET);

void setup() {
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  pinMode(PIN_SENSOR_MAGNETICO, INPUT);
  Serial.begin(9600);
}

void loop() {
  display.clearDisplay();
  display.setFont(&FreeMono9pt7b);
  display.setTextColor(WHITE);
  display.setTextSize(1);

  // Verifica o estado do sensor
  bool sensorAtivo = digitalRead(PIN_SENSOR_MAGNETICO);
  
  // Exibe as mensagens correspondentes
  if (sensorAtivo) {
    exibirMensagem("Som", "Nao", "Detectado");
  } else {
    exibirMensagem("Som", "", "Detectado");
  }

  display.display();
  delay(500);
}

void exibirMensagem(const char* linha1, const char* linha2, const char* linha3) {
  display.setCursor(10, 10);  // Posição da primeira linha
  display.print(linha1);      // Imprime a primeira linha
  display.setCursor(10, 30);  // Posição da segunda linha
  display.print(linha2);      // Imprime a segunda linha
  display.setCursor(10, 50);  // Posição da terceira linha
  display.print(linha3);      // Imprime a terceira linha
}
