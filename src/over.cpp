#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // C = A over B -> c = c(a)a(a) + c(b)a(b)(1-a(a))
  // https://en.wikipedia.org/wiki/Alpha_compositing#Straight_versus_premultiplied
  const int RED = 0;
  const int GREEN = 1;
  const int BLUE = 2;
  const int ALPHA = 3;
  double alpha_A, alpha_B;
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++) {
      alpha_A = A[ALPHA + 4 * (j + i * width)] / 255.0;
      alpha_B = B[ALPHA + 4 * (j + i * width)] / 255.0;
      C[ALPHA + 4 * (j + i * width)] = alpha_A + alpha_B * (1 - alpha_A);
      C[RED + 4 * (j + i * width)] = alpha_A * A[RED + 4 * (j + i * width)] + (1 - alpha_A) * alpha_B * B[RED + 4 * (j + i * width)];
      C[BLUE + 4 * (j + i * width)] = alpha_A * A[BLUE + 4 * (j + i * width)] + (1 - alpha_A) * alpha_B * B[BLUE + 4 * (j + i * width)];
      C[GREEN + 4 * (j + i * width)] = alpha_A * A[GREEN + 4 * (j + i * width)] + (1 - alpha_A) * alpha_B * B[GREEN + 4 * (j + i * width)];
      C[ALPHA + 4 * (j + i * width)] *= 255;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
