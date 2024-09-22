#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  const int RED = 0;
  const int GREEN = 1;
  const int BLUE = 2;
  
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      rgb[RED + 3 * (j + i * width)] = rgba[RED + 4 * (j + i * width)];
      rgb[GREEN + 3 * (j + i * width)] = rgba[GREEN + 4 * (j + i * width)];
      rgb[BLUE + 3 * (j + i * width)] = rgba[BLUE + 4 * (j + i * width)];
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}


// void rgba_to_rgb(
//   const std::vector<unsigned char> & rgba,
//   const int & width,
//   const int & height,
//   std::vector<unsigned char> & rgb)
// {
//   rgb.resize(height*width*3);
//   ////////////////////////////////////////////////////////////////////////////
//   // Add your code here
//   ////////////////////////////////////////////////////////////////////////////
//   // This assignment stores pixels in R, G, B order.
//   static const int RED = 0;
//   static const int GREEN = 1;
//   static const int BLUE = 2;
//   static const int ALPHA = 2;

//   // Use (i,j) to represent (row,column) of input.
//   for (int i = 0; i < height; i++){
//     for (int j = 0; j < width; j++) {
//       // Take RGB values from RGBA (ignoring alpha channel).
//       rgb[RED + 3*(j + i*width)] = rgba[RED + 4*(j + i*width)];
//       rgb[GREEN + 3*(j + i*width)] = rgba[GREEN + 4*(j + i*width)];
//       rgb[BLUE + 3*(j + i*width)] = rgba[BLUE + 4*(j + i*width)];
//     }
//   }
// }
