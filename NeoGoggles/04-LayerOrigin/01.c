#include "neogoggles.h"

void setup(void) {

}

void loop(void) {
  origin[0] = knobColor >> 4;
  origin[1] = knobBrightness >> 4;
  origin[2] = knobSpeed >> 4;
  project(knobPattern >> 7, 1 << (knobSection / (4096 / 5)));
}
