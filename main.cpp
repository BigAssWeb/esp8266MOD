#include <Arduino.h>

// Адреса заливки приложений
#define ADDR_APP1 0x00000
#define ADDR_APP2 0x10000
// Пропускаем заголовок ELF-файла (0x1000)
#define ENTRY_OFFSET 0x1000

typedef void (*app_entry_t)(void) __attribute__((noreturn));

void setup() {
  // Подтягиваем GPIO0 к VCC, нажатие (LOW) — выбор второй программы
  pinMode(0, INPUT_PULLUP);
  bool runSecond = digitalRead(0) == LOW;

  uint32_t addr = (runSecond ? ADDR_APP2 : ADDR_APP1) + ENTRY_OFFSET;
  app_entry_t userApp = reinterpret_cast<app_entry_t>(addr);
  
  // «Прыжок» в пользовательскую прошивку
  userApp();
}

void loop() {
  // Никогда не выполняется
}
