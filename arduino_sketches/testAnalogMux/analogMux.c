#include <stdint.h>
#include "analogMux.h"

void analogMux8_init(const struct AnalogMux8 *const self) {
  pinMode(self->selectorPin0, 1); // OUTPUT
  pinMode(self->selectorPin1, 1); // OUTPUT
  pinMode(self->selectorPin2, 1); // OUTPUT
  pinMode(self->analogPin, self->analogPinDirection);
}

uint32_t analogMux8_read(const struct AnalogMux8 *const self, uint8_t selector) {
  analogMux8_select(self, selector);
  delay(self->delayAfterSelection);
  return analogRead(self->analogPin);
}

void analogMux8_write(const struct AnalogMux8 *const self, uint8_t selector, uint32_t value) {
  analogMux8_select(self, selector);
  delay(self->delayAfterSelection);
  return analogWrite(self->analogPin, value);
}

void analogMux8_select(const struct AnalogMux8 *const self, uint8_t selector) {
  digitalWrite(self->selectorPin0, (selector & (1 << 0)) >> 0);
  digitalWrite(self->selectorPin1, (selector & (1 << 1)) >> 1);
  digitalWrite(self->selectorPin2, (selector & (1 << 2)) >> 2);
}
