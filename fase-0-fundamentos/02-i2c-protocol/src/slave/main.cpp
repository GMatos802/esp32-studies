#include <Arduino.h>
#include <Wire.h>

#define SDA_PIN 8
#define SCL_PIN 9

void setup() {
  Serial.begin(115200);
  
  for(int i = 0; i < 10; i++) {
    delay(1000);
    Serial.printf("Aguardando Serial... %d\n", 10-i);
  }

  Serial.println("\n--- I2C Scanner Iniciado ---");
  
  bool status = Wire.begin(SDA_PIN, SCL_PIN, 100000);
  if (!status) {
    Serial.println("ERRO: Nao foi possivel iniciar o I2C nos pinos 8 e 9.");
    while(1) delay(1000);
  }
}

void loop() {
  byte erro, endereco;
  int nDispositivos = 0;

  Serial.println("Escaneando barramento...");

  for (endereco = 1; endereco < 127; endereco++) {
    Wire.beginTransmission(endereco);
    erro = Wire.endTransmission();

    if (erro == 0) {
      Serial.printf("Dispositivo I2C encontrado no endereco 0x%02X!\n", endereco);
      nDispositivos++;
    } else if (erro == 4) {
      Serial.printf("Erro desconhecido no endereco 0x%02X\n", endereco);
    }
  }

  if (nDispositivos == 0) {
    Serial.println("Nenhum dispositivo I2C encontrado.\n");
  } else {
    Serial.println("Escaneamento finalizado.\n");
  }

  delay(3000);
}