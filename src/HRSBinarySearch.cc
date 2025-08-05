//========================================================================
// HRSBinarySearch.cc
//========================================================================
// Handwritten recognition system that uses binary search.

#include "HRSBinarySearch.h"

#include "IHandwritingRecSys.h"
#include "Image.h"
#include "Vector.h"
#include <cstddef>
#include <iostream>

//------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------

HRSBinarySearch::HRSBinarySearch(int K) : m_k(K) {}

//------------------------------------------------------------------------
// train
//------------------------------------------------------------------------

void HRSBinarySearch::train(const Vector<Image> &vec) {
  m_data = vec;

  m_data.sort([](const Image &a, const Image &b) {
    return a.get_intensity() < b.get_intensity();
  });
}

//------------------------------------------------------------------------
// classify
//------------------------------------------------------------------------
// classify using binary search.

Image HRSBinarySearch::classify(const Image &img) {
  auto dist_func = [](const Image &a, const Image &b) { return a.distance(b); };

  auto cmp_func = [](const Image &a, const Image &b) {
    return a.get_intensity() < b.get_intensity();
  };

  return m_data.find_closest_binary(img, m_k, dist_func, cmp_func);
}