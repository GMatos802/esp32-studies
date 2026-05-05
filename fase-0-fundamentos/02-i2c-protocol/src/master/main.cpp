#include <Arduino.h>
#include <Wire.h>

#define SLAVE_ADDR 0x08 

void setup() {
    Wire.begin(21, 22);
    pinMode(21, INPUT_PULLUP);
    pinMode(22, INPUT_PULLUP);
    Serial.begin(115200);
    Serial.println("Master inicializada!");
}

void loop() {
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write("ping");
    byte erro = Wire.endTransmission();

    if (erro != 0) {
        Serial.println("Slave nao encontrada");
        delay(1000);
        return;
    }

    delay(10);
    Wire.requestFrom(SLAVE_ADDR, 4);
    Serial.println("Slave respondeu!");
    while (Wire.available()) {
        Serial.print((char)Wire.read());
    }
    Serial.println();
    delay(1000);

}