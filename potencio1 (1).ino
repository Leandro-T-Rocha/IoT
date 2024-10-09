void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop() {
  int posicaoX = analogRead(A1); // Lê o potenciômetro do Eixo X
  int posicaoY = analogRead(A0); // Lê o potenciômetro do Eixo Y

  // Determina a direção com base no Eixo Y
  String direcaoY;
  if (posicaoY < 512) {
    direcaoY = "    Para baixo";
  } else {
    direcaoY = "    Para cima";
  }

  // Determina a direção com base no Eixo X
  String direcaoX;
  if (posicaoX < 512) {
    direcaoX = "    Para esquerda";
  } else {
    direcaoX = "    Para direita";
  }

  // Imprime as leituras e direções no formato desejado
  Serial.print(" / posicao X = ");
  Serial.print(posicaoX);
  Serial.println(direcaoX);
  Serial.print("posicao Y = ");
  Serial.print(posicaoY);
  Serial.print(direcaoY);
  //Serial.print(" | Direcao Y: ");
  //Serial.print(direcaoY);
  //Serial.print(" | Direcao X: ");
  //Serial.println(direcaoX);

  delay(500); // Aguarda meio segundo antes da próxima leitura
}
