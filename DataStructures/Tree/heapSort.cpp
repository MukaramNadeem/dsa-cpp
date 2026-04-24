#include <iostream>
#include <vector>
using namespace std;

// helper function to buid  MAX heap.
void heapify_max_heap(vector<int> &array, int size, int root) {

  // to calculate the left and right we have.
  int l = 2 * root + 1;
  int r = 2 * root + 2;

  // let the largest as root at the start.
  int largest = root;

  // update the largest accordingly.
  // if left > largest then largest = left.
  if (l < size && array[l] > array[largest]) {
    largest = l;
  }
  // if right > largest then largest = right.
  if (r < size && array[r] > array[largest]) {
    largest = r;
  }
  // if largest is not the root then heapify it.
  if (largest != root) {
    // array[root] , array[largest] = array[largest] , array[root];
    int temp = array[root];
    array[root] = array[largest];
    array[largest] = temp;
    // Shift up function that heapify the other elements of heap-tress present above.
    heapify_max_heap(array, size, largest); // recursion!!!
  }
}


// MAX Heap build fuction : It will use the `Shift UP` approach as we are using the reversed loop.
void build_max_heap(vector<int> &array) {
  int size = array.size();
  // reversed loop for shift up.
  for (int i = size - 1; i >= 0; i--) {
    heapify_max_heap(array, size, i); // index is being passed : `i`
  }
}


int delete_max(vector<int> &heap) {
  if (heap.empty())
    return 0;
  // swap last element with root
  int max_value = heap[0];
  heap[0] = heap.back();
  // remove last element
  heap.pop_back();
  // passing 0 as root
  heapify_max_heap(heap, heap.size(), 0);
  return max_value;
}


// print heap function
void print_heap(vector<int> array) {
  for (int i = 0; i < array.size(); i++) {
    cout << array[i] << "   ";
  }
  cout << endl;
}

void heap_sort(vector <int> &array){
  build_max_heap(array);
  vector<int> result;
  int size = array.size();
  for(int i = 0; i < size ; i++){
    result.push_back(delete_max(array));
  }
  print_heap(result);
}


int main(){
  vector<int> heap;
  heap = {4, 10, 3, 5, 1};  
  heap_sort(heap);
  return 0;
}
