#include <iostream>
using namespace std;
#define Size 5 

struct Stack{

    int top = -1 ;
    int stack[Size]= {0};


    int pop(){
        if(top == -1 ){
            cout<<"Underflow";
            return -1;
        }
        else{
            int temp = stack[top];
            stack[top] = 0;
            top--;
            return temp;
        }
    }

    
    void push(int val){
        if(top < Size-1){
            top++;
            stack[top] = val;
        }
        else{
            cout<<"Overflow";
        }
    }
};

int main(){
    Stack s1;
    s1.push(3);
    s1.push(2);
    s1.push(1);
    s1.push(3);
    s1.push(2);
   
    s1.pop();

    for(int i = 0; i< Size; i++){
        cout<<s1.stack[i];
    }
    s1.push(1);
    cout<<endl;
    cout<<s1.pop();

    return 0;
}
