#include <iostream>
using namespace std;
#include <stdexcept>
#define Size 3

struct CircularQueue{
    int queue[Size] = {};
    int rear = -1;
    int front = -1;

    void enqueue(int val){
        //Overflow condition
        if(front == 0 && rear == Size-1 || rear==front-1){  // ` || rear==front-1 ` : extra condition for circular only!!!. 
            throw invalid_argument("Overflow");
        }
        //for first element
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            queue[rear] = val;
        }
        // to mkae it circular!!!
        else if(rear == Size-1 && front!=0){
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
        //to make it circular!!!
        else if(front == Size-1){
            int val = queue[front];
            queue[front] = 0;
            front = 0;
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

    void printQueue() {
        
        if (front == -1 && rear == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << "  ";
            }
        }

        else {
            for (int i = front; i < Size; i++) {
                cout << queue[i] << "  ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << queue[i] << "  ";
            }
        }
        cout << endl;
    }
};




int main(){
    CircularQueue q1;
    q1.enqueue(1);
        q1.printQueue();
    q1.enqueue(2);
        q1.printQueue();
    q1.enqueue(3);
        q1.printQueue();
    // q1.enqueue(4);
    // q1.printQueue();
    q1.dequeue();
        q1.printQueue();
    
    q1.enqueue(4);
        q1.printQueue();
    q1.dequeue();
        q1.printQueue();
    q1.dequeue();
        q1.printQueue();
    q1.dequeue();
        q1.printQueue();
   
    return 0;
}