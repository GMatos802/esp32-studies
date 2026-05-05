#include <Arduino.h>
#include <Wire.h>

#define I2C_SDA 8
#define I2C_SCL 9

void setup() {
  Serial.begin(115200);
  delay(3000); 
  
  Serial.println("\n--- Scanner I2C Otimizado para C3 ---");

  Wire.setPins(I2C_SDA, I2C_SCL); 
  
  if (!Wire.begin()) {
    Serial.println("Falha ao iniciar o barramento I2C");
    while(1) delay(10);
  }

  Serial.println("I2C iniciado com sucesso nos pinos 8 e 9.");
}

void loop() {
  byte error, address;
  int devicesFound = 0;

  Serial.println("Escaneando...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Dispositivo encontrado no endereco 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      devicesFound++;
    }
  }

  if (devicesFound == 0) Serial.println("Nenhum dispositivo encontrado.");
  
  delay(5000);
}