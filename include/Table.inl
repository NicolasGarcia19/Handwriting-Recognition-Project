//========================================================================
// Table.inl
//========================================================================
// Implementation of Table.

#include "Vector.h"
#include "ece2400-stdlib.h"
#include <cassert>

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement Table.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

//------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------

template <typename T, typename HashFunc>
Table<T, HashFunc>::Table( int k, HashFunc hash )
{
  assert(false && "TODO: Table<T, HashFunc>::Table( int k, HashFunc hash )");
}

//------------------------------------------------------------------------
// size
//------------------------------------------------------------------------

template <typename T, typename HashFunc>
int Table<T, HashFunc>::size() const
{
  assert(false && "TODO: Table<T, HashFunc>::size()");
  return 0;
}

//------------------------------------------------------------------------
// add
//------------------------------------------------------------------------

template <typename T, typename HashFunc>
void Table<T, HashFunc>::add( const T& value )
{
  assert(false && "TODO: Table<T, HashFunc>::add( const T& value )");
}

//------------------------------------------------------------------------
// contains
//------------------------------------------------------------------------

template <typename T, typename HashFunc>
bool Table<T, HashFunc>::contains( const T& value ) const
{
  assert(false && "TODO: Table<T, HashFunc>::contains( const T& value )");
  return false;
}

//------------------------------------------------------------------------
// find_closest
//------------------------------------------------------------------------

template <typename T, typename HashFunc>
template <typename DistFunc>
T Table<T, HashFunc>::find_closest( const T& value, DistFunc dist ) const
{
  assert(false && "TODO: Table<T, HashFunc>::find_closest( const T& value, DistFunc dist )");

  static T dummy{};
  return dummy;
}

template <typename T, typename HashFunc>
Vector<T> Table<T, HashFunc>::to_vector() const
{
  assert(false && "TODO: Table<T, HashFunc>::to_vector()");

  static Vector<T> dummy{};
  return dummy;
}
//------------------------------------------------------------------------
// print
//------------------------------------------------------------------------

template <typename T, typename HashFunc>
void Table<T, HashFunc>::print() const
{
  assert(false && "TODO: Table<T, HashFunc>::print()");
}
