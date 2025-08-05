//========================================================================
// HRSLinearSearch.cc
//========================================================================
// Handwritten recognition system that uses linear search.

#include "HRSLinearSearch.h"

#include "Image.h"
#include <cstddef>
#include <iostream>

//------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------

HRSLinearSearch::HRSLinearSearch() {}

//------------------------------------------------------------------------
// train
//------------------------------------------------------------------------

void HRSLinearSearch::train(const Vector<Image> &vec) { m_data = vec; }

//------------------------------------------------------------------------
// inference
//------------------------------------------------------------------------
// inference using linear search.

Image HRSLinearSearch::classify(const Image &img) {
  auto distance_func = [](const Image &img1, const Image &img2) {
    return img1.distance(img2);
  };

  return m_data.find_closest_linear(img, distance_func);
}
