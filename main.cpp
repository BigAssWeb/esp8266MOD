#include <Arduino.h>

#define LED_PIN 2  // GPIO2, часто используется как выход для светодиода

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Устанавливаем пин в режим вывода
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // Включаем светодиод
  delay(2000);                  // Ждём 1 секунду
  digitalWrite(LED_PIN, LOW);   // Выключаем светодиод
  delay(2000);                  // Ждём 1 секунду
}
