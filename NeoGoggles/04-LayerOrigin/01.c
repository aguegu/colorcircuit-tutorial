#include "neogoggles.h"

void setup(void) {

}

void loop(void) {
  origin[0] = knobColor >> 4;
  origin[4] = knobBrightness >> 4;
  origin[8] = knobSpeed >> 4;  
  project(knobSection >> 7, knobPattern >> 7);
}
