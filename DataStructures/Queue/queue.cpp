#include <iostream>
using namespace std;
#include <stdexcept>
#define Size 5

struct Queue{
    int queue[Size] = {0};
    int rear = -1;
    int front = -1;

    void enqueue(int val){
        //Overflow condition
        if(front == 0 && rear == Size-1){
            throw invalid_argument("Overflow");
        }
        //for first element
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            queue[rear] = val;
        }
        //for other elements
        else{
            rear+=1;
            queue[rear] = val;
        }
    }


    int dequeue(){
        //empty
        if(front==-1 && rear==-1){
            throw invalid_argument("Underflow");
        }
        //if queue has only one element then it will become empty(front=rear=-1).
        else if(front==0 && rear==0 || front == rear){
            int val =  queue[front];
            queue[front] = 0;
            front = -1;
            rear = -1;
            return val;
        }
        //for other elements
        else{
            int val = queue[front];
            queue[front] = 0;
            front+=1;
            return val;
        }
    }


    void printQueue(){
        if(front==-1 && rear==-1){
            return;
        }
        for(int i = front ; i <= rear;i++){
            cout<<queue[i]<< "  ";
        }
        cout<<endl;
    }

};




int main(){
    Queue q1;
    q1.enqueue(1);
        q1.printQueue();
        
    q1.dequeue();
        q1.printQueue();
    
    q1.enqueue(2);
        q1.printQueue();
    
    q1.enqueue(3);
        q1.printQueue();
    q1.enqueue(4);
        q1.printQueue();
    
    q1.dequeue();
        q1.printQueue();
    q1.enqueue(5);
        q1.printQueue();
   

    q1.dequeue();
        q1.printQueue();
    q1.dequeue();
        q1.printQueue();
    q1.dequeue();
        q1.printQueue();
   

    return 0;
}