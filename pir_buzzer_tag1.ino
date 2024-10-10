#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4 // Green LED pin
#define LED_R 5 // Red LED pin


MFRC522 mfrc522(SS_PIN, RST_PIN);


const String authorizedUIDs[] = {"E6 C2 66 AC"};

int sensorState = 0;
int buzzer = 8;


void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(buzzer, OUTPUT);
  
  SPI.begin();
  mfrc522.PCD_Init();
  
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);

}

 

void loop()
{
  sensorState = digitalRead(2);

 // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  content.toUpperCase();
  
  if (sensorState == HIGH){
    tone(buzzer, 100, 1000);
  }
      if (content.substring(1) == "E6 C2 66 AC" )
  {
    digitalWrite(LED_G, HIGH);
    Serial.println("Acesso Autorizado");
    Serial.println();
    noTone(buzzer);
    delay(1000);
    digitalWrite(LED_G, LOW);
    
  }  
  
 
 else{
    digitalWrite(LED_R, HIGH);
    Serial.println("Acesso Negado");
    delay(1000);
    digitalWrite(LED_R, LOW);
    tone(buzzer, 100, 1000);
    
   }
 delay(1000);
}

