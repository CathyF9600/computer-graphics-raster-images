#include "hsv_to_rgb.h"
#include <cmath>
#include <algorithm> // For min and max functions

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  // If saturation is zero, the color is grayscale (R = G = B = V)
  if (s == 0) {
    r = v;
    g = v;
    b = v;
    return;
  }

  double hh = h / 60.0; // Hue sector (0 to 5)
  int i = static_cast<int>(hh); // Integer part of hh
  double ff = hh - i;  // Fractional part of hh
  double p = v * (1.0 - s); 
  double q = v * (1.0 - s * ff);
  double t = v * (1.0 - s * (1.0 - ff));

  // Assign RGB values based on the hue sector
  switch (i) {
    case 0:
      r = v; g = t; b = p;
      break;
    case 1:
      r = q; g = v; b = p;
      break;
    case 2:
      r = p; g = v; b = t;
      break;
    case 3:
      r = p; g = q; b = v;
      break;
    case 4:
      r = t; g = p; b = v;
      break;
    case 5:
    default:
      r = v; g = p; b = q;
      break;
  }
}
