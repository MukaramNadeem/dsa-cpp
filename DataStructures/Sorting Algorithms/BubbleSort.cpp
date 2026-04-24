#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {10, 6, 4, 7, 2};
    int size = 5;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size-i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++){
        cout << arr[i] << "  ";
    }

    return 0;
}