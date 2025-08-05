//========================================================================
// Tree.h
//========================================================================
// Declarations for generic tree.

#ifndef TREE_H
#define TREE_H

#include <cstddef>

template <typename T> class Vector;

template <typename T, typename CmpFunc> class Tree {
public:
  Tree(int K, CmpFunc cmp);
  ~Tree();

  // Copy constructor
  Tree(const Tree<T, CmpFunc> &tree);

  // Methods
  int size() const;
  void add(const T &value);
  bool contains(const T &value) const;

  template <typename DistFunc>
  T find_closest(const T &value, DistFunc dist) const;

  Vector<T> to_vector() const;

  void print() const;

  // Operator overloading
  Tree<T, CmpFunc> &operator=(const Tree<T, CmpFunc> &tree);

private:
  struct Node {
    T m_value;
    Node *m_left;
    Node *m_right;

    Node(const T &value) : m_value(value), m_left(nullptr), m_right(nullptr) {}
  };

  Node *m_root;
  int m_size;
  int m_k;
  CmpFunc m_cmp;

  void delete_helper(Node *node);
  Node *copy_helper(const Node *node);
  void add_helper(Node *&node, const T &value);
  bool contains_helper(const Node *node, const T &value) const;
  Node *binary_helper(Node *node, const T &value, int levels) const;
  void print_helper(Node *node, int indent) const;
  void to_vector_helper(Node *node, Vector<T> &vec) const;
};

// Include inline definitions
#include "Tree.inl"

#endif /* TREE_H */
