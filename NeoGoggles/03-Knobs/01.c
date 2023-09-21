#include "neogoggles.h"

void setup(void) {

}

void loop(void) {
  for (uint8_t i = 0; i < LED_LEN; i++) {
    if (i >= knobSection / 128  && i < knobPattern / 128) {
      frameBuffer[i + 0] = knobColor >> 4;
      frameBuffer[i + 1] = knobBrightness >> 4;
      frameBuffer[i + 2] = knobSpeed >> 4;
    } else {
      frameBuffer[i + 0] = 0;
      frameBuffer[i + 1] = 0;
      frameBuffer[i + 2] = 0;
    }
  }
}
