#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // Convert RGB to HSV
  double h, s, v;
  const int RED = 0;
  const int GREEN = 1;
  const int BLUE = 2;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Extract the RGB values from the input array
      double r = rgb[RED + 3 * (i*width + j)] / 255.0;
      double g = rgb[GREEN + 3 * (i*width + j)] / 255.0;
      double b = rgb[BLUE + 3 * (i*width + j)] / 255.0;
      rgb_to_hsv(r, g, b, h, s, v);
      hsv_to_rgb(h, s * (1-factor), v, r, g, b);
      desaturated[RED + 3 * (i*width + j)] = static_cast<unsigned char>(r * 255);
      desaturated[GREEN + 3 * (i*width + j)] = static_cast<unsigned char>(g * 255);
      desaturated[BLUE + 3 * (i*width + j)] = static_cast<unsigned char>(b * 255);
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
