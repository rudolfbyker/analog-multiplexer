#include "analogMux.h"

struct AnalogMux8 mux0;

void setup() {
  // Arduino Due has 12-bit ADCs.
  analogReadResolution(12);

  mux0 = {
    .selectorPin0=2,
    .selectorPin1=3,
    .selectorPin2=4,
    .analogPin=A0,
    .analogPinDirection=INPUT,
    .delayAfterSelection=10
  };
  analogMux8_init(&mux0);

  Serial.begin(9600);
}

void loop() {
  uint32_t value = 0;
  uint8_t selector = 0;
  uint8_t n_mux_inputs = 8;
  uint16_t delay_between_cycles = 1000;

  for (selector=0; selector<n_mux_inputs; selector++) {
    value = analogMux8_read(&mux0, selector);
    Serial.print(value);
    if (selector<n_mux_inputs-1) {
      Serial.print(",");
    }
  }
  Serial.println();
  delay(delay_between_cycles);
}
