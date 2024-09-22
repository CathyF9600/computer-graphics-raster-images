#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  const int RED = 0;
  const int GREEN = 1;
  const int BLUE = 2;
  float avg_red, avg_green, avg_blue;
  float count_red, count_green, count_blue;  
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      avg_red = 0.0;
      avg_green = 0.0;
      avg_blue = 0.0;
      count_red = 0;
      count_green = 0;
      count_blue = 0;
      // G B | G B
      // R G | R G
      // G B | G B
      // R G | R G
      if (i % 2 == 0 && j % 2 == 0) { // if the current pixel is top left G
        if (i >= 1) { // if there exists a top pixel (i-1,j)
          avg_red += bayer[j + (i-1)*width];
          count_red ++;
        }
        if (i <= height-2) { // if there exists a bottom pixel (i+1,j)
          avg_red += bayer[j + (i+1)*width];
          count_red ++;
        }
        if (j >= 1) { // if there exists a left  pixel (i,j-1)
          avg_blue += bayer[j-1 + i*width];
          count_blue ++;
        }
        if (j <= width-2) { // if there exists a right pixel (i,j+1)
          avg_blue += bayer[j+1 + i*width];
          count_blue ++;
        }
        if (count_red > 0) {
          avg_red = avg_red / count_red;
        }
        if (count_blue > 0) {
          avg_blue = avg_blue / count_blue;
        }
        rgb[RED + 3 * (j + i *width)] = avg_red;
        rgb[GREEN + 3 * (j + i*width)] = bayer[j + i*width];
        rgb[BLUE + 3 * (j + i*width)] = avg_blue;
      } else if (i % 2 == 0 && j % 2 == 1) { // if the current pixel is B
        // G B | G B
        // R G | R G
        // G B | G B
        // R G | R G
        if (i >= 1 && j >= 1) { // if there exists a top left pixel (i-1, j-1)
            avg_red += bayer[j-1 + (i-1)*width];
            count_red++;
          }
          if (i >= 1 && j <= width-2) { // if there exists a top right pixel (i-1, j+1)
            avg_red += bayer[j+1 + (i-1)*width];
            count_red++;
          }
          if (i <= height-2 && j >= 1) { // if there exists a bottom left pixel (i+1, j-1)
            avg_red += bayer[j-1 + (i+1)*width];
            count_red++;
          }
          if (i <= height-2 && j <= width-2) { // if there exists a bottom right pixel (i+1, j+1)
            avg_red += bayer[j+1 + (i+1)*width];
            count_red++;
          }
          if (i >= 1) { // if there exists a top pixel (i-1, j)
            avg_green += bayer[j + (i-1)*width];
            count_green++;
          }
          if (i <= height-2) {// if there exists a bottom pixel (i+1, j)
            avg_green += bayer[j + (i+1)*width];
            count_green++;
          }
          if (j >= 1) { // if there exists a left pixel (i, j-1)
            avg_green += bayer[j-1 + i*width];
            count_green++;
          }
          if (j <= width-2) { // if there exists a right pixel (i, j+1)
            avg_green += bayer[j+1 + i*width];
            count_green++;
          }
          if (count_red > 0) {
            avg_red = avg_red / count_red;
          }
          if (count_green > 0) {
            avg_green = avg_green / count_green;
          }
          rgb[RED + 3*(j + i*width)] = avg_red;
          rgb[GREEN + 3*(j + i*width)] = avg_green;
          rgb[BLUE + 3*(j + i*width)] = bayer[j + i*width];
      } else if (i % 2 == 1 && j % 2 == 0) { // if the current pixel is R
        // G B | G B
        // R G | R G
        // G B | G B
        // R G | R G
          if (i >= 1 && j >= 1) { // if there exists a top left pixel (i-1, j-1)
            avg_blue += bayer[j-1 + (i-1)*width];
            count_blue++;
          }
          if (i >= 1 && j <= width-2) { // if there exists a top right pixel (i-1, j+1)
            avg_blue += bayer[j+1 + (i-1)*width];
            count_blue++;
          }
          if (i <= height-2 && j <= width-2) { // if there exists a bottom right pixel (i+1, j+1)
            avg_blue += bayer[j+1 + (i+1)*width];
            count_blue++;
          }
          if (i <= height-2 && j >= 1) { // if there exists a bottom left pixel (i+1, j-1)
            avg_blue += bayer[j-1 + (i+1)*width];
            count_blue++;
          }
          if (i >= 1) { // if there exists a top pixel (i-1, j)
            avg_green += bayer[j + (i-1)*width];
            count_green++;
          }
          if (i <= height-2) {
            avg_green += bayer[j + (i+1)*width]; // bottom pixel (i+1, j)
            count_green++;
          }
          if (j >= 1) {
            avg_green += bayer[j-1 + i*width]; // left pixel (i, j-1)
            count_green++;
          }
          if (j <= width-2) {
            avg_green += bayer[j+1 + i*width]; // right pixel (i, j+1)
            count_green++;
          }
          if (count_blue > 0) {
            avg_blue = avg_blue / count_blue;
          }
          if (count_green > 0) {
            avg_green = avg_green / count_green;
          }

          rgb[RED + 3*(j + i*width)] = bayer[j + i*width];
          rgb[GREEN + 3*(j + i*width)] = avg_green;
          rgb[BLUE + 3*(j + i*width)] = avg_blue;

        } else if (i % 2 == 1 && j % 2 == 1) { // if the current pixel is bottom right G
          if (i >= 1) {
            avg_blue += bayer[j + (i-1)*width]; // top pixel (i-1, j)
            count_blue++;
          }
          if (i <= height-2) {
            avg_blue += bayer[j + (i+1)*width]; // bottom pixel (i+1, j)
            count_blue++;
          }

          if (j >= 1) {
            avg_red += bayer[j-1 + i*width]; // left pixel (i, j-1)
            count_red++;
          }
          if (j <= width-2) {
            avg_red += bayer[j+1 + i*width]; // right pixel (i, j+1)
            count_red++;
          }

          if (count_red > 0) {
            avg_red = avg_red / count_red;
          }
          if (count_blue > 0) {
            avg_blue = avg_blue / count_blue;
          }

          rgb[RED + 3*(j + i*width)] = avg_red;
          rgb[GREEN + 3*(j + i*width)] = bayer[j + i*width];
          rgb[BLUE + 3*(j + i*width)] = avg_blue;
        
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
