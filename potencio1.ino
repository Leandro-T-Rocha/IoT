void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop() {
  int posicaoX = analogRead(A1); // Lê o potenciômetro do Eixo X
  int posicaoY = analogRead(A0); // Lê o potenciômetro do Eixo Y

  // Imprime as leituras no formato desejado
  Serial.print("posicao X = ");
  Serial.print(posicaoX);
  Serial.print(" / posicao Y = ");
  Serial.println(posicaoY);

  delay(500); // Aguarda meio segundo antes da próxima leitura
}
