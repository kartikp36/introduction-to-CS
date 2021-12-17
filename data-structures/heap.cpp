// Max-Heap implementation in C++

#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

class Heap {
 private:
  vector<int> heap;
  int left(int parent);
  int righeap(int parent);
  int parent(int child);

 public:
  void heapifyUp(vector<int> &heap, int i) {
    int size = heap.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && heap[l] > heap[largest])
      largest = l;
    if (r < size && heap[r] > heap[largest])
      largest = r;

    if (largest != i) {
      swap(&heap[i], &heap[largest]);
      heapifyUp(heap, largest);
    }
  };

  void insert(int newNum) {
    int size = heap.size();
    if (size == 0) {
      heap.push_back(newNum);
    } else {
      heap.push_back(newNum);
      for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyUp(heap, i);
      }
    }
  };

  void deleteNode(int num) {
    int size = heap.size();
    int i;
    bool found = false;
    for (i = 0; i < size; i++) {
      if (num == heap[i]) {
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "Element: " << num << " not found" << endl;
      return;
    }
    swap(&heap[i], &heap[size - 1]);
    heap.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapifyUp(heap, i);
    }
  };

  void displayHeap() {
    for (int i = 0; i < heap.size(); ++i)
      cout << heap[i] << " ";
    cout << "\n";
  };

  int extractMax() {
    if (heap.size() == 0) {
      return -1;
    } else
      return heap.front();
  };

  int size() {
    return heap.size();
  };
};

int Heap::left(int parent) {
  int l = 2 * parent + 1;
  if (l < heap.size())
    return l;
  else
    return -1;
}

int Heap::righeap(int parent) {
  int r = 2 * parent + 2;
  if (r < heap.size())
    return r;
  else
    return -1;
}

int Heap::parent(int child) {
  int p = (child - 1) / 2;
  if (child == 0)
    return -1;
  else
    return p;
}

int main() {
  Heap h;
  h.insert(19);
  h.insert(9);
  h.insert(5);
  h.insert(10);
  h.insert(4);
  h.insert(8);
  h.insert(1);
  cout << "Max-Heap array: ";
  h.displayHeap();
  h.deleteNode(9);
  cout << "After deleting: ";
  h.displayHeap();
}
