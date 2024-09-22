#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"
#include <cmath>

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int i = 0; i < width * height; ++i) {
    // Extract the RGB values from the input array
    double r = rgb[3 * i] / 255.0;
    double g = rgb[3 * i + 1] / 255.0;
    double b = rgb[3 * i + 2] / 255.0;

    // Convert RGB to HSV
    double h, s, v;
    rgb_to_hsv(r, g, b, h, s, v);

    // Apply the hue shift and wrap around if necessary
    h = fmod(h + shift, 360.0);
    if (h < 0) h += 360.0;  // Ensure the hue stays in the [0, 360] range

    // Convert back to RGB
    hsv_to_rgb(h, s, v, r, g, b);

    // Store the new RGB values in the output array (scaled back to [0, 255])
    shifted[3 * i] = static_cast<unsigned char>(r * 255);
    shifted[3 * i + 1] = static_cast<unsigned char>(g * 255);
    shifted[3 * i + 2] = static_cast<unsigned char>(b * 255);
  }
  ////////////////////////////////////////////////////////////////////////////
}
