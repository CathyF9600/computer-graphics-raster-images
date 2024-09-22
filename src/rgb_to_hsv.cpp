#include "rgb_to_hsv.h"
#include <algorithm>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  h = 0;
  s = 0;
  v = 0;
  // https://en.wikipedia.org/wiki/HSL_and_HSV#From_RGB

  double x_max = std::max({r,g,b});
  double x_min = std::min({r,g,b});

  v = x_max; // value

  double c = x_max - x_min; // chroma

  if (c == 0){
    h = 0;
  } else if (v == r) {
    h = 60 * (0 + (g-b)/c);
  } else if (v == g) {
    h = 60 * (2 + (b-r)/c);
  } else if (v == b) {
    h = 60 * (4 + (r-g)/c);
  } // hue

  if (v == 0) {
    s = 0;
  } else {
    s = c / v; // saturation
  }
  ////////////////////////////////////////////////////////////////////////////
}
