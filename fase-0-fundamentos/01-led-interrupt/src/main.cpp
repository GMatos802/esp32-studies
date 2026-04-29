#include <Arduino.h>

const uint8_t botao = 18;
volatile unsigned long ultimoPress = 0;
unsigned long delayDebounce = 50;
volatile bool pressed = false;
volatile int contador = 0;

void ARDUINO_ISR_ATTR buttonLed() {
  unsigned long present_time = millis();
    // ligar o led
    // detectar o bottao e jogar no serial
    // *debouce
    if (present_time - ultimoPress > delayDebounce) {
      pressed = true;
      contador++;
    }
    ultimoPress = present_time;

}

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  attachInterrupt(botao, buttonLed, FALLING);
}

void loop() {
  if (pressed) {
    Serial.print("botão pressionado! ");
    digitalWrite(2, !digitalRead(2));
    Serial.println(contador);
    pressed = false;
  }
}