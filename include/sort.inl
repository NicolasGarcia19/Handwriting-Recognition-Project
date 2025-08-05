//========================================================================
// sort.inl
//========================================================================
// Definition of generic sort algorithm.


#include "ece2400-stdlib.h"
#include "sort.h"
#include <cassert>

//------------------------------------------------------------------------
// partition(T* a, int begin, int end, Cmp cmp)
//------------------------------------------------------------------------
// partitions a data set into two based on a median of three pivot selection
template < typename T, typename Cmp>
int partition(T* a, int begin, int end, Cmp cmp) {
  assert(begin <= end);
  if (begin == end - 1) {
    return begin;
  }
  if ((end - begin) == 2) {
    if (cmp(a[end-1], a[begin])) {
      T tmp = a[begin];
      a[begin] = a[end - 1];
      a[end-1] = tmp;
    }
    return begin + 1;
  }

  int mid = begin + ((end - begin) / 2);

  if (cmp(a[mid], a[begin])) {
    T tmp = a[begin];
    a[begin] = a[mid];
    a[mid] = tmp;
  }
  if (cmp(a[end-1], a[begin])) {
    T tmp = a[begin];
    a[begin] = a[end - 1];
    a[end - 1] = tmp;
  }
  if (cmp(a[end-1], a[mid])) {
    T tmp = a[mid];
    a[mid] = a[end - 1];
    a[end - 1] = tmp;
  }

  T pivot = a[mid];
  T temp = a[mid];
  a[mid] = a[end-1];
  a[end-1] = temp;

  int left = begin;
  int right = end - 2;

  while (left <= right) {
    while (left <= right && (cmp(a[left],pivot) ||(!cmp(a[left],pivot) && !cmp(pivot,a[left])))) {
      left++;
    }
    while (left<=right && cmp(pivot,a[right])) {
      right--;
    }
    
    if (left < right) {
      T swap = a[left];
      a[left] = a[right];
      a[right] = swap;
      left++;
      right--;
    }
  }

  T swap = a[left];
  a[left] = a[end-1];
  a[end-1] = swap;

  return left;
}

//------------------------------------------------------------------------
// sort_helper(T* a, int begin, int end, Cmp cmp)
//------------------------------------------------------------------------
// calls partition in smaller and smaller intervals
template < typename T, typename Cmp>
void sort_helper(T* a, int begin, int end, Cmp cmp) {
  if (begin < end-1) {
    int pindex = partition(a, begin, end, cmp);
    if (pindex > begin) {
      sort_helper(a, begin, pindex, cmp);
    }
    if (pindex+1 < end) {
      sort_helper(a,pindex+1, end, cmp);
    }
  }
}

//------------------------------------------------------------------------
// sort(T* a, int size, Cmp cmp)
//------------------------------------------------------------------------
// Starts quick sort and checks for edge cases
template <typename T, typename Cmp>
void sort( T* a, int size, Cmp cmp )
{
  if (a == nullptr || size <= 1) {
    return;
  }
  sort_helper(a, 0, size, cmp);
  return;
}