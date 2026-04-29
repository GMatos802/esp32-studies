# 01 — LED com Interrupção e Contador

## O que faz
Detecta o aperto de um botão via interrupção de hardware (GPIO 18),
togla um LED externo (GPIO 2) e imprime um contador no Serial.

## Conceitos aprendidos
- `ARDUINO_ISR_ATTR`: coloca a ISR na IRAM para execução rápida e segura
- `volatile`: impede que o compilador otimize variáveis compartilhadas entre ISR e loop
- `INPUT_PULLUP`: usa resistor interno, botão conectado ao GND → trigger FALLING
- A ISR só seta flags — o loop faz o trabalho pesado (Serial, GPIO)
- Debounce por software: janela de 50ms para ignorar bouncing mecânico

## Circuito
- Botão: GPIO 18 → GND (INPUT_PULLUP ativo)
- LED interno: GPIO 2

## Bug encontrado
`LED_BUILTIN` não existe neste DevKit — necessário usar GPIO 2 como LED interno.
Serial com símbolos estranhos → corrigido com `monitor_speed = 115200` no platformio.ini.

## Como rodar
1. Instalar PlatformIO no VS Code
2. Abrir a pasta do projeto
3. Upload para ESP32 DevKit 30 pinos
4. Abrir Serial Monitor a 115200 baud
