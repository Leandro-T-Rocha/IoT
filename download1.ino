// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2

// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

int counter;

void setup() {
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
 
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.clear();
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
 
  lcd.print("LED Vermelho");
  lcd.setCursor(0, 1);
  delay(2000);
 
  digitalWrite(3, HIGH);
  digitalWrite(1, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
 
  lcd.clear();
  lcd.print("LED Verde");
  lcd.setCursor(0, 1);
  delay(3000);
 
  digitalWrite(3, LOW);
  digitalWrite(1, LOW);
  digitalWrite(5, LOW);
 
  lcd.clear();
  digitalWrite(2, HIGH);
  lcd.print("LED Amarelo");
  lcd.setCursor(0, 1);
  delay(2000);

 

}
