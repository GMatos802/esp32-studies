#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP_CS   5
#define BMP_MOSI 23
#define BMP_MISO 19
#define BMP_SCK  18

Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);

void setup() {
  Serial.begin(115200);
  bmp.begin();
  if (!bmp.begin()) {
    Serial.println("erro na inicialização do BMP")
    while(1);
  }
  Serial.println("Sensor e SPI inicializados");
}

void loop() {
  float temperatura = bmp.readTemperature();
  float pressao = bmp.readPressure();
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  Serial.print("Pressão: ");
  Serial.println(pressao / 100);
  delay(2000);
}