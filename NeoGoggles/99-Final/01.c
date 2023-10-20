#include "neogoggles.h"

const uint8_t routesDefault[] = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
  28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7, 24, 25, 26, 27, 20, 21, 22, 23, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  7, 5, 3, 1, 0, 2, 4, 6, 8, 10, 12, 14, 15, 13, 11, 9, 23, 21, 19, 17, 16, 18, 20, 22, 24, 26, 28, 30, 31, 29, 27, 25,
  0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31,
};

uint8_t step = 0;
uint16_t m, mSpan = 0, mMax = 0, mMin = 4095;

uint8_t routeIndex = 0;

void setup(void) {
  initRoutes(routesDefault, sizeof(routesDefault));
}

void loop(void) {
  if (btnRouteLast && !btnRouteNow) {
    setRouteIndex(++routeIndex);
  }

  uint8_t w0 = 1 << (knobSpeed >> 9);  // speed
  uint8_t w1 = 1 << ((255 - (knobSection >> 4)) / 43);  // section
  uint8_t l = LED_LEN / w1;
  uint16_t w3 = 4095 - knobColor;  // color
  uint8_t w4 = ((255 - (knobBrightness >> 4)) >> 3) + 1; // brightness
  uint8_t w5 = 255 - (knobPattern >> 4); // pattern

  mMax = mic > mMax ? mic : mMax;
  mMin = mic < mMin ? mic : mMin;

  if (!(getJiffies() & 0x07)) {
    mSpan = ((mMax - mMin) >> 1) + (mSpan >> 1);
    mMax = mic;
    mMin = mic;
  }

  switch (w5 & 0xc0) {
    case 0x00:
      memset(origin, 0x00, FRAMEBUFFER_LEN);
      setHSB(0, w3 / 11 - (mSpan << 3), w3 < 3600 ? 0xff : 0x00, w4);
      break;
    case 0x40:
      memset(origin, 0x00, FRAMEBUFFER_LEN);
      uint8_t tail = w4;
      uint8_t k = 0;
      while (tail) {
        setHSB(k++, w3 / 11, w3 < 3600 ? 0xff : 0x00, tail);
        tail >>= 1;
      }
      break;
    case 0x80:
      for (uint8_t i = 0; i < l; i++) {
        setHSB(i, i * 360 / l + w3 / 11, 0xff, w4);
      }
      break;
    case 0xc0:
      for (uint8_t i = 0; i < l; i++) {
        setHSB(i, i * 180 / l + w3 / 11, 0xff, w4);
      }
      break;
  }

  if (getJiffies() % w0) {
    project(step, w1);
  } else {
    project(step++, w1);
  }

  if (w5 & 0x10) {
    reverse(frameBuffer, 0, LED_LEN - 1);
  }

  if (w5 & 0x20 && w1 > 1 && w1 < LED_LEN) {
    for (uint8_t i = 1; i < w1; i+=2) {
      reverse(frameBuffer, l * i, l * (i + 1) - 1);
    }
  }
}
