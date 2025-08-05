//========================================================================
// Image.cc
//========================================================================
// Implementations for Image.

#include "Image.h"

#include "ece2400-stdlib.h"
#include <cassert>
#include <iostream>

// default constructor
Image::Image()
    : m_pixels(), m_ncols(0), m_nrows(0), m_label('?'), m_intensity(-1) {}

// non-default constructor
Image::Image(const Vector<int> &vec, int ncols, int nrows)
    : m_pixels(vec), m_ncols(ncols), m_nrows(nrows), m_label('?'),
      m_intensity(-1) {
  if (vec.size() != (ncols * nrows)) {
    throw ece2400::InvalidArgument(
        "Vector size does not match image dimensions.");
  }

  // calculates the intensity in the constructor
  int sum = 0;
  for (int i = 0; i < vec.size(); i++) {
    sum = sum + vec[i];
  }
  m_intensity = sum;
}

// simple accessors
int Image::get_ncols() const { return m_ncols; }
int Image::get_nrows() const { return m_nrows; }
int Image::at(int x, int y) const {
  if (y < 0 || x < 0 || y >= m_nrows || x >= m_ncols) {
    throw ece2400::OutOfRange("Pixel (x,y) out of range");
  }
  return m_pixels[(m_ncols * y) + x];
}

// label helpers
char Image::get_label() const { return m_label; }
void Image::set_label(char l) { m_label = l; }

// Intensity Getter
int Image::get_intensity() const {
  if (m_intensity == -1) {
    int sum = 0;
    for (int i = 0; i < m_pixels.size(); i++) {
      sum = sum + m_pixels[i];
    }
    m_intensity = sum;
  }
  return m_intensity;
}

// Calculates the Euclidian Distance
int Image::distance(const Image &other) const {
  if (m_ncols != other.m_ncols || m_nrows != other.m_nrows) {
    throw ece2400::InvalidArgument("Image sizes don't match.");
  }
  int sum = 0;
  for (int i = 0; i < m_pixels.size(); i++) {
    int diff = m_pixels[i] - other.m_pixels[i];
    sum = sum + (diff * diff);
  }
  return sum;
}

// Equality & Inequality Overloads
bool Image::operator==(const Image &rhs) const {
  if (m_ncols != rhs.m_ncols || m_nrows != rhs.m_nrows) {
    return false;
  }
  for (int i = 0; i < m_pixels.size(); i++) {
    if (m_pixels[i] != rhs.m_pixels[i]) {
      return false;
    }
  }
  return true;
}
bool Image::operator!=(const Image &rhs) const { return !(*this == rhs); }

// returns the pixel at a certain idx of the image
const int &Image::operator[](int idx) const { return m_pixels[idx]; }

//------------------------------------------------------------------------
// print
//------------------------------------------------------------------------

void Image::print() const {
  std::cout << "label: " << this->get_label() << std::endl;
  std::cout << "intensity: " << this->get_intensity() << std::endl;
}

//------------------------------------------------------------------------
// print_pixel
//------------------------------------------------------------------------
// A helper function that prints a grayscale pixel using unicode based on
// the integer value.

void print_pixel(int v) {
  if (v <= 0)
    std::cout << "  ";
  else if (0 < v && v <= 64)
    std::cout << "\u2591\u2591";
  else if (64 < v && v <= 128)
    std::cout << "\u2592\u2592";
  else if (128 < v && v <= 192)
    std::cout << "\u2593\u2593";
  else
    std::cout << "\u2588\u2588";
}

//------------------------------------------------------------------------
// display
//------------------------------------------------------------------------

void Image::display() const {
  int nrows = this->get_nrows();
  int ncols = this->get_ncols();

  for (int y = 0; y < nrows; y++) {
    for (int x = 0; x < ncols; x++) {
      print_pixel(this->at(x, y));
    }
    std::cout << "\n";
  }
}

//------------------------------------------------------------------------
// operator<<
//------------------------------------------------------------------------

std::ostream &operator<<(std::ostream &output, const Image &image) {
  output << image.get_intensity() << "{" << image.get_label() << "}";
  return output;
}
