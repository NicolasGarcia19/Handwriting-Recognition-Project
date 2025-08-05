//========================================================================
// Tree.inl
//========================================================================
// Implementation of Tree.

#include "Vector.h"
#include "ece2400-stdlib.h"
#include <cassert>
#include <iostream>



//------------------------------------------------------------------------
// Tree<T,CmpFunc> Constructor
//------------------------------------------------------------------------

template <typename T, typename CmpFunc>
Tree<T, CmpFunc>::Tree( int K, CmpFunc cmp ) : m_root(nullptr), m_size(0), m_k(K), m_cmp(cmp) {}

//------------------------------------------------------------------------
// Tree<T,CmpFunc> Destructor
//------------------------------------------------------------------------

template <typename T, typename CmpFunc>
Tree<T, CmpFunc>::~Tree()
{
  delete_helper(m_root);
}

// destructor helper function
template <typename T, typename CmpFunc>
void Tree<T, CmpFunc>::delete_helper(Node* node) {
  if (node == nullptr) {
    return;
  }
  delete_helper(node->m_left);
  delete_helper(node->m_right);
  delete node;
}
//------------------------------------------------------------------------
// Tree<T,CmpFunc> Copy Constructor
//------------------------------------------------------------------------

template <typename T, typename CmpFunc>
Tree<T, CmpFunc>::Tree( const Tree& tree ) : m_k(tree.m_k), m_cmp(tree.m_cmp), m_size(tree.m_size)
{
  m_root = copy_helper(tree.m_root);
}

// copy constructor helper function
template <typename T, typename CmpFunc>
typename Tree<T, CmpFunc>:: Node* Tree<T, CmpFunc>:: copy_helper(const Node* node) {
  if (node == nullptr) {
    return nullptr;
  }

  Node* new_node = new Node(node->m_value);
  new_node->m_left = copy_helper(node->m_left);
  new_node->m_right = copy_helper(node->m_right);
  return new_node;
}
//------------------------------------------------------------------------
// Tree<T,CmpFunc>::size
//------------------------------------------------------------------------

template <typename T, typename CmpFunc>
int Tree<T, CmpFunc>::size() const
{
  return m_size;
}

//------------------------------------------------------------------------
// Tree<T,CmpFunc>::add
//------------------------------------------------------------------------

template <typename T, typename CmpFunc>
void Tree<T, CmpFunc>::add( const T& value )
{
  if (m_root == nullptr) {
    m_root = new Node(value);
    m_size++;
  }
  else {
    add_helper(m_root,value);
  }
  
}

// add helper function
template <typename T, typename CmpFunc>
void Tree<T, CmpFunc>::add_helper(Node*& node, const T& value) {
  if (node == nullptr) {
    node = new Node(value);
    m_size++;
    return;
  }

  if (m_cmp(value,node->m_value)) {
    add_helper(node->m_left, value);
  }
  else if (m_cmp(node->m_value, value)) {
    add_helper(node->m_right,value);
  }
  
}
//------------------------------------------------------------------------
// Tree<T,CmpFunc>::contains
//------------------------------------------------------------------------

template <typename T, typename CmpFunc>
bool Tree<T, CmpFunc>::contains( const T& value ) const
{
  return contains_helper(m_root, value);
}

// contains helper function
template <typename T, typename CmpFunc>
bool Tree<T, CmpFunc>::contains_helper(const Node* node, const T& value) const {
  if (node == nullptr) {
    return false;
  }

  if (m_cmp(value, node->m_value)) {
    return contains_helper(node->m_left, value);
  }
  else if (m_cmp(node->m_value, value)) {
    return contains_helper(node->m_right, value);
  }
  else {
    return true;
  }
}

//------------------------------------------------------------------------
// Tree<T,CmpFunc>::find_closest
//------------------------------------------------------------------------

template <typename T, typename CmpFunc>
template <typename DistFunc>
T Tree<T, CmpFunc>::find_closest( const T& value, DistFunc dist ) const
{
  if (m_root == nullptr) {
    printf("root is nullptr");
    throw ece2400::OutOfRange("No values in the tree to search through.");
  }
  int tot_levels = ece2400::log2(m_size);
  int k_levels = ece2400::log2(m_k);
  int bin_levels = tot_levels - k_levels;
  if (bin_levels < 0) {
    bin_levels = 0;
  }

  Node* start = binary_helper(m_root,value, bin_levels);

  if (start == nullptr) {
    printf("binary_helper returned nullptr!\n");
  }

  Vector<T> vec;
  to_vector_helper(start,vec);
  return vec.find_closest_linear(value, dist);
  
}

// find_closest helper
template <typename T, typename CmpFunc>
typename Tree<T, CmpFunc>:: Node* Tree<T,CmpFunc>::binary_helper(Node* node, const T& value, int levels) const {
  if (node == nullptr || levels == 0) {
    return node;
  }

  if (m_cmp(value, node->m_value)) {
    if (node->m_left == nullptr) {
      return node;
    }
    else {
      return binary_helper(node->m_left, value, levels - 1);
    }
    
  }
  else{
    if (node->m_right == nullptr) {
      return node;
    }
    else {
      return binary_helper(node->m_right, value, levels - 1);
    }
  }
}



//------------------------------------------------------------------------
// Tree<T,CmpFunc>::to_vector
//------------------------------------------------------------------------

template <typename T, typename CmpFunc>
Vector<T> Tree<T, CmpFunc>::to_vector() const
{
  Vector<T> vec;
  to_vector_helper(m_root,vec);
  return vec;
}

// to_vector helper function
template <typename T, typename CmpFunc>
void Tree<T,CmpFunc>::to_vector_helper(Node* node, Vector<T>& vec) const{
  if (node == nullptr) {
    return;
  }

  to_vector_helper(node->m_left, vec);
  vec.push_back(node->m_value);
  to_vector_helper(node->m_right, vec);
}

//------------------------------------------------------------------------
// Tree<T,CmpFunc>::print
//------------------------------------------------------------------------

template <typename T, typename CmpFunc>
void Tree<T, CmpFunc>::print() const
{
  print_helper(m_root,0);
}

template <typename T, typename CmpFunc>
void Tree<T, CmpFunc>::print_helper(Node* node, int indent) const
{
  if (node == nullptr) {
    return;
  }
  if (node->m_right) {
    print_helper(node->m_right, indent + 4);
  }

  for (int i = 0; i < indent; ++i) {
    std::cout << ' ';
  }
  std::cout << node->m_value << "\n";

  if (node->m_left) {
    print_helper(node->m_left, indent + 4);
  }
}

//------------------------------------------------------------------------
// Tree<T,CmpFunc>::operator=
//------------------------------------------------------------------------

template <typename T, typename CmpFunc>
Tree<T, CmpFunc>& Tree<T, CmpFunc>::operator=( const Tree<T, CmpFunc>& tree )
{
  if (this == &tree) {
    return *this;
  }

  delete_helper(m_root);

  m_k = tree.m_k;
  m_cmp = tree.m_cmp;
  m_size = tree.m_size;
  m_root = copy_helper(tree.m_root);

  return *this;
}
