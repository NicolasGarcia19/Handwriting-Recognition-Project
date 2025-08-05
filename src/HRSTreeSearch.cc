//========================================================================
// HRSTreeSearch.cc
//========================================================================
// Definitions for HRSTreeSearch

#include "HRSTreeSearch.h"

#include "Image.h"
#include "Tree.h"
#include "Vector.h"

//------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------

HRSTreeSearch::HRSTreeSearch(int K) : m_training_set(K, ImgCmpFunc()), m_k(K) {}

//------------------------------------------------------------------------
// train
//------------------------------------------------------------------------

void HRSTreeSearch::train(const Vector<Image> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    m_training_set.add(vec[i]);
  }
}

//------------------------------------------------------------------------
// classify
//------------------------------------------------------------------------

Image HRSTreeSearch::classify(const Image &img) {
  auto dist_func = [](const Image &a, const Image &b) { return a.distance(b); };

  return m_training_set.find_closest(img, dist_func);
}