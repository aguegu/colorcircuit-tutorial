#include "neogoggles.h"

void setup(void) {

}

void loop(void) {
  setHue(0, knobBrightness >> 4, knobColor >> 4, knobSpeed >> 4);
  project(knobPattern >> 7, 1 << (knobSection / (4096 / 5)));
}
