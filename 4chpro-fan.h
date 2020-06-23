#include "esphome.h"
using namespace esphome;

#define PIN_1 12
#define PIN_2 5
#define PIN_3 4

class Sonoff4CHProFan : public Component, public FloatOutput {
  public:
    void write_state(float state) override {
      if (state < 0.3) {
        // OFF
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_2, LOW);
        digitalWrite(PIN_3, LOW);
      } else if (state < 0.6) {
        // low speed
        digitalWrite(PIN_1, HIGH);
        digitalWrite(PIN_2, LOW);
        digitalWrite(PIN_3, LOW);
      } else if (state < 0.9) {
        // medium speed
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_2, HIGH);
        digitalWrite(PIN_3, LOW);
      } else {
        // high speed
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_2, LOW);
        digitalWrite(PIN_3, HIGH);
      }
    }
};