#include <iostream>
using namespace std;

#define Size 8

void quick_sort(int array[], int _start, int _end) {
    // base case: 0 or 1 element
    if (_start >= _end) {
        return;
    }
    //recursive case.
    int pivot = array[_start];
    int down = _start;
    int up = _end;

    while (down < up) {
        while (down < up && array[up] >= pivot) {
            up--;
        }
        while (down < up && array[down] <= pivot) {
            down++;
        }
        if (down < up) {
            int temp = array[down];
            array[down] = array[up];
            array[up] = temp;
        }
    }

    array[_start] = array[down];
    array[down] = pivot;

    quick_sort(array, _start, down - 1);
    quick_sort(array, down + 1, _end);
}

int main() {
    int arr[Size] = {4, 5, 1, 3, 2, 7, 8, 0};
    quick_sort(arr, 0, Size - 1);

    for (int i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
