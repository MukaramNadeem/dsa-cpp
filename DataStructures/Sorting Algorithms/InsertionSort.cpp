#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> arr = {2,7,3,6,1,9};
    int size = 6;
    for(int i=0;i<size;i++){
        int min_index = i;
        int min_value=arr[i];
        for(int j = i+1; j<size ;j++){
           if(arr[i]>arr[j]){
            min_index = j;
            min_value = arr[j];
           }
        }
        arr[min_index] = arr[i];
        arr[i] = min_value;
    }

    for(int i =0 ; i<size;i++){
        cout<<arr[i]<<' ';
    }

    return 0;
}