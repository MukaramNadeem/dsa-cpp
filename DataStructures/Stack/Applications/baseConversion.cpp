#include <iostream>
using namespace std;
#define Size 20

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



    void dec_to_bin(int dec){
        while(dec>0){
            int remainder = dec%2;
            push(remainder);
            dec = dec/2;
        }
        while(top!=-1){
            cout<<pop();
        }
    }
};








int main(){

    Stack s1;
    s1.dec_to_bin(19);
    
    return 0;
}