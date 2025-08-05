# Handwriting Recognition System - Tree Search Implementation

## Overview

A comprehensive handwriting recognition system implemented in C++ that classifies handwritten digits (0-9) from the MNIST database with high accuracy. The project implements a tree-based classification algorithm along with linear and binary search methods, demonstrating advanced data structures and algorithmic optimization techniques.

## Features

### Core Data Structures
- **Generic Vector<T>**: Template-based resizable vector with sorting and search capabilities
- **Image Class**: Represents 28×28 grayscale images with pixel values 0-255
- **Tree<T,CmpFunc>**: Binary search tree supporting approximate nearest neighbor search with hybrid binary/exhaustive search strategy

### Classification Algorithms
1. **Linear Search**: Brute force search through entire training dataset
2. **Binary Search**: Hybrid approach using intensity-based binary search + Euclidean distance linear search
3. **Tree Search**: Advanced binary search tree with partial binary search and exhaustive subtree search for optimal accuracy/speed balance

### Advanced Features
- **Generic Programming**: Template-based implementations supporting any data type
- **Function Objects**: Support for custom comparison and distance functions
- **Memory Management**: Complete implementation of Rule of Three (constructor, destructor, assignment operator)
- **Exception Handling**: Proper error handling with custom exception types
- **GUI Integration**: Python frontend with C++ backend for real-time digit classification

## Technical Implementation

### Algorithms & Data Structures
```cpp
// Generic sorting algorithm
template <typename T, typename CmpFunc>
void sort(T* array, int size, CmpFunc cmp);

// Template vector with advanced search capabilities
template <typename DistFunc>
T find_closest_linear(const T& value, DistFunc dist) const;

template <typename DistFunc, typename CmpFunc>
T find_closest_binary(const T& value, int k, DistFunc dist, CmpFunc cmp) const;
```

### Performance Optimizations
- **Hybrid Tree Search Strategy**: Combines fast binary search traversal with accurate exhaustive search of subtrees
- **Memory Efficient**: Careful dynamic memory management with no memory leaks
- **Algorithmic Complexity**: Optimized tree structure for both training and classification phases
- **Adaptive Search Depth**: Configurable parameter K for balancing speed vs accuracy

### Distance Metrics
- **Euclidean Distance**: Sum of squared differences between pixel values
- **Intensity-based Comparison**: Used for fast approximate matching in tree traversal
- **Hybrid Distance Strategy**: Binary search uses intensity comparison, exhaustive search uses Euclidean distance

## Architecture

### System Components
```
Frontend (Python GUI) ↔ Backend (C++ Engine)
                          ├── Vector<Image> (Training Data)
                          ├── Classification Algorithms
                          │   ├── Linear Search
                          │   ├── Binary Search  
                          │   └── Tree Search (Primary Implementation)
                          └── Image Processing
```

### Class Hierarchy
- **IHandwritingRecSys**: Abstract interface for all recognition systems
- **Concrete Implementations**: HRSLinearSearch, HRSBinarySearch, HRSTreeSearch
- **Template Specializations**: Separate implementations for integers and images

## Performance Analysis

### Complexity Analysis
- **Linear Search**: O(N) training, O(N) classification
- **Binary Search**: O(N log N) training, O(log N + K) classification  
- **Tree Search**: O(N log N) training, O(log N + K) classification with improved memory locality

Where N = training set size, K = exhaustive search parameter

### Accuracy vs Speed Trade-offs
The tree search system allows tuning of the parameter K to balance between:
- **Higher K**: More exhaustive subtree search, higher accuracy, slower classification
- **Lower K**: Faster tree traversal, potentially lower accuracy but better performance
- **Optimal K Selection**: log₂(K) determines the depth of exhaustive search in the tree structure

## Testing Strategy

### Comprehensive Test Suite
- **Unit Tests**: Individual component testing for all data structures
- **Integration Tests**: End-to-end system testing
- **Random Testing**: Automated testing with random inputs
- **Memory Leak Detection**: Valgrind integration for memory safety
- **Code Coverage**: Systematic coverage analysis

### Test Categories
- Directed tests for specific scenarios
- Random tests for edge cases
- Performance benchmarking
- Memory usage validation

## Technical Skills Demonstrated

### C++ Advanced Features
- Template metaprogramming
- Function objects and lambdas
- Operator overloading
- RAII and resource management
- Exception handling
- Object-oriented design principles

### Software Engineering Practices
- Test-driven development
- Memory leak prevention
- Code coverage analysis
- Performance profiling
- Build automation (CMake/CTest)
- Version control integration

### Algorithm Design
- Hybrid tree search algorithms
- Binary search tree implementation with custom comparison functions
- Complexity analysis and optimization
- Data structure selection and implementation

## Dataset

**MNIST Handwritten Digits Database**
- 60,000 training images
- 10,000 test images  
- 28×28 pixel grayscale images
- 10 classes (digits 0-9)
- Pixel values: 0 (white) to 255 (black)

## Build System

The project uses CMake for cross-platform building with automated testing and evaluation scripts for performance analysis and accuracy measurement.

## Results

The system successfully classifies handwritten digits with high accuracy using an advanced tree-based search algorithm. The implementation demonstrates sophisticated understanding of data structures and provides an optimal balance between classification speed and accuracy through the hybrid binary/exhaustive search strategy. The modular design allows for easy comparison between linear, binary, and tree search approaches.
