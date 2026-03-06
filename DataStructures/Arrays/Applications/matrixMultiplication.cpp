#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    const int R1 = 2; 
    const int C1 = 3;
    const int R2 = 3; 
    const int C2 = 2; 

    
    int A[R1][C1] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int B[R2][C2] = {
        {9, 8},
        {6, 5},
        {3, 2}
    };

    
    int C[R1][C2] = {0};

    for(int i = 0; i < R1; i++){
        for(int j = 0; j < C2; j++){
            for(int k = 0; k < C1; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }




    // for (int x = 0; x < R1 * C2; x++) {

    //     int i = x / C2; 
    //     int j = x % C2; 
    //     cout<<"============"<<endl;
    //     cout<<i<<"  "<<j<<endl;
    //     for (int k = 0; k < C1; k++) {
    //         C[i][j] += A[i][k] * B[k][j];
    //     }
    // }




    
    cout << "Result Matrix:" << endl;
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}