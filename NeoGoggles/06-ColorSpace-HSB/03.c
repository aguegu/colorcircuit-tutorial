#include "neogoggles.h"

void setup(void) {

}

void loop(void) {
  setHSB(0, knobColor / 10, knobColor <= 3600 ? 255 : 0, knobBrightness >> 6);
  project(knobPattern >> 7, 1 << (knobSection / (4096 / 5)));
}
