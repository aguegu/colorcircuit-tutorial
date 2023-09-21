#include "neogoggles.h"

void setup(void) {

}

void loop(void) {
  origin[0] = knoblColor >> 4;
  origin[1] = knoblBrightnessr >> 4;
  origin[2] = knoblSpeed >> 4;
  project(knobSection >> 7, 1 << (knobPattern / (4096 / 5)));
}
