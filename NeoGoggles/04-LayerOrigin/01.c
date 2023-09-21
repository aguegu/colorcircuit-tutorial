#include "neogoggles.h"

void setup(void) {

}

void loop(void) {
  origin[0] = knobColor >> 4;
  origin[1] = knobBrightnessr >> 4;
  origin[2] = knobSpeed >> 4;
  project(knobSection >> 7, 1 << (knobPattern / (4096 / 5)));
}
