#include <iostream>
using namespace std;

void merge_sort(int array[],int size){
    if(size<=1){
        return;
    }
    int mid = size/2;
    merge_sort(array,mid);
    
}



int main(){
    int arr[8] = {4,5,1,3,2,7,8,0};
    merge_sort(arr,8);
    for(int i : arr){
        cout<<arr[i] <<" "<<endl; 
    }
    return 0;
}