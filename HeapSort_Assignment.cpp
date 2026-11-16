/*
  Filename   : HeapSort_Assignment.cpp
  Author     : Jingnan Xie
  Course     : CSCI 362
  Description: Heap Sort Using a Zero-Based Binary Min-Heap

  ASSIGNMENT
  ----------
  Complete the nine functions marked TODO below. Replace each placeholder
  throw statement with your own code.

  Requirements:
  1. Use the vector itself as a binary min-heap. Every element is used:
     valid indices are 0, 1, ..., n-1. There is NO unused element at index 0.
  2. Sort in non-ascending (descending) order, including duplicate values.
  3. Sort in place: do not create a second vector to hold the heap or result.
  4. Implement heapify recursively. Build the heap from the bottom up.
  5. Do not use std::sort, std::make_heap, std::priority_queue, or similar
     library functions that implement the required heap/sorting operations.
     You may use std::swap.
  6. Do not change the function names, parameters, or test code in main().

  In a short comment at the end of your submission, also answer:
  A. Why does a MIN-heap produce descending order in this heap sort?
  B. What are the worst-case time complexities of heapify, buildHeap,
     and the complete heapSort?
  C. Why must heapify ignore the sorted portion of the vector?

  Convention: 'last' is the INCLUSIVE last index of the active heap.
  Thus, the active heap is vector[0 ... last], and an empty heap has last=-1.
  In heap sort, elements after 'last' form the already sorted portion.

  The helper functions are deliberately left for you to implement.
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// Return the index of the parent of node i.
// Precondition: i > 0.
int parentIndex(int i) {
  // TODO 1: Derive the parent-index formula for ZERO-BASED indexing.
  throw std::logic_error("TODO 1: parentIndex");
}

// Return the index of the left child of node i.
int leftChildIndex(int i) {
  // TODO 2: Derive the left-child formula for ZERO-BASED indexing.
  throw std::logic_error("TODO 2: leftChildIndex");
}

// Return the index of the right child of node i.
int rightChildIndex(int i) {
  // TODO 3: Derive the right-child formula for ZERO-BASED indexing.
  throw std::logic_error("TODO 3: rightChildIndex");
}

// Return the index of the smaller child of node i in heap[0 ... last].
// If i has no child in the active heap, return -1.
// If both children have equal values, return the LEFT child's index.
// Precondition: i is a valid index in the active heap.
int smallerChildIndex(const std::vector<int>& heap, int i, int last) {
  // TODO 4: Handle a leaf, a node with only a left child, and a node
  //         with two children. Never access an index larger than last.
  throw std::logic_error("TODO 4: smallerChildIndex");
}

// Restore the min-heap property at node i, assuming its child subtrees
// already satisfy the min-heap property.
// Only heap[0 ... last] belongs to the active heap.
void heapify(std::vector<int>& heap, int i, int last) {
  // TODO 5: Implement RECURSIVE heapify using smallerChildIndex().
  //         Stop if i has no child or heap[i] is no larger than its
  //         smaller child. Otherwise swap and continue recursively.
  throw std::logic_error("TODO 5: heapify");
}

// Convert an arbitrary vector prefix heap[0 ... last] into a min-heap.
// Do this in place, beginning with the last internal node and moving
// backward to the root. An empty or one-element heap needs no work.
void buildHeap(std::vector<int>& heap, int last) {
  // TODO 6: Use parentIndex() to find the last internal node.
  //         Call heapify() on each internal node in the correct order.
  throw std::logic_error("TODO 6: buildHeap");
}

// Return true if heap[0 ... last] satisfies the min-heap property.
// Return true when last == -1 (the active heap is empty).
// Do not rearrange the vector.
bool isMinHeap(const std::vector<int>& heap, int last) {
  // TODO 7: Check every parent-child relationship inside the active heap.
  //         Use zero-based child indices. A value equal to its parent
  //         does NOT violate the min-heap property.
  throw std::logic_error("TODO 7: isMinHeap");
}

// HEAPSORT HELPER: heap[0 ... last] is ALREADY a min-heap.
// Sort that prefix into non-ascending order IN PLACE.
void heapSort(std::vector<int>& heap, int last) {
  // TODO 8: Repeatedly:
  //   - swap the minimum (root at index 0) with the last heap element;
  //   - shrink the active heap by one element;
  //   - restore the min-heap property at the root.
  // Do not rebuild the whole heap after each swap.
  throw std::logic_error("TODO 8: heapSort helper");
}

// MAIN HEAPSORT FUNCTION: sort every element in non-ascending order.
// The input may be empty and may contain negative or repeated values.
void heapSort(std::vector<int>& numbers) {
  // TODO 9: Handle small inputs, build a min-heap, then call the
  //         two-argument heapSort() helper. No extra array is needed.
  throw std::logic_error("TODO 9: heapSort");
}

// ------------------- Provided tests: DO NOT EDIT -------------------

void testHeapProperty(const std::string& name, std::vector<int> values,
                      bool expected) {
  try {
    bool actual = isMinHeap(values, static_cast<int>(values.size()) - 1);
    std::cout << name << ": " << (actual == expected ? "PASS" : "FAIL")
              << '\n';
  } catch (const std::logic_error& e) {
    std::cout << name << ": NOT IMPLEMENTED (" << e.what() << ")\n";
  }
}

void testSort(const std::string& name, std::vector<int> values,
              const std::vector<int>& expected) {
  try {
    std::vector<int> built = values;
    if (!built.empty()) {
      buildHeap(built, static_cast<int>(built.size()) - 1);
    }
    bool heapCorrect = isMinHeap(built, static_cast<int>(built.size()) - 1);

    heapSort(values);
    bool sortCorrect = (values == expected);
    std::cout << name << ": "
              << (heapCorrect && sortCorrect ? "PASS" : "FAIL") << '\n';
  } catch (const std::logic_error& e) {
    std::cout << name << ": NOT IMPLEMENTED (" << e.what() << ")\n";
  }
}

int main() {
  testHeapProperty("Min-heap property: valid heap",
                   {1, 4, 2, 8, 5, 7, 3}, true);
  testHeapProperty("Min-heap property: invalid heap",
                   {1, 5, 2, 3}, false);
  testHeapProperty("Min-heap property: equal values",
                   {2, 2, 2, 2}, true);
  testHeapProperty("Min-heap property: empty heap", {}, true);

  testSort("Original mixed input",
           {20, -13, 29, 3, 8, 17, 13, 10, 26, 0, -11, -5, 7, 19,
            8, -11, 36, -5, 49, 13},
           {49, 36, 29, 26, 20, 19, 17, 13, 13, 10, 8, 8, 7, 3,
            0, -5, -5, -11, -11, -13});
  testSort("Empty input", {}, {});
  testSort("One element", {42}, {42});
  testSort("Two elements", {3, 9}, {9, 3});
  testSort("Duplicates", {5, 1, 5, 3, 1}, {5, 5, 3, 1, 1});
  testSort("Ascending input", {1, 2, 3, 4, 5}, {5, 4, 3, 2, 1});
  testSort("Descending input", {9, 7, 5, 3, 1}, {9, 7, 5, 3, 1});
  testSort("Negative values", {-8, -2, -9, -1}, {-1, -2, -8, -9});
  testSort("All equal", {4, 4, 4, 4}, {4, 4, 4, 4});

  return 0;
}
