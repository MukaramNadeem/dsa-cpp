#include <iostream>
using namespace std;


void transpose(int matrix[][3]){
    int transpose[3][2] = {0};
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            transpose[j][i] = matrix[i][j]; 
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int matrix1[2][3]={{1,2,3},{4,5,6}};
    int matrix2[2][3]={{1,2,3},{4,5,6}};
    transpose(matrix1);


    
    return 0;
}
