#include <iostream>
#include <vector>
using namespace std;

// helper function to buid  MAX heap.
void heapify_max_heap(vector <int> &array, int size, int root) {

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
  if (largest != root){
    // array[root] , array[largest] = array[largest] , array[root];
    int temp = array[root];
    array[root] = array[largest];
    array[largest] = temp;
    // Shift up function that heapify the other elements of heap-tress present above.
    heapify_max_heap(array, size, largest); // recursion!!!
  }
}

// helper function to buid  MIN heap.
void heapify_min_heap(vector <int> &array, int size, int root) {

  // to calculate the left and right we have.
  int l = 2 * root + 1;
  int r = 2 * root + 2;

  // let the smallest as root at the start.
  int smallest = root;

  // update the smallest accordingly.
  // if left < smallest then smallest = left.
  if (l < size && array[l] < array[smallest]) {
    smallest = l;
  }
  // if right < smallest then smallest = right.
  if (r < size && array[r] < array[smallest]) {
    smallest = r;
  }
  // if smallest is not the root then heapify it.
  if (smallest != root) {
    // array[root] , array[smallest] = array[smallest] , array[root];
    int temp = array[root];
    array[root] = array[smallest];
    array[smallest] = temp;
    // Shift up function that heapify the other elements of heap-tress present above.
    heapify_min_heap(array, size, smallest); // recursion!!!
  }
}

// MAX Heap build fuction : It will use the `Shift UP` approach as we are using the reversed loop.
void build_max_heap(vector <int> &array){
  int size = array.size();
  //reversed loop for shift up.
  for (int i = size - 1; i >= 0; i--) {
    heapify_max_heap(array, size, i);//index is being passed : `i`
  }
}

// MIN Heap build fuction : It will use the `Shift UP` approach as we are using the reversed loop.
void build_min_heap(vector <int> &array){
  int size = array.size();
  //reversed loop for shift up.
  for (int i = size - 1; i >= 0; i--) {
    heapify_min_heap(array, size, i);//index is being passed : `i`
  }
}


//deletion function for max heap : It will use the `Shift Down` approach, starting from index 0.
void delete_max(vector <int> &heap){
  if(heap.empty()) return;
  //swap last element with root
  heap[0] = heap.back();
  //remove last element
  heap.pop_back();
  //passing 0 as root 
  heapify_max_heap(heap,heap.size(),0);
}
//deletion function for min heap : It will use the `Shift Down` approach, starting from index 0.
void delete_min(vector <int> &heap){
  if (heap.empty()) return;
  //swap last element with root
  heap[0] = heap.back();
  //remove last element
  heap.pop_back();
  //passing 0 as root.
  heapify_min_heap(heap,heap.size(),0);
}

//print heap function
void print_heap(vector <int> array){
  for(int i = 0;i<array.size();i++){
    cout<<array[i]<<"   ";
  }
  cout<<endl;
}

int main(){

  vector <int> heap;
  //lets take input for the insertion of elements into the MAX heap and print the heapify step by step.
  cout<<"How many elements do you want to insert into the MAX Heap : ";
  int noOfElements;
  cin>>noOfElements;
  for(int i = 0;i<noOfElements;i++){
    //taking input
    cout<<"Enter element to insert : ";  
    int x; cin>>x;
    //add that element to heap vector at end.
    heap.push_back(x);
    
    build_max_heap(heap);
    
    print_heap(heap);
  }
  
  cout<<endl<<"--------------------------------------"<<endl;

  //lets take input for the insertion of elements into the MIN heap and print the heapify step by step.
  vector <int> heap2;
  cout<<"How many elements do you want to insert into the MIN Heap : ";
  int noOfElements2;
  cin>>noOfElements2;
  for(int i = 0;i<noOfElements2;i++){
    //taking input
    cout<<"Enter element to insert : ";  
    int x;
    cin>>x;
    //add that element to heap vector at end.
    heap2.push_back(x);
    
    build_min_heap(heap2);
    print_heap(heap2);
  }

  cout<<endl;
  //lets delete the elements from both the min and the max heap and simulate it.
  cout<<"Simulation of deletion of elements from the MAX heap"<<endl;
  for(int i =0 ; i < noOfElements;i++){
    delete_max(heap);
    print_heap(heap);
  }

  cout<<endl;
  cout<<"Simulation of deletion of elements from the MIN heap"<<endl;
  for(int i = 0 ; i < noOfElements2;i++){
    delete_min(heap2);
    print_heap(heap2);
  }
  return 0;
}