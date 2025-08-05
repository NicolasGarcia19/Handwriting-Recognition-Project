//========================================================================
// tree-adhoc.cc
//========================================================================
// This file contains an ad-hoc test for tree.

#include "Tree.h"
#include "ece2400-stdlib.h"
#include <cstdio>
#include <functional>

int main() {
  Tree<int, std::function<int(int, int)>> tree(10, ece2400::less);

  for (int v : {55, 20, 74, 5, 43, 59, 99, 12, 32})
    tree.add(v);

  tree.print();

  std::printf("\n");

  return 0;
}
