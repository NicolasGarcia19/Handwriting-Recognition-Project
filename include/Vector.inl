//========================================================================
// Vector.inl
//========================================================================
// Implementation of Vector.

#include "sort.h"
#include <iostream>
#include <cassert>





//------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------

template <typename T>
Vector<T>::Vector()
{
  m_data = nullptr;
  m_size = 0;
  m_maxsize = 0;
}

//------------------------------------------------------------------------
// Desttructor
//------------------------------------------------------------------------

template <typename T>
Vector<T>::~Vector()
{
  delete[] m_data;
  m_data = nullptr;
  m_size = 0;
  m_maxsize = 0;
}

//------------------------------------------------------------------------
// Copy constructor from an array
//------------------------------------------------------------------------

template <typename T>
Vector<T>::Vector( T* data, int size )
{
  m_maxsize = size;
  m_size = size;
  m_data = new T[size];
  for(int i = 0; i < size; i ++) {
    m_data[i] = data[i];
  }
}

//------------------------------------------------------------------------
// Copy constructor
//------------------------------------------------------------------------

template <typename T>
Vector<T>::Vector( const Vector<T>& vec )
{
  m_size = vec.m_size;
  m_maxsize = vec.m_maxsize;
  m_data = new T[m_maxsize];
  for (int i = 0; i < m_size; i ++) {
    m_data[i] = vec.m_data[i];
  }
}

//------------------------------------------------------------------------
// size
//------------------------------------------------------------------------

template <typename T>
int Vector<T>::size() const
{
  return m_size;
}

//------------------------------------------------------------------------
// push_back
//------------------------------------------------------------------------
// Pushes a new value to the end of the Vector<T>

template <typename T>
void Vector<T>::push_back( const T& value )
{
  if (m_maxsize == 0) {
    m_maxsize = 1;
    m_data = new T[1];
  }
  if (m_size >= m_maxsize) {
    T *newdata = new T[(m_maxsize * 2)];
    for (int i = 0; i < m_size; i++) {
      newdata[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newdata;
    m_maxsize = m_maxsize * 2;
  }
  m_data[m_size] = value;
  m_size++;
}

//------------------------------------------------------------------------
// at (read)
//------------------------------------------------------------------------
// Does boundary check. Returns what value is at an idx.

template <typename T>
const T& Vector<T>::at( int idx ) const
{
  if (idx >= m_size || idx < 0) {
    throw ece2400::OutOfRange("Index not in range.");
  }
  return m_data[idx];
}

//------------------------------------------------------------------------
// at (write)
//------------------------------------------------------------------------
// Does boundary check. Returns what is at an idx

template <typename T>
T& Vector<T>::at( int idx )
{
  if (idx >= m_size || idx < 0) {
    throw ece2400::OutOfRange("Index not in range.");
  }
  
  return m_data[idx];
}

//------------------------------------------------------------------------
// contains
//------------------------------------------------------------------------
// Returns if a value is inside of the Vector<T>

template <typename T>
bool Vector<T>::contains( const T& value ) const
{
  for(int i = 0; i < m_size; i++) {
    if (m_data[i] == value) {
      return true;
    }
  }
  return false;
}

//------------------------------------------------------------------------
// find_closest_linear
//------------------------------------------------------------------------
// Return the value of the closest match that has the lowest index. For
// example, if a vector contains { 1, 5, 3, 7 }, then
// find_closest_linear( 4 ) should return 5 instead of 3.

template <typename T>
template <typename DistFunc>
T Vector<T>::find_closest_linear( const T& value, DistFunc dist ) const
{
  if (m_size == 0) {
    throw ece2400::OutOfRange("Can't find closest value because vector is empty.");
  }

  int closestdist;
  int currdist;
  int closestidx;

  for(int i = 0; i < m_size; i++) {
    currdist = dist(value,m_data[i]);

    if (i == 0) {
      closestdist = currdist;
      closestidx = 0;
    }
    else {
      if (currdist < closestdist) {
        closestdist = currdist;
        closestidx = i;
      }
    }
  }

  return m_data[closestidx];
}

//------------------------------------------------------------------------
// find_closest_binary
//------------------------------------------------------------------------
// Return the value of the closest match that has the lowest index.
// Because the vector must be sorted, this will also be the lowest value.
// For example, if a vector was initialized to { 1, 5, 3, 7 }, then it
// must be sorted to { 1, 3, 5, 7 } before binary search, and
// find_closest_binary( 4 ) should return 3 instead of 5.

template <typename T>
template <typename DistFunc, typename CmpFunc>
T Vector<T>::find_closest_binary( const T& value, int k, DistFunc dist,
                                  CmpFunc cmp ) const
{
  if (m_size == 0) {
    throw ece2400::OutOfRange("Can't find closest value because vector is empty.");
  }
  for(int i = 0; i < m_size - 1; i++) {
    if (cmp(m_data[i+1], m_data[i])) {
      throw ece2400::InvalidArgument("Can't binary search because vector isn't sorted.");
    }
  }

  int low = 0;
  int high = m_size - 1;
  int mid;
  int closestidx;
  int closestdist;
  int currdist;

  while (low <= high) {
    mid = low + (high - low) / 2;

    if (!cmp(m_data[mid],value) && !cmp(value,m_data[mid])) {
      break;
    } else if (cmp(m_data[mid], value)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  int max = mid + k;
  if (max > m_size - 1) {
    max = m_size - 1;
  }
  int min = mid - k;
  if (min < 0) {
    min = 0;
  }

  closestidx = min;
  closestdist = dist(value,m_data[min]);

  for(int i = min; i <= max; i++) {
    currdist = dist(value,m_data[i]);
    if(currdist < closestdist || (currdist == closestdist && cmp(m_data[i], m_data[closestidx]))) {
      closestdist = currdist;
      closestidx = i;
    }

  }
  return m_data[closestidx];
}

//------------------------------------------------------------------------
// sort
//------------------------------------------------------------------------
// Sorts the data in the Vector<T>

template <typename T>
template <typename CmpFunc>
void Vector<T>::sort( CmpFunc cmp )
{
  
  ::sort(m_data, m_size, cmp);
}

//------------------------------------------------------------------------
// operator[] (read)
//------------------------------------------------------------------------
// Does not do boundary check.

template <typename T>
const T& Vector<T>::operator[]( int idx ) const
{
  return m_data[idx];
}

//------------------------------------------------------------------------
// operator[] (write)
//------------------------------------------------------------------------
// Does not do boundary check.

template <typename T>
T& Vector<T>::operator[]( int idx )
{
  return m_data[idx];
}

//------------------------------------------------------------------------
// operator=
//------------------------------------------------------------------------

template <typename T>
Vector<T>& Vector<T>::operator=( const Vector<T>& vec )
{
  if (this == &vec) {
    return *this;
  }
  delete[] m_data;

  m_size = vec.m_size;
  m_maxsize = vec.m_maxsize;
  m_data = new T[m_maxsize];
  for (int i = 0; i < m_size; i++) {
    m_data[i] = vec.m_data[i];
  }
  return *this;
}

//------------------------------------------------------------------------
// print
//------------------------------------------------------------------------

template <typename T>
void Vector<T>::print() const {
  std::cout << "[";
  for (int i = 0; i < m_size; i++) {
    std::cout << m_data[i];
    if (i != m_size - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}
