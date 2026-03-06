#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
#define Size 50 

struct Stack{
    int top = -1;
    int stack[Size] = {};


    int pop(){
        if(top==-1){
            throw invalid_argument("Underflow");
        }
        else{
            int temp = stack[top];
            stack[top] = 0;
            top--;
            return temp;
        }
    }
    void push(int val){
        if(top >= Size -1){
            throw invalid_argument("Overflow");
        }
        else{
            top++;
            stack[top] = val;
        }
    }
    string postfixEvaluation(string input){
        for(int i = 0 ; i < input.length() ; i++ ){
            // if its operand...
            if(input[i]!='('  &&  input[i] != '[' && input[i] != '{' && input[i] != '+' && input[i] != '-' && input[i] !='*' && input[i] !='/' && input[i] !='%' && input[i] !='^' && input[i] !=')' && input[i] !='}' && input[i] !=']' ){
                push(input[i]-'0');
            }
            // if its operator...
            if(input[i] == '+' || input[i] == '-' || input[i] =='*' || input[i] =='/' || input[i] =='%' || input[i] =='^'){
                int op1 = pop();
                int op2 = pop();
                if (input[i]== '^'){
                    int temp = pow(op2,op1);
                    push(temp);
                }
                if (input[i]== '+'){
                   int temp = op2 + op1; 
                   push(temp);
                }
                if (input[i]== '-'){
                   int temp = op2 - op1;
                   push(temp); 
                }
                if (input[i]== '%'){
                   int temp = op2 % op1; 
                   push(temp);
                }
                if (input[i]== '/'){
                   int temp = op2 / op1; 
                   push(temp);
                }
                if (input[i]== '*'){
                   int temp = op2 * op1; 
                   push(temp);
                }
            }
            
        }

            cout<<pop()<<endl;
            return top==-1 ? "True" : "False";
    }
};



int main(){
    Stack s1;
    cout<<s1.postfixEvaluation("623+-382%+*2^3+");

    return 0;
}