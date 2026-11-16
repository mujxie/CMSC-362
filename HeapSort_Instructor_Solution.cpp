/*
  Filename   : HeapSort_Instructor_Solution.cpp
  Author     : Jingnan Xie
  Course     : CSCI 362
  Description: Instructor Solution - Zero-Based Binary Min-Heap Sort

  Sort in descending order using an in-place binary min-heap.
  Convention: last is the inclusive last index of the active heap.
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

int parentIndex(int i) {
  return (i - 1) / 2;
}

int leftChildIndex(int i) {
  return 2 * i + 1;
}

int rightChildIndex(int i) {
  return 2 * i + 2;
}

int smallerChildIndex(const std::vector<int>& heap, int i, int last) {
  int left = leftChildIndex(i);
  if (left > last) {
    return -1;
  }
  int right = rightChildIndex(i);
  if (right > last || heap[left] <= heap[right]) {
    return left;
  }
  return right;
}

void heapify(std::vector<int>& heap, int i, int last) {
  int child = smallerChildIndex(heap, i, last);
  if (child == -1 || heap[i] <= heap[child]) {
    return;
  }
  std::swap(heap[i], heap[child]);
  heapify(heap, child, last);
}

void buildHeap(std::vector<int>& heap, int last) {
  if (last <= 0) {
    return;
  }
  for (int i = parentIndex(last); i >= 0; --i) {
    heapify(heap, i, last);
  }
}

bool isMinHeap(const std::vector<int>& heap, int last) {
  for (int i = 0; i <= last; ++i) {
    int left = leftChildIndex(i);
    int right = rightChildIndex(i);
    if (left <= last && heap[left] < heap[i]) {
      return false;
    }
    if (right <= last && heap[right] < heap[i]) {
      return false;
    }
  }
  return true;
}

void heapSort(std::vector<int>& heap, int last) {
  for (int end = last; end > 0; --end) {
    std::swap(heap[0], heap[end]);
    heapify(heap, 0, end - 1);
  }
}

void heapSort(std::vector<int>& numbers) {
  if (numbers.size() < 2) {
    return;
  }
  int last = static_cast<int>(numbers.size()) - 1;
  buildHeap(numbers, last);
  heapSort(numbers, last);
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
