#include "neogoggles.h"

void setup(void) {

}

void loop(void) {
  for (uint8_t i = 0; i < LED_LEN; i++) {
    setHSB(i, i * 360 / LED_LEN , 255, knobBrightness >> 6);
  }
  project(knobPattern >> 7, 1 << (knobSection / (4096 / 5)));
}
