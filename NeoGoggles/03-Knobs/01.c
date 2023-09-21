#include "neogoggles.h"

void setup(void) {

}

void loop(void) {
  for (uint8_t i = 0; i < LED_LEN; i++) {
    uint8_t j = i * 3;
    if (i >= knobSection / 128  && i <= knobPattern / 128) {
      frameBuffer[j + 0] = knobColor >> 4;
      frameBuffer[j + 1] = knobBrightness >> 4;
      frameBuffer[j + 2] = knobSpeed >> 4;
    } else {
      frameBuffer[j + 0] = 0;
      frameBuffer[j + 1] = 0;
      frameBuffer[j + 2] = 0;
    }
  }
}
