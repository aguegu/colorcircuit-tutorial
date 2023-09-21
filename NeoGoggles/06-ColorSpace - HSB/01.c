#include "neogoggles.h"

void setup(void) {

}

void loop(void) {
  setHSB(0, knobColor / 11, 255, knobBrightness >> 6);
  project(knobPattern >> 7, 1 << (knobSection / (4096 / 5)));
}
