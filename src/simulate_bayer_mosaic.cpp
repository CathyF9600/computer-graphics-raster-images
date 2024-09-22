#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // G B | G B
  // R G | R G
  // G B | G B
  // R G | R G
  const int RED = 0;
  const int GREEN = 1;
  const int BLUE = 2;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // gray[RED + 3 * (j + i * width)] = rgb[RED + 4 * (j + i * width)] * RED_CO;
      // gray[GREEN + 3 * (j + i * width)] = rgb[GREEN + 4 * (j + i * width)] * GREEN_CO;
      // gray[BLUE + 3 * (j + i * width)] = rgb[BLUE + 4 * (j + i * width)] * BLUE_CO;
      if (i % 2 == 1 && j % 2 == 0) {
        bayer[j + i * width] = rgb[RED + 3 * (j + i * width)];
      } else if (i % 2 == 0 && j % 2 == 1) {
        bayer[j + i * width] = rgb[BLUE + 3 * (j + i * width)];
      } else {
        bayer[j + i * width] = rgb[GREEN + 3 * (j + i * width)];
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
