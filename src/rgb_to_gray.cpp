#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  const int RED = 0;
  const int GREEN = 1;
  const int BLUE = 2;
  static const float RED_CO = 0.2126;
  static const float GREEN_CO = 0.7152;
  static const float BLUE_CO= 0.0722;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // gray[RED + 3 * (j + i * width)] = rgb[RED + 4 * (j + i * width)] * RED_CO;
      // gray[GREEN + 3 * (j + i * width)] = rgb[GREEN + 4 * (j + i * width)] * GREEN_CO;
      // gray[BLUE + 3 * (j + i * width)] = rgb[BLUE + 4 * (j + i * width)] * BLUE_CO;
      gray[j + i * width] = rgb[RED + 3 * (j + i * width)] * RED_CO + rgb[GREEN + 3 * (j + i * width)] * GREEN_CO + rgb[BLUE + 3 * (j + i * width)] * BLUE_CO;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}


