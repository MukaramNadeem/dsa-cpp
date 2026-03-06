#include <iostream>
using namespace std;
#define Size 20

struct Stack{

    int top = -1 ;
    char stack[Size]= {};


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


    bool isBalanced(string input){
        for(int i = 0 ; i < input.length() ; i ++){
            // if opening
            if(input[i]=='('  ||  input[i] ==  '[' || input[i] == '{'){
                if(input[i] == '('){
                    push(')');
                }
                if(input[i] == '{'){
                    push('}');
                }
                if(input[i] == '['){
                    push(']');
                }

                for(int i = 0; i< Size; i++){
                cout<<stack[i];
                }
            }
            // if closing
            if(input[i]==')'  ||  input[i] ==  ']' || input[i] == '}'){
                if(top==-1){
                    return false;
                }
                else{
                    char c = pop();
                    if(input[i] != c){
                        return false;
                    }
                }
            }
        }
        // at end
        if(top ==-1){
            return true;
        }
        else{
            return false;
        }
        top = -1;
    }
};
int main(){
    Stack s1,s2,s3,s4,s5,s6;

    cout<<s1.isBalanced("((())")<<" not balanced"<<endl;
    cout<<s2.isBalanced("()))")<<" not balanced"<<endl;
    cout<<s3.isBalanced("([)]")<<" not balanced"<<endl;
    cout<<s4.isBalanced("[({}{}{})([])]")<<" balanced"<<endl;
    cout<<s5.isBalanced("{([])}")<<" balanced"<<endl;
    cout<<s6.isBalanced("([{}])")<<" balanced"<<endl;
    
    return 0;

}