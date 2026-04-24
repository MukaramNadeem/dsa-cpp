#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> arr = {1,6,5,4,1};
    for(int i = 0;i<arr.size();i++){
        for(int j = i+1; j<arr.size();j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i<arr.size();i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}
