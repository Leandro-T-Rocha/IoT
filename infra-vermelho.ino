#include <Wire.h> // Biblioteca para uso do protocolo I2C;
#include <Adafruit_GFX.h> // Biblioteca para manipulação gráfica no display;
#include <Adafruit_SH1106.h> // Biblioteca para operação do driver de controle do display;
#include <Fonts/FreeMono9pt7b.h> // Fonte para alteração do texto;
#define OLED_RESET -1 // Em displays que não possuem pino RESET, é dado o valor -1;
#define pinSensor1 7
Adafruit_SH1106 display(OLED_RESET); // Declaração da tela com o nome "display";
void setup () {
 display.begin(SH1106_SWITCHCAPVCC, 0x3C); // Inicialização do display com a biblioteca e endereço de hardware do display;
  pinMode(pinSensor1, INPUT);
  Serial.begin(9600);
}

void loop() {
  display.clearDisplay();

  display.setFont(&FreeMono9pt7b); // Definir a fonte
  display.setTextColor(WHITE); // Cor do texto
  display.setTextSize(1); // Tamanho do texto

bool estadoSensor1 = digitalRead(pinSensor1);

if (estadoSensor1) {
  Serial.println("PRETO (ou nada)");
  display.setCursor(5, 35); // Posição do "O"
  display.print("aproxime-se");
  display.display();
}else{
  Serial.println("BRANDO (diferente de preto)");
  display.setCursor(20, 35); // Posição do "O"
  display.print("afaste-se");
  display.display();
}

}