#ifndef ANALOG_MUX_H
#define ANALOG_MUX_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct AnalogMux8 {
  uint8_t selectorPin0; // Least significant bit.
  uint8_t selectorPin1;
  uint8_t selectorPin2; // Most significant bit.

  uint8_t analogPin; // Where we read or write the value.
  uint8_t analogPinDirection; // OUTPUT=1, INPUT=0

  uint16_t delayAfterSelection; // Delay between selection and using the analog pin to allow the mux to settle.
};

void analogMux8_init(const struct AnalogMux8 *self);

uint32_t analogMux8_read(const struct AnalogMux8 *self, uint8_t selector);

void analogMux8_write(const struct AnalogMux8 *self, uint8_t selector, uint32_t value);

void analogMux8_select(const struct AnalogMux8 *self, uint8_t selector);

#ifdef __cplusplus
}
#endif

#endif
