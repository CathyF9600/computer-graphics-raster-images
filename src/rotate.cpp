#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      for (int k = 0; k < num_channels; k++) {
        rotated[k + num_channels * (i + height * (width - 1 - j))] = input[k + num_channels*(j + width * i)];
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
