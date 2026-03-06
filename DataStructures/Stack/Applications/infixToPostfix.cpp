#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
#define Size 50 

struct Stack{

    int top =-1;
    char stack[Size]={};


    char pop(){
        if(top == -1 ){
            throw invalid_argument("Underflow");
        }
        else{
            char temp = stack[top];
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
            throw invalid_argument("Overflow");
        }
    }

    //helper function to compare operators 
    int _priority(char c){
        if(c == '^'){
            return 3;
        }
        else if(c == '*' || c == '/' || c == '%'){
            return 2;
        }
        else if (c == '+' || c == '-') {
            return 1;
        }
        else{
            return 0; //for brackets...They must have lowest priority so they will not be compared.
        }
    }

    //print each loop...
    void _print(string postfix){
        cout<<"_______________"<<endl;
        cout<<"postfix -> "<<postfix<<endl;
        cout<<top<<endl;
        for(int i = 0; i< Size; i++){
            cout<<stack[i];
        }
        cout<<endl;
    }

    string infixToPostfix(string input){
        string postfix;
        //loop...
        for(int i = 0 ; i < input.length() ; i++ ){

            // if its an opening bracket...
            if(input[i]=='('  ||  input[i] ==  '[' || input[i] == '{'){
                push(input[i]);
            }

            // if closing bracket...
            if(input[i]==')'  ||  input[i] ==  ']' || input[i] == '}'){
                
                for( int  j = 0 ; j < Size ; j++){
                    if(stack[top]=='('|| stack[top]=='{'|| stack[top]=='['){
                        pop();
                        break;
                    }
                    else{
                        postfix+=pop();
                    }
                }

                /*
                while(top != -1 && stack[top] != '(' && stack[top] != '{' && stack[top] != '['){
                    postfix += pop();
                }
                pop();
                */
            }

            // if its an operand...
            if(input[i]!='('  &&  input[i] != '[' && input[i] != '{' && input[i] != '+' && input[i] != '-' && input[i] !='*' && input[i] !='/' && input[i] !='%' && input[i] !='^' && input[i] !=')' && input[i] !='}' && input[i] !=']' ){
                postfix+= input[i];
            }

            // if its operator...
            if(input[i] == '+' || input[i] == '-' || input[i] =='*' || input[i] =='/' || input[i] =='%' || input[i] =='^'){
                //first check if stack is empty...
                if (top == -1){
                    push(input[i]);
                }
                // if stack is not empty...
                else{
                    int inputCharPriority = _priority(input[i]);
                    while (top != -1){
                        int stackTopPriority = _priority(stack[top]);
                        // pop when lower priority OR equal priority and not exponent
                        if (inputCharPriority < stackTopPriority ||(inputCharPriority == stackTopPriority && input[i] != '^')){
                            postfix += pop();
                        }
                        else{
                            break;
                        }
                    }
                    push(input[i]);
                }

                /*
                //its checking 1 , (2 , (3,4)) conditions here
                while(top != -1 && (_priority(input[i]) < _priority(stack[top]) || (_priority(input[i]) == _priority(stack[top]) && input[i] != '^'))){ 
                    postfix += pop();
                }
                push(input[i]);
                */
            }

            _print(postfix);
        }


        //at the end(of loop) if stack is not empty...pop all values and add to postfix.
        if(top!=-1){
            while(top>-1){
                postfix += pop();
            }
        }
        return postfix;
    }
};

int main(){
    Stack s1;
    
    // cout<<s1.infixToPostfix("A+B*C/d-F+A^E");

    cout<<s1.infixToPostfix("A-(B+C/D-(E+F*G)-H)");
    
    // cout<<s1.infixToPostfix("1 * 2 - 3 / 4 + 5 * 6 - 7 * 8 + 9 / 10");

    
    // cout<<s1.infixToPostfix("10 + 3 * 5 / (16 - 4)");
    
    return 0;

}