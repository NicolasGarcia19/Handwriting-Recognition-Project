//========================================================================
// Image.h
//========================================================================
// Declarations for Image.

#ifndef IMAGE_H
#define IMAGE_H

#include "Vector.h"
#include "ece2400-stdlib.h"
#include <cstddef>
#include <functional>
#include <iostream>

class Image {
public:
  // Constructors
  Image();
  Image(const Vector<int> &vec, int ncols, int nrows);

  // Methods
  int get_ncols() const;
  int get_nrows() const;
  int at(int x, int y) const;
  void set_label(char l);
  char get_label() const;
  int get_intensity() const;
  int distance(const Image &other) const;
  void print() const;
  void display() const;

  // Operator overloading
  bool operator==(const Image &rhs) const;
  bool operator!=(const Image &rhs) const;

  const int &operator[](int idx) const;

  friend std::ostream &operator<<(std::ostream &output, const Image &image);

private:
  Vector<int> m_pixels;
  int m_ncols;
  int m_nrows;
  char m_label;
  mutable int m_intensity = -1;
};

// Include inline definitions
#include "Image.inl"

#endif // IMAGE_H
