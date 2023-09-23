#include "neogoggles.h"

void setup(void) {}

void loop(void) {
  static uint8_t step = 0;
  uint8_t sections = 1 << (knobSection / (4095 / 5));
  uint8_t interval = 1 << (knobSpeed >> 9);

  for (uint8_t i = 0; i < LED_LEN; i++) {
    setHSB(i, (i + knobColor / (4096 / LED_LEN)) * 360 / LED_LEN , 255, knobBrightness >> 6);
  }

  project(step, sections);

  if (!(getJiffies() % interval)) {
    step++;
  }
}
